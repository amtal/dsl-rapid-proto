packets_c2s.h:
 
#define u8 unsigned char;
#define u16 unsigned short;
#define u32 unsigned int;

#define SIZE_UNKNOWN 0
#define SIZE_DYNAMIC -1
const int size_lut[256] = {-1,5,9,5,9,5,9,9,5,9,9,-1,5,9,9,5,9,9,-1,9,-1,-1,13,5,17,5,9,9,3,9,9,17,13,9,5,9,5,9,13,9,9,9,9,-1,-1,-1,-1,9,9,9,17,17,5,17,9,5,13,5,3,3,9,5,5,3,1,1,-1,-1,17,9,13,13,1,9,-1,9,5,3,-1,7,9,9,-1,1,1,-1,-1,-1,3,17,-1,-1,-1,7,6,5,1,3,5,5,-1,-1,-1,-1,37,1,-1,1,262,13,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
struct /*0x1*/ walk {
	u8	k;	// 1
	u16	x;
	u16	y;
}
struct /*0x2*/ walk_to_entity {
	u8	k;	// 2
	u32	entity_kind;
	u32	id;
}
struct /*0x3*/ run {
	u8	k;	// 3
	u16	x;
	u16	y;
}
struct /*0x4*/ run_to_entity {
	u8	k;	// 4
	u32	entity_kind;
	u32	id;
}
struct /*0x5*/ shift_left_click_skill {
	u8	k;	// 5
	u16	x;
	u16	y;
}
struct /*0x6*/ left_skill_on_unit {
	u8	k;	// 6
	u32	entity_kind;
	u32	id;
}
struct /*0x7*/ shift_left_skill_on_unit {
	u8	k;	// 7
	u32	entity_kind;
	u32	id;
}
struct /*0x8*/ shift_left_skill__hold_ {
	u8	k;	// 8
	u16	x;
	u16	y;
}
struct /*0x9*/ left_skill_on_unit__hold_ {
	u8	k;	// 9
	u32	entity_kind;
	u32	id;
}
struct /*0xa*/ shift_left_skill_unit__hold_ {
	u8	k;	// 10
	u32	entity_kind;
	u32	id;
}
// 0xb 1<Unknown>0b
struct /*0xc*/ right_skill {
	u8	k;	// 12
	u16	x;
	u16	y;
}
struct /*0xd*/ right_skill_unit {
	u8	k;	// 13
	u32	entity_kind;
	u32	id;
}
struct /*0xe*/ shift_right_skill_unit {
	u8	k;	// 14
	u32	entity_kind;
	u32	id;
}
struct /*0xf*/ right_skill__hold_ {
	u8	k;	// 15
	u16	x;
	u16	y;
}
struct /*0x10*/ right_skill_unit__hold_ {
	u8	k;	// 16
	u32	entity_kind;
	u32	id;
}
struct /*0x11*/ shift_right_skill_unit__hold_ {
	u8	k;	// 17
	u32	entity_kind;
	u32	id;
}
// 0x12 1<Unknown>12
struct /*0x13*/ interact__click__entity {
	u8	k;	// 19
	u32	entity_kind;
	u32	id;
}
struct /*0x14*/ overhead_chat {
	u8	k;	// 20
	u8	k1;	// 0
	u8	k2;	// 0
	char*	message;
	u8	k3;	// 0
	u8	k4;	// 0
	u8	k5;	// 0
}
struct /*0x15*/ chat {
	u8	k;	// 21
	u8	k1;	// 1
	u8	k2;	// 0
	char*	message;
	u8	k3;	// 0
	u8	k4;	// 0
	u8	k5;	// 0
}
struct /*0x16*/ pick_item__ground_ {
	u8	k;	// 22
	u8	k1;	// 4
	u8	k2;	// 0
	u8	k3;	// 0
	u8	k4;	// 0
	u32	id;
	u32	inventory;	// (0) or cursor (1)
}
struct /*0x17*/ drop_item__ground_ {
	u8	k;	// 23
	u32	id;
}
struct /*0x18*/ insert_item_in_buffer {
	u8	k;	// 24
	u32	id;
	u32	xpos;
	u32	ypos;
	u32	buffer;
}
struct /*0x19*/ remove_item_from_buffer {
	u8	k;	// 25
	u32	id;
}
struct /*0x1a*/ equip_item {
	u8	k;	// 26
	u32	id;
	u16	position;
	u8	k1;	// 0
	u8	k2;	// 0
}
struct /*0x1b*/ swap_2_handed_item {
	u8	k;	// 27
	u32	id;
	u16	position;
	u8	k1;	// 0
	u8	k2;	// 0
}
struct /*0x1c*/ remove_body_item {
	u8	k;	// 28
	u16	position;
}
struct /*0x1d*/ swap_cursor_item_with_body {
	u8	k;	// 29
	u32	id;
	u16	position;
	u8	k1;	// 0
	u8	k2;	// 0
}
struct /*0x1e*/ swap_2_1_handed_items_with_a_2_handed_item {
	u8	k;	// 30
	u32	unknown;
	u32	unknown1;
}
struct /*0x1f*/ swap_cursor_buffer_items {
	u8	k;	// 31
	u32	cursor_item;	// id
	u32	buffer_item;	// id
	u32	xpos;
	u32	ypos;
}
struct /*0x20*/ activate_buffer_item {
	u8	k;	// 32
	u32	id;
	u16	x;
	u8	k1;	// 0
	u8	k2;	// 0
	u16	y;
	u8	k3;	// 0
	u8	k4;	// 0
}
struct /*0x21*/ stack_items {
	u8	k;	// 33
	u32	item_to;	// stack id
	u32	item_where;	// it stacks id
}
struct /*0x22*/ unstack_items {
	u8	k;	// 34
	u32	unknown;
}
struct /*0x23*/ item_to_belt {
	u8	k;	// 35
	u32	id;
	u16	x;
	u16	y;
}
struct /*0x24*/ item_from_belt {
	u8	k;	// 36
	u32	id;
}
struct /*0x25*/ switch_belt_item {
	u8	k;	// 37
	u32	cursor_item;
	u32	belt_item;
}
struct /*0x26*/ use_belt_item {
	u8	k;	// 38
	u32	id;
	u32	shift_key;	// stats
	u32	unknown;
}
struct /*0x27*/ identify_item {
	u8	k;	// 39
	u32	item_id;
	u32	scroll_id;
}
struct /*0x28*/ socket_item {
	u8	k;	// 40
	u32	item_to;	// socket id
	u32	socketable_item;	// id
}
struct /*0x29*/ scroll_to_book {
	u8	k;	// 41
	u32	scroll_id;
	u32	book_id;
}
struct /*0x2a*/ item_to_cube__indirect_ {
	u8	k;	// 42
	u32	item_id;
	u32	cube_id;
}
// 0x2b Unused
// 0x2c UnusedLoggedashack
// 0x2d UnusedLoggedashack
// 0x2e Unknown
struct /*0x2f*/ initiate_entity_chat {
	u8	k;	// 47
	u32	entity_kind;
	u32	id;
}
struct /*0x30*/ terminate_entity_chat {
	u8	k;	// 48
	u32	entity_kind;
	u32	id;
}
struct /*0x31*/ quest_message {
	u8	k;	// 49
	u32	id;
	u32	message;
}
struct /*0x32*/ buy_item_from_npc_buffer {
	u8	k;	// 50
	u32	entity_id;
	u32	item_id;
	u32	tab;
	u32	cost;
}
struct /*0x33*/ sell_item_to_npc_buffer {
	u8	k;	// 51
	u32	entity_id;
	u32	item_id;
	u32	tab;
	u32	cost;
}
struct /*0x34*/ identify_items_with_npc {
	u8	k;	// 52
	u32	entity_id;
}
struct /*0x35*/ repair {
	u8	k;	// 53
	u32	entity_id;
	u32	item_id;
	u32	tab;
	u32	cost;	// ?
}
struct /*0x36*/ hire_merc {
	u8	k;	// 54
	u32	entity_id;
	u32	merc_id;
}
struct /*0x37*/ identify__from_gamble_ {
	u8	k;	// 55
	u32	item_id;
}
struct /*0x38*/ entity_action {
	u8	k;	// 56
	u32	action;
	u32	entity_id;
	u32	complement;
}
struct /*0x39*/ purchase_life {
	u8	k;	// 57
	u32	npc_id;
}
struct /*0x3a*/ add_stat_point {
	u8	k;	// 58
	u16	stat;
}
struct /*0x3b*/ add_skill_point {
	u8	k;	// 59
	u16	skill;
}
struct /*0x3c*/ select_skill {
	u8	k;	// 60
	u16	skill;
	u8	k1;	// 0
	u8	left;	// (80) or right 00) skill
	u8	k2;	// 255
	u8	k3;	// 255
	u8	k4;	// 255
	u8	k5;	// 255
}
struct /*0x3d*/ highlight_a_door__logged_as_mode__5__crash__ {
	u8	k;	// 61
	u32	object_id;
}
struct /*0x3e*/ activate_scroll_of_inifuss {
	u8	k;	// 62
	u32	scroll_of;	// infuss. id
}
struct /*0x3f*/ play_audio {
	u8	k;	// 63
	u16	sound_message;
}
struct /*0x40*/ request_quest_data {
	u8	k;	// 64
}
struct /*0x41*/ resurrect {
	u8	k;	// 65
}
// 0x42 Unknown/Unused
// 0x43 Unknown/Unused
struct /*0x44*/ staff_in_orifice {
	u8	k;	// 68
	u32	orifice_entity;	// kind
	u32	orifice_id;
	u32	staff_id;
	u32	entity_state;
}
struct /*0x45*/ change_tp_location__logged_as_hack__ {
	u8	k;	// 69
	u32	entity_id;
	u16	location;
	u8	k1;	// 0
	u8	k2;	// 0
}
struct /*0x46*/ have_merc_interact {
	u8	k;	// 70
	u32	merc_id;
	u32	entity_id;
	u32	entity_type;
}
struct /*0x47*/ move_merc {
	u8	k;	// 71
	u32	merc_id;
	u16	x;
	u8	k1;	// 0
	u8	k2;	// 0
	u16	y;
	u8	k3;	// 0
	u8	k4;	// 0
}
struct /*0x48*/ turns_off_busy_state {
	u8	k;	// 72
}
struct /*0x49*/ take_wp_close_wp {
	u8	k;	// 73
	u32	wp_id;
	u8	destination;
	u8	k1;	// 0
	u8	k2;	// 0
	u8	k3;	// 0
}
// 0x4a Unused
struct /*0x4b*/ request_entity_update {
	u8	k;	// 75
	u32	entity_type;
	u32	entity_id;
}
struct /*0x4c*/ transmorgify {
	u8	k;	// 76
	u32	object_id;
}
struct /*0x4d*/ play_npc_message {
	u8	k;	// 77
	u16	npc_sound;	// Message
}
// 0x4e Unused
struct /*0x4f*/ click_button {
	u8	k;	// 79
	u16	button_id;
	u16	unknown;
	u16	complement;
}
struct /*0x50*/ drop_gold {
	u8	k;	// 80
	u32	player_id;
	u32	gold_pieces;
}
struct /*0x51*/ bind_hotkey_to_skill {
	u8	k;	// 81
	u8	skill;
	u8	left;	// (80) or right 00) skill
	u16	hotkey;
	u8	k1;	// 255
	u8	k2;	// 255
	u8	k3;	// 255
	u8	k4;	// 255
}
// 0x52 5<Unknown>52[DWORDunknown]
struct /*0x53*/ turn_stamina_on__not_used__ {

}
// 0x53 
struct /*0x54*/ turn_stamina_off__not_used_ {
	u8	k;	// 84
}
// 0x55 Unused
// 0x56 Unused
// 0x57 Unused
struct /*0x58*/ quest_completed {
	u8	k;	// 88
	u16	quest_id;
}
struct /*0x59*/ make_entity_move {
	u8	k;	// 89
	u32	entity_kind;
	u32	entity_id;
	u16	x;
	u8	k1;	// 0
	u8	k2;	// 0
	u16	y;
	u8	k3;	// 0
	u8	k4;	// 0
}
// 0x5a Unused
// 0x5b Unused
// 0x5c Unused
struct /*0x5d*/ squelch_hostile {
	u8	k;	// 93
	u8	button;
	u8	toggle_on;	// /off
	u32	player_id;
}
struct /*0x5e*/ invite_party {
	u8	k;	// 94
	u8	button;
	u32	player_id;
}
struct /*0x5f*/ update_player_pos {
	u8	k;	// 95
	u16	x;
	u16	y;
}
struct /*0x60*/ swap_weapons {
	u8	k;	// 96
}
struct /*0x61*/ drop_pickup_merc_item {
	u8	k;	// 97
	u16	position;	// (00 to drop)
}
struct /*0x62*/ resurrect_merc {
	u8	k;	// 98
	u32	npc_id;
}
struct /*0x63*/ shift_left_click_item__to_belt_ {
	u8	k;	// 99
	u32	item;
}
// 0x64 9<HackDetection>64[DWORDunknown][DWORDunknown]
// 0x65 <HackDetection>65
struct /*0x66*/ warden_response {
	u8	k;	// 102
	u8	data_length;
	u8	k1;	// 0
	u8*	data;
}
// 0x67 
struct /*0x68*/ game_join_request {
	u8	k;	// 104
	u32	server_hash;
	u16	server_token;
	u8	char_type;
	u32	verbyte;	// (0x0d)
	u32	unknown;
	u32	unknown1;
	u8	k1;	// 0
	u8	char_name[15];
	u8	k2;	// 0
}
struct /*0x69*/ leave_game {
	u8	k;	// 105
}
// 0x6a 
struct /*0x6b*/ join_game {
	u8	k;	// 107
}
struct /*0x6c*/ upload_character_save {
	u8	k;	// 108
	u32	unknown;
	u32	unknown1;
	u8	savefile[252];
}
struct /*0x6d*/ ping {
	u8	k;	// 109
	u32	tickcount;
	u32	delay;
	u32	wardenresponse;	// (or 00000000)
}
// 0x6e Unknown/Unused
// 0x6f Unknown/Unused
const struct walk WALK = {0x1,0,0};
const struct walk_to_entity WALK_TO_ENTITY = {0x2,0,0};
const struct run RUN = {0x3,0,0};
const struct run_to_entity RUN_TO_ENTITY = {0x4,0,0};
const struct shift_left_click_skill SHIFT_LEFT_CLICK_SKILL = {0x5,0,0};
const struct left_skill_on_unit LEFT_SKILL_ON_UNIT = {0x6,0,0};
const struct shift_left_skill_on_unit SHIFT_LEFT_SKILL_ON_UNIT = {0x7,0,0};
const struct shift_left_skill__hold_ SHIFT_LEFT_SKILL__HOLD_ = {0x8,0,0};
const struct left_skill_on_unit__hold_ LEFT_SKILL_ON_UNIT__HOLD_ = {0x9,0,0};
const struct shift_left_skill_unit__hold_ SHIFT_LEFT_SKILL_UNIT__HOLD_ = {0xa,0,0};
const struct right_skill RIGHT_SKILL = {0xc,0,0};
const struct right_skill_unit RIGHT_SKILL_UNIT = {0xd,0,0};
const struct shift_right_skill_unit SHIFT_RIGHT_SKILL_UNIT = {0xe,0,0};
const struct right_skill__hold_ RIGHT_SKILL__HOLD_ = {0xf,0,0};
const struct right_skill_unit__hold_ RIGHT_SKILL_UNIT__HOLD_ = {0x10,0,0};
const struct shift_right_skill_unit__hold_ SHIFT_RIGHT_SKILL_UNIT__HOLD_ = {0x11,0,0};
const struct interact__click__entity INTERACT__CLICK__ENTITY = {0x13,0,0};
const struct overhead_chat OVERHEAD_CHAT = {0x14,0x0,0x0,0,0x0,0x0,0x0};
const struct chat CHAT = {0x15,0x1,0x0,0,0x0,0x0,0x0};
const struct pick_item__ground_ PICK_ITEM__GROUND_ = {0x16,0x4,0x0,0x0,0x0,0,0};
const struct drop_item__ground_ DROP_ITEM__GROUND_ = {0x17,0};
const struct insert_item_in_buffer INSERT_ITEM_IN_BUFFER = {0x18,0,0,0,0};
const struct remove_item_from_buffer REMOVE_ITEM_FROM_BUFFER = {0x19,0};
const struct equip_item EQUIP_ITEM = {0x1a,0,0,0x0,0x0};
const struct swap_2_handed_item SWAP_2_HANDED_ITEM = {0x1b,0,0,0x0,0x0};
const struct remove_body_item REMOVE_BODY_ITEM = {0x1c,0};
const struct swap_cursor_item_with_body SWAP_CURSOR_ITEM_WITH_BODY = {0x1d,0,0,0x0,0x0};
const struct swap_2_1_handed_items_with_a_2_handed_item SWAP_2_1_HANDED_ITEMS_WITH_A_2_HANDED_ITEM = {0x1e,0,0};
const struct swap_cursor_buffer_items SWAP_CURSOR_BUFFER_ITEMS = {0x1f,0,0,0,0};
const struct activate_buffer_item ACTIVATE_BUFFER_ITEM = {0x20,0,0,0x0,0x0,0,0x0,0x0};
const struct stack_items STACK_ITEMS = {0x21,0,0};
const struct unstack_items UNSTACK_ITEMS = {0x22,0};
const struct item_to_belt ITEM_TO_BELT = {0x23,0,0,0};
const struct item_from_belt ITEM_FROM_BELT = {0x24,0};
const struct switch_belt_item SWITCH_BELT_ITEM = {0x25,0,0};
const struct use_belt_item USE_BELT_ITEM = {0x26,0,0,0};
const struct identify_item IDENTIFY_ITEM = {0x27,0,0};
const struct socket_item SOCKET_ITEM = {0x28,0,0};
const struct scroll_to_book SCROLL_TO_BOOK = {0x29,0,0};
const struct item_to_cube__indirect_ ITEM_TO_CUBE__INDIRECT_ = {0x2a,0,0};
const struct initiate_entity_chat INITIATE_ENTITY_CHAT = {0x2f,0,0};
const struct terminate_entity_chat TERMINATE_ENTITY_CHAT = {0x30,0,0};
const struct quest_message QUEST_MESSAGE = {0x31,0,0};
const struct buy_item_from_npc_buffer BUY_ITEM_FROM_NPC_BUFFER = {0x32,0,0,0,0};
const struct sell_item_to_npc_buffer SELL_ITEM_TO_NPC_BUFFER = {0x33,0,0,0,0};
const struct identify_items_with_npc IDENTIFY_ITEMS_WITH_NPC = {0x34,0};
const struct repair REPAIR = {0x35,0,0,0,0};
const struct hire_merc HIRE_MERC = {0x36,0,0};
const struct identify__from_gamble_ IDENTIFY__FROM_GAMBLE_ = {0x37,0};
const struct entity_action ENTITY_ACTION = {0x38,0,0,0};
const struct purchase_life PURCHASE_LIFE = {0x39,0};
const struct add_stat_point ADD_STAT_POINT = {0x3a,0};
const struct add_skill_point ADD_SKILL_POINT = {0x3b,0};
const struct select_skill SELECT_SKILL = {0x3c,0,0x0,0,0xff,0xff,0xff,0xff};
const struct highlight_a_door__logged_as_mode__5__crash__ HIGHLIGHT_A_DOOR__LOGGED_AS_MODE__5__CRASH__ = {0x3d,0};
const struct activate_scroll_of_inifuss ACTIVATE_SCROLL_OF_INIFUSS = {0x3e,0};
const struct play_audio PLAY_AUDIO = {0x3f,0};
const struct request_quest_data REQUEST_QUEST_DATA = {0x40};
const struct resurrect RESURRECT = {0x41};
const struct staff_in_orifice STAFF_IN_ORIFICE = {0x44,0,0,0,0};
const struct change_tp_location__logged_as_hack__ CHANGE_TP_LOCATION__LOGGED_AS_HACK__ = {0x45,0,0,0x0,0x0};
const struct have_merc_interact HAVE_MERC_INTERACT = {0x46,0,0,0};
const struct move_merc MOVE_MERC = {0x47,0,0,0x0,0x0,0,0x0,0x0};
const struct turns_off_busy_state TURNS_OFF_BUSY_STATE = {0x48};
const struct take_wp_close_wp TAKE_WP_CLOSE_WP = {0x49,0,0,0x0,0x0,0x0};
const struct request_entity_update REQUEST_ENTITY_UPDATE = {0x4b,0,0};
const struct transmorgify TRANSMORGIFY = {0x4c,0};
const struct play_npc_message PLAY_NPC_MESSAGE = {0x4d,0};
const struct click_button CLICK_BUTTON = {0x4f,0,0,0};
const struct drop_gold DROP_GOLD = {0x50,0,0};
const struct bind_hotkey_to_skill BIND_HOTKEY_TO_SKILL = {0x51,0,0,0,0xff,0xff,0xff,0xff};
const struct turn_stamina_on__not_used__ TURN_STAMINA_ON__NOT_USED__ = {};
const struct turn_stamina_off__not_used_ TURN_STAMINA_OFF__NOT_USED_ = {0x54};
const struct quest_completed QUEST_COMPLETED = {0x58,0};
const struct make_entity_move MAKE_ENTITY_MOVE = {0x59,0,0,0,0x0,0x0,0,0x0,0x0};
const struct squelch_hostile SQUELCH_HOSTILE = {0x5d,0,0,0};
const struct invite_party INVITE_PARTY = {0x5e,0,0};
const struct update_player_pos UPDATE_PLAYER_POS = {0x5f,0,0};
const struct swap_weapons SWAP_WEAPONS = {0x60};
const struct drop_pickup_merc_item DROP_PICKUP_MERC_ITEM = {0x61,0};
const struct resurrect_merc RESURRECT_MERC = {0x62,0};
const struct shift_left_click_item__to_belt_ SHIFT_LEFT_CLICK_ITEM__TO_BELT_ = {0x63,0};
const struct warden_response WARDEN_RESPONSE = {0x66,0,0x0,0};
const struct game_join_request GAME_JOIN_REQUEST = {0x68,0,0,0,0,0,0,0x0,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},0x0};
const struct leave_game LEAVE_GAME = {0x69};
const struct join_game JOIN_GAME = {0x6b};
const struct upload_character_save UPLOAD_CHARACTER_SAVE = {0x6c,0,0,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
const struct ping PING = {0x6d,0,0,0};