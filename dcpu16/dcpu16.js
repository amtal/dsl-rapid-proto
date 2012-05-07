// Slight modifications made:
//   s/'Basic opcodes'/'Basic opcodes:'/
spec = """DCPU-16 Specification
Copyright 1985 Mojang
Version 1.1



=== SUMMARY ====================================================================

* 16 bit words
* 0x10000 words of ram
* 8 registers (A, B, C, X, Y, Z, I, J)
* program counter (PC)
* stack pointer (SP)
* extra/excess (EX)
* interrupt address (IA)

In this document, anything within [brackets] is shorthand for "the value of the
RAM at the location of the value inside the brackets". For example, SP means
stack pointer, but [SP] means the value of the RAM at the location the stack
pointer is pointing at.

Whenever the CPU needs to read a word, it reads [PC], then increases PC by one.
Shorthand for this is [PC++]. In some cases, the CPU will modify a value before
reading it, in this case the shorthand is [++PC].

For stability and to reduce bugs, it's strongly suggested all multi-byte
operations use little endian in all DCPU-16 programs, wherever possible.



=== INSTRUCTIONS ===============================================================

Instructions are 1-3 words long and are fully defined by the first word.
In a basic instruction, the lower five bits of the first word of the instruction
are the opcode, and the remaining eleven bits are split into a five bit value b
and a six bit value a.
b is always handled by the processor after a, and is the lower five bits.
In bits (in LSB-0 format), a basic instruction has the format: aaaaaabbbbbooooo

In the tables below, C is the time required in cycles to look up the value, or
perform the opcode, VALUE is the numerical value, NAME is the mnemonic, and
DESCRIPTION is a short text that describes the opcode or value.



--- Values: (5/6 bits) ---------------------------------------------------------
 C | VALUE     | DESCRIPTION
---+-----------+----------------------------------------------------------------
 0 | 0x00-0x07 | register (A, B, C, X, Y, Z, I or J, in that order)
 0 | 0x08-0x0f | [register]
 1 | 0x10-0x17 | [register + next word]
 0 |      0x18 | (PUSH / [--SP]) if in b, or (POP / [SP++]) if in a
 0 |      0x19 | [SP] / PEEK
 0 |      0x1a | [SP + next word] / PICK n
 0 |      0x1b | SP
 0 |      0x1c | PC
 0 |      0x1d | EX
 1 |      0x1e | [next word]
 1 |      0x1f | next word (literal)
 0 | 0x20-0x3f | literal value 0xffff-0x1e (-1..30) (literal) (only for a)
 --+-----------+----------------------------------------------------------------
  
* "next word" means "[PC++]". Increases the word length of the instruction by 1.
* By using 0x18, 0x19, 0x1a as PEEK, POP/PUSH, and PICK there's a reverse stack
  starting at memory location 0xffff. Example: "SET PUSH, 10", "SET X, POP"



--- Basic opcodes: (5 bits) ----------------------------------------------------
 C | VAL  | NAME     | DESCRIPTION
---+------+----------+--------------------------------------------------------
 - | 0x00 | n/a      | special instruction - see below
 1 | 0x01 | SET b, a | sets b to a
 2 | 0x02 | ADD b, a | sets b to b+a, sets EX to 0x0001 if there's an overflow, 
   |      |          | 0x0 otherwise
 2 | 0x03 | SUB b, a | sets b to b-a, sets EX to 0xffff if there's an underflow,
   |      |          | 0x0 otherwise
 2 | 0x04 | MUL b, a | sets b to b*a, sets EX to ((b*a)>>16)&0xffff (treats b,
   |      |          | a as unsigned)
 2 | 0x05 | MLI b, a | like MUL, but treat b, a as signed
 3 | 0x06 | DIV b, a | sets b to b/a, sets EX to ((b<<16)/a)&0xffff. if a==0,
   |      |          | sets b and EX to 0 instead. (treats b, a as unsigned)
 3 | 0x07 | DVI b, a | like DIV, but treat b, a as signed
 3 | 0x08 | MOD b, a | sets b to b%a. if a==0, sets b to 0 instead.
 1 | 0x09 | AND b, a | sets b to b&a
 1 | 0x0a | BOR b, a | sets b to b|a
 1 | 0x0b | XOR b, a | sets b to b^a
 2 | 0x0c | SHR b, a | sets b to b>>>a, sets EX to ((b<<16)>>a)&0xffff 
   |      |          | (logical shift)
 2 | 0x0d | ASR b, a | sets b to b>>a, sets EX to ((b<<16)>>>a)&0xffff 
   |      |          | (arithmetic shift) (treats b as signed)
 2 | 0x0e | SHL b, a | sets b to b<<a, sets EX to ((b<<a)>>16)&0xffff
 - | 0x0f | -        |
 2+| 0x10 | IFB b, a | performs next instruction only if (b&a)!=0
 2+| 0x11 | IFC b, a | performs next instruction only if (b&a)==0
 2+| 0x12 | IFE b, a | performs next instruction only if b==a 
 2+| 0x13 | IFN b, a | performs next instruction only if b!=a 
 2+| 0x14 | IFG b, a | performs next instruction only if b>a 
 2+| 0x15 | IFA b, a | performs next instruction only if b>a (signed)
 2+| 0x16 | IFL b, a | performs next instruction only if b<a 
 2+| 0x17 | IFU b, a | performs next instruction only if b<a (signed)
 - | 0x18 | -        |
 - | 0x19 | -        |
 - | 0x1a | -        |
 - | 0x1b | -        |
 - | 0x1c | -        |
 - | 0x1d | -        |
 - | 0x1e | -        |
 - | 0x1f | -        |
---+------+----------+----------------------------------------------------------

* The branching opcodes take one cycle longer to perform if the test fails
* Signed numbers are represented using two's complement.


    
Special opcodes always have their lower five bits unset, have one value and a
five bit opcode. In binary, they have the format: aaaaaaooooo00000
The value (a) is in the same six bit format as defined earlier.

--- Special opcodes: (6 bits) --------------------------------------------------
 C | VAL  | NAME  | DESCRIPTION
---+------+-------+-------------------------------------------------------------
 - | 0x00 | n/a   | reserved for future expansion
 3 | 0x01 | JSR a | pushes the address of the next instruction to the stack,
   |      |       | then sets PC to a
 - | 0x02 | -     |
 - | 0x03 | -     |
 - | 0x04 | -     |
 - | 0x05 | -     |
 - | 0x06 | -     |
 - | 0x07 | -     |
 4 | 0x08 | INT a | triggers a software interrupt with message a
 1 | 0x09 | ING a | sets a to IN 
 1 | 0x0a | INS a | sets IN to a
 - | 0x0b | -     |
 - | 0x0c | -     |
 - | 0x0d | -     |
 - | 0x0e | -     |
 - | 0x0f | -     |
 2 | 0x10 | HWN a | sets a to number of connected hardware devices
 4 | 0x11 | HWQ a | sets A, B, C, X, Y registers to information about hardware a
   |      |       | a+b is a 32 bit word identifying the hardware type
   |      |       | c is the hardware revision
   |      |       | x+y is a 32 bit word identifying the manufacturer
 4+| 0x12 | HWI a | sends an interrupt to hardware a
 - | 0x13 | -     |
 - | 0x14 | -     |
 - | 0x15 | -     |
 - | 0x16 | -     |
 - | 0x17 | -     |
 - | 0x18 | -     |
 - | 0x19 | -     |
 - | 0x1a | -     |
 - | 0x1b | -     |
 - | 0x1c | -     |
 - | 0x1d | -     |
 - | 0x1e | -     |
 - | 0x1f | -     |
---+------+-------+-------------------------------------------------------------



=== INTERRUPTS =================================================================    

When IA is set to something other than 0, interrupts triggered on the DCPU-16
will push PC to the stack, followed by pushing A to the stack, then set the PC
to IA, and A to the interrupt message. A well formed interrupt handler must pop
A from the stack before returning (popping PC from the stack)
 
If IA is set to 0, a triggered interrupt does nothing.

The DCPU-16 will attempt to perform one clock interrupt 60 times per second,
with the A message being 0.



=== HARDWARE ===================================================================    

The DCPU-16 supports up to 65536 connected hardware devices. These devices can
be anything from additional storage, sensors, monitors or speakers.
How to control the hardware is specified per hardware device, but the DCPU-16
supports a standard enumeration method for detecting connected hardware via
the HWN, HWQ and HWI instructions.

Interrupts sent to hardware can't contain messages, can take additional cycles,
and can read or modify any registers or memory adresses on the DCPU-16. This
behavior changes per hardware device and is documented in the hardware
documentation.

Hardware must NOT start modifying registers or ram on the DCPU-16 before at
least one HWI call has been made to the hardware.

The DPCU-16 does not support hot swapping hardware. The behavior of connecting
or disconnecting hardware while the DCPU-16 is undefined.
"""


