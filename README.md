Rapid prototyping of domain specific languages via OMeta/JS.

See http://amtal.github.com/2012/04/28/source-to-source-transforms-with-ometa

Resutls:
--------

~160 lines of OMeta/JS code generating ~1500 lines of C, based on some existing public notes.

Code generation: 
----------------

```javascript
c2s = """
... see notes.c2s.txt
"""

s2c = """
... see notes.s2c.txt
"""

gen = function(t) {
    console.log('\n\nnotes:\n', defines)
    console.log(PPrint.matchAll(t,"packets"))

    console.log(PPrint.matchAll(t,"packets"))
    console.log('\n\npackets_c2s.h:\n', defines)
    console.log(SizeLUT.matchAll(t,"packets"))
    console.log(Structs.matchAll(t,"packets"))
    console.log(Encode.matchAll(t,"packets"))
}

gen(Parser.matchAll(c2s, "packets"))
gen(Parser.matchAll(s2c, "packets"))
```

Parsers and printers:
---------------------

```javascript
ometa CleanParser {
  // literals
  number = digit+:ds -> parseInt(ds.join('')),
  hexDigit = char:x {'0123456789abcdef'.indexOf(x.toLowerCase())}:v ?(v >= 0) -> v,
  hexLit = hexLit:n hexDigit:d -> (n*16+d)
         | hexDigit,
  sp = (~'\n' space)*,
  // label parsing is extremely hacky due to dealing with pretty freestyle natural-language
  // hacky top-level labels
  topLabelFst = letter | '-' | '(' | '0x',
  topLabelOk = topLabelFst | char:c ? ("?)/.#,\'|=".indexOf(c)!=-1) | digit,
  topLabelRst = topLabelOk // here there be hacks:
           | ' ' topLabelOk,  // allow spaces and numbers, but tabs end
  topLabel = <topLabelFst topLabelRst*>,
  // hacky field labels
  labelFst = topLabelFst | '<',
  labelOk = topLabelOk | '<' | '>',
  labelRst = labelOk 
           | ' ' labelOk 
           | '[' digit+ ']', // for 'char[123]' in label contents 
  label = <labelFst labelRst*>,
  // moving on to proper structure
  length = "BYTES[" number:d "]" -> ['BYTES',d] // less frequent variant
         | "WORD" | "DWORD" | "BUFFER" | "BYTE" | "CSTRING",
  // Ideally every packet field has a name - but sometimes they aren't defined :(
  field = sp '[' length:l sp label*:name ']' -> [l,name.concat()[0]]
        | sp hexLit:h -> ['const',h],
  size = number | "?",
  packet = hexLit:id spaces size:s ' '* topLabel:desc sp field*:fs sp label*:desc2 
            -> ['p',id,s,desc2.length==0?desc:desc+desc2,fs]
         | hexLit:id sp fromTo('-','\n'):msg -> ['p',id,'undefined',msg.replace(/[-\n(  )]/g,'')],
  header = "Number" "Size" "Effect:" "Usage:" '\n' '-'+ '\n',
  packets = header* (spaces packet)*:ps -> ps
}

ometa Parser <: CleanParser {
  length = "NULLSTRING[" number:d "]" -> ['BYTES',d]
         | ^length
         | "VOID"     -> 'BUFFER'
         | "VARIABLE" -> 'BUFFER'     // varlength warden packet
         | "*char"    -> 'CSTRING'    // varlength chat messages
         | "Char"     -> 'CSTRING'    // definition typo like [Char Name[15]]
         | "Object"   -> 'DWORD'      // typo in `4c   5   Transmorgify   4c [Object ID]`
         // SaveChar defines `[dwUnk] [dwUnk] [char[252] SaveFile]`
         // This is double-annoying, since there's no description to parse or base field names off of.
         | "dwUnk"    -> 'DWORD'
         | "char[" number:d "]" -> ['BYTES',d],
  field = ^field
        | "<Research Incomplete>" -> ['BUFFER','ResearchIncomplete']
        | sp '?' sp -> ['BUFFER','ResearchIncomplete']
        | sp '*' sp -> ['BUFFER','ResearchIncomplete']
        | sp '-'+ sp -> ['BUFFER','ResearchIncomplete'],
  size = ^size       
       | "[Varies]" -> '*' // Why is this different from `sp '[Varies]' sp`?
       | "*" -> '*'  // * means dynamic size, need to inspect packet to determine
       | "?" -> '?', // ? means unknown size
  packet = ^packet
         | hexLit:id sp (~'\n' anything)*:msg -> ['p',id,'undefined',msg.join('').replace(/[-\n(  )]/g,'')]
}


ometa PPrint {
  packets = packet*:ps -> ps.join('\n'),
  packet = ['p' id:id :size :name [field*:fs]] -> (id+' '+size+'\t'+name+' \t'+fs.join(' '))
         | ['p' id:id 'undefined' :desc]      -> (id+' ?\t'+desc),
  id = :h -> h.toString(16),
  field = ['const' id:n] -> n
        | [['BYTES' :len] :name] -> ('BYTES['+len+'] '+name)
        | :s -> ('['+s.join(' ')+']')
}


ometa C {
  // lazy C identifier validity - doesn't do 1st letter or reserved words
  valid = :s -> s.replace(/[^A-Za-z_0-9]/g, '_').toLowerCase(),
  // chops a valid identifier off a string, and sticks any tail into a comment
  ident = [idLabel:l ' '* anything*:c] -> [l.toLowerCase(), c.length==0?'':'\t// '+c.join('')],
  idLabel = idWord:x idWord:y   -> (x+'_'+y)
          | idWord:x            -> x,
  idWord = ' '* (letter | '_')+:w -> w.join('')
}

field = function(type,txt) {
  var name = txt[0]
  if (Structs.sym[name]===undefined) {
     Structs.sym[name]=0
  } else {
     Structs.sym[name]++
     name += Structs.sym[name]
  }
  return ('\t'+type+'\t'+name+';'+txt[1])
}

ometa Structs <: C {
  // structure
  packets = packet*:ps -> ps.join(''),
  packet = ['p' :id :size valid:name [field*:fs]]   {'/*0x'+id.toString(16)+'*/ '}:comment
                                                    {' {\n' + fs.join('\n') + '\n}\n'}:body
                                                 -> {Structs.sym={}; 'struct '+comment+name+body}
         | ['p' :id 'undefined' :desc]      -> ('// 0x'+id.toString(16)+' '+desc+'\n'),
  field = ['const' ksym:k]                -> field('u8',k)
        | ['BYTE'       remap('u8'):n]  -> n
        | ['WORD'       remap('u16'):n]  -> n
        | ['DWORD'      remap('u32'):n] -> n
        | ['BUFFER'     remap('u8*'):n] -> n
        | ['CSTRING'    remap('char*'):n] -> n
        | [['BYTES' :s] ident:n] -> {n[0]+='['+s+']'; field('u8',n)}
        | :n -> ('\t// UNHANDLED GENERATOR: '+n),
  // I used remap to play with arguments, but really it loses clarity by muddling 
  // the split between input and output. Doubt it's worth the reduction in repetition.
  remap :type = ident:txt -> field(type,txt),
  ksym = :msg -> ['k', '\t// '+msg]
};
Structs.sym={}; // duplicate symbol counter

defines = """
#define u8 unsigned char;
#define u16 unsigned short;
#define u32 unsigned int;
"""

ometa Encode <: C {
  packets = packet*:ps -> ps.join(''),
  packet = ['p' :id :size valid:name [field*:fs]] -> 
                       ('const struct '+name+' '+name.toUpperCase()+' = {'+fs.join(',')+'};\n')
         | ['p' :id 'undefined' :desc]        -> '',
  field = ['const' hex:n] -> n
        | [['BYTES' :len] :name] -> {var s='{'; for (var i=0;i<len;i++) {s+=(i==len-1)?'0':'0,';}; s+='}'}
        | :s -> '0',
  hex = :h -> ('0x'+h.toString(16))
}

ometa SizeLUT {
  packets = packet* -> {
     var s='const int size_lut[256] = {';
     for(var i=0;i<256;i++){
         s+=SizeLUT.lut[i]===undefined?'-1':SizeLUT.lut[i];
         if(i!=255) s+=',';
     }; 
     s+='};\n'
  },
  packet = ['p' :id size:s :name :fields] -> {SizeLUT.lut[id]=s}
         | ['p' :id 'undefined' :desc],
  size = '?' -> '0'
       | '*' -> '-1'
       | number
}
SizeLUT.lut = {}

defines += """
#define SIZE_UNKNOWN 0
#define SIZE_DYNAMIC -1
"""
```