ometa Literals{
  hexDigit = char:x {'0123456789abcdef'.indexOf(x.toLowerCase())}:v ?(v >= 0) -> v,
  hexLit = hexLit:n hexDigit:d -> (n*16+d)
         | hexDigit,
  decLit = digit+:d -> parseInt(d.join('')),
  binDigit = '0' -> 0
           | '1' -> 1,
  binLit = binLit:n binDigit:d -> (n*2+d)
         | binDigit
  // 'foo' is a literal occurance of 'foo' in the stream (which is messed up, 
  // because matchAll will give you the string 'foobar' as ['f','o','o','b','a','r'])
  // "foo" is `space* seq('foo')` where space is anything <=32 and seq matches character
  // by character sequentially
  // in other words, annoying to figure out (ffs) and annoying to deal with newline-delimited text like assembly or specdocs
  // Ometa/JS 101 is: match vs matchAll details (no, Things You Should Know does NOT qualify) and 'foo' vs "foo"
  // possibly to override by defining `token :x = ' '* seq(x)` or whatever
}

test = function(o,ts) { // run KATs against an ometa object, passed as string name
  console.log(o+':')
  for(var i=0;i<ts.length;i++) {
    var real=eval(o).matchAll(ts[i][1],ts[i][0]), expected=ts[i][2]
    console.log('\t'+ (real.toString()===expected.toString()?'[x] ':'[ ] ')+ real +'\t== '+ expected)
  }
}

test('Literals',
  [['decLit', '123', 123]
  ,['hexLit', 'ff', 255]
  ,['binLit', '1110', 14]
  ])


// Time to get nuts

// Parse ASCII table from spec:
//   table = [name,bit_size,listOf(row)]
//   row = listOf(col)


// sequence of characters -> string -> strip start/end whitespace
str = function(cs) {return cs.join('').replace(/^[ ]+/,'').replace(/[ ]+$/,'')}

ometa Table {
  table = head:h row+:rs -> ['table',h,rs],
  head = "---" between(' ',':'):name "" between('(',')'):size "-"+ '\n' 
             -> [name,size.slice(0,-5)],
  between :x :y = fromTo(x,y):s -> s.slice(1,-1),
  row = "---+" fromTo('-','\n')  -> ['skip']
      | seq('   | ') cells:cs    -> ['row_cont',''].concat(cs)
      | cell1:c cells:cs         -> ['row',c].concat(cs),
  cell1 = char:a char:b char:c '|'       -> str([a,b,c]),
  cells = (~sep ~'\n' char)+:cs sep cells:rest -> [str(cs)].concat(rest)
        | (~'\n' char)+:cs '\n'          -> [str(cs)],
  sep = '|' ' '
}

test('Table',
  [['head', '--- Values: (5/6 bits) --------\n', ['Values', '5/6']]
  ,['row',  '---+----\n',                        ['skip']]
  ,['row',  '123| 456| 789\n',                   ['row','123','456','789']]
  ,['row',  '   |      |       | then sets PC to a\n', ['row_cont','','','','then sets PC to a']]
])


// Parse http://dcpu.com/highnerd/dcpu16.txt into a list of string-filled named tables.
ometa Doc <: Table {
  tables = ((~table line)* table)*,
  line = (~'\n' char)* '\n'
}

tables = Doc.matchAll(spec,'tables')
//console.log(JSON.parse(JSON.stringify(tables)))

skip = function(arr) {return arr.filter(function(x){return x[0]!='skip'})}

// Transform text tables into something more useful.
// Switching between pattern matching on [[][[][]]][]], and strings, seems impossible. Hm.
// That's kind of annoying for what I'm trying to do - I'd like Table to work with -any- 
// table, and not hardcode any table-specific knowhow.
ometa LUT <: Literals {
  lut = table*,
  table = ['table' ['Values' :size] [operand*:rows]]          -> ['operand', size, skip(rows)]
        | ['table' ['Basic opcodes' :size] [basic*:rows]]     -> ['basic',   size, skip(rows)]
        | ['table' ['Special opcodes' :size] [special*:rows]] -> ['special', size, skip(rows)],
  // cycle costs, machine codes, and memory targets of operands:
  operand = ['row' 'C' 'VALUE' 'DESCRIPTION']             -> ['skip']
          | ['row' decLit:cycles code:code target:target] -> [code, cycles, target]
          | :x -> x,
  target = ['[' reg:r seq(' + next word]') char*] -> ['offset',r]
         | ['[' reg:r ']' char*]                  -> ['indirect',r]
         | [reg:r char*]                          -> ['direct',r]
         | ["(PUSH" char*]                        -> ['indirect', 'pushpop'] // dependant on whether a or b
         | ["literal" char*]                      -> ['literal']
         | :x -> ['TODO',x],
  reg = "next word" -> 'word'
      | "register" -> 'reg'
      | "SP" | "PC" | "EX",
  // basic (two-operand) instruction cycle costs, machine codes, and operational semantics:
  basic = ['row' 'C' 'VAL' 'NAME' 'DESCRIPTION']              -> ['skip']
        | ['row' '-' code ['-' char*]]                        -> ['skip']
        | ['row_cont' :c :val :name :desc]                    -> ['skip'] // ignore for now, contains -some- data
        | ['row' '-' code:code 'n/a' ["special" char*]]       -> ['skip'] // special instructions go here
        | ['row' cycles:cycles code:code instr:instr effect:effect] -> [code, cycles, instr, effect]
        | anything,
  // special (one-operand) instructions:
  special = [`row `C `VAL `NAME `DESCRIPTION] -> [`skip]
          | [`row '-' :a :b] -> [`skip]
          | [`row '-' :a :b :c] -> [`skip]
          | [`row_cont '' '' '' :desc_cont] -> [`skip] // contains useful data, skip for now
          | [`row cycles:cycles code:code instr:instr effect:effect] -> [code, cycles, instr, effect]
          | anything,
  // utility:
  cycles = [decLit:c]
         | [decLit:c '+'] -> ['minimum',c],
  instr = [(~' ' char)+:cs seq(' b, a')] -> [cs.join(''), 2]
        | [(~' ' char)+:cs seq(' a')] -> [cs.join(''), 1],
  code = ['0' 'x' hexLit:x] -> x
       | ['0' 'x' hexLit:from '-' '0' 'x' hexLit:to] -> ['range',from,to],
  effect = ["performs next instruction only if " char*:cond] -> ['branch', cond.join('')]
         | ["sets b to " char*:result] -> ['assign', result.join('')]
         | anything
}

luts = LUT.matchAll(tables,'lut')
console.log(JSON.parse(JSON.stringify(luts)))

logJSON = function(x){console.log(JSON.parse(JSON.stringify(x)))}

ometa PrintLUT {
  luts = lut* -> 0,
  lut [:name :bits [row*]] -> console.log(['\t(TABLE:', name, ' BITS:', bits, ')'].join('')),
  row = [:code :cycles :name :effect]:x -> logJSON(x)
      | [:code :cycles :effect]:x -> logJSON(x)
}

console.log(PrintLUT.matchAll(luts, 'luts'))
