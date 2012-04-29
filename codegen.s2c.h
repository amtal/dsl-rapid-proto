#define u8 unsigned char;
#define u16 unsigned short;
#define u32 unsigned int;

#define SIZE_UNKNOWN 0
#define SIZE_DYNAMIC -1
const int size_lut[256] = {1,8,1,12,1,1,1,6,6,12,6,6,9,13,12,16,16,8,-1,-1,-1,11,-1,-1,-1,2,2,3,5,3,4,6,10,12,12,13,-1,-1,-1,40,103,97,15,-1,8,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,8,-1,-1,6,-1,-1,-1,-1,11,11,-1,-1,-1,16,17,7,1,15,14,42,10,-1,-1,-1,-1,-1,26,40,36,5,5,-1,-1,7,-1,-1,-1,-1,7,-1,16,21,12,-1,16,16,10,-1,-1,-1,-1,-1,-1,10,13,6,2,21,6,13,8,6,18,-1,10,-1,20,29,-1,-1,-1,-1,-1,-1,2,6,6,11,7,10,33,13,-1,-1,-1,-1,13,9,1,-1,16,-1,7,-1,-1,7,8,10,7,8,-1,-1,-1,-1,7,-1,7,-1,7,-1,-1,-1,2,1,-1,-1,5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
const struct game_loading GAME_LOADING = {0x0};
const struct game_flags GAME_FLAGS = {0x1,0,0,0,0,0};
const struct load_successful LOAD_SUCCESSFUL = {0x2};
const struct load_act LOAD_ACT = {0x3,0,0,0,0};
const struct load_complete LOAD_COMPLETE = {0x4};
const struct unload_complete UNLOAD_COMPLETE = {0x5};
const struct game_exit_sucessful GAME_EXIT_SUCESSFUL = {0x6};
const struct map_reveal MAP_REVEAL = {0x7,0,0,0};
const struct map_hide MAP_HIDE = {0x8,0,0,0};
const struct assign_lvl_warp__door_ ASSIGN_LVL_WARP__DOOR_ = {0x9,0,0,0,0,0};
const struct remove_object REMOVE_OBJECT = {0xa,0,0};
const struct game_handshake GAME_HANDSHAKE = {0xb,0,0};
const struct npc_hit NPC_HIT = {0xc,0,0,0,0};
const struct player_stop PLAYER_STOP = {0xd,0,0,0,0,0,0,0};
const struct object_state OBJECT_STATE = {0xe,0,0,0,0,0};
const struct player_move PLAYER_MOVE = {0xf,0,0,0,0,0,0x0,0,0};
const struct player_to_target PLAYER_TO_TARGET = {0x10,0,0,0,0,0,0,0};
const struct report_kill REPORT_KILL = {0x11,0,0,0};
const struct reassign_player REASSIGN_PLAYER = {0x15,0,0,0,0,0};
const struct _byte_gold_to_inv_ _BYTE_GOLD_TO_INV_ = {0x19,0};
const struct _byte_add_exp_ _BYTE_ADD_EXP_ = {0x1a,0};
const struct _word_add_exp_ _WORD_ADD_EXP_ = {0x1b,0};
const struct _dword_add_exp_ _DWORD_ADD_EXP_ = {0x1c,0};
const struct _byte_base_attribute _BYTE_BASE_ATTRIBUTE = {0x1d,0,0};
const struct _word_base_attribute _WORD_BASE_ATTRIBUTE = {0x1e,0,0};
const struct _dword_base_attribute _DWORD_BASE_ATTRIBUTE = {0x1f,0,0};
const struct attribute_update ATTRIBUTE_UPDATE = {0x20,0,0,0};
const struct update_item_oskill UPDATE_ITEM_OSKILL = {0x21,0,0,0,0,0,0};
const struct update_item_skill UPDATE_ITEM_SKILL = {0x22,0,0,0,0,0};
const struct set_skill SET_SKILL = {0x23,0,0,0,0,0xff,0xff,0xff,0xff};
const struct game_chat GAME_CHAT = {0x26,0,0,0,0,0,0,0x0,0,0x0};
const struct npc_info NPC_INFO = {0x27,0,0,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
const struct quest_info QUEST_INFO = {0};
const struct game_quest_info GAME_QUEST_INFO = {0};
const struct npc_transaction NPC_TRANSACTION = {0x2a,0,0,0,0,0};
const struct play_sound PLAY_SOUND = {0x2c,0,0,0};
const struct update_item_stats UPDATE_ITEM_STATS = {0};
const struct use_stackable_item USE_STACKABLE_ITEM = {0};
const struct clear_cursor CLEAR_CURSOR = {0x42,0,0};
const struct relator_1 RELATOR_1 = {0x47,0,0,0};
const struct relator_2 RELATOR_2 = {0x48,0,0,0};
const struct unit_skill_on_target UNIT_SKILL_ON_TARGET = {0x4c,0,0,0,0,0,0,0x0,0x0};
const struct unit_cast_skill UNIT_CAST_SKILL = {0x4d,0,0,0,0,0,0,0x0,0x0};
const struct merc_for_hire MERC_FOR_HIRE = {0x4e,0,0};
const struct start_merc_list START_MERC_LIST = {0x4f};
const struct _______needs_research__ _______NEEDS_RESEARCH__ = {};
const struct assign_object ASSIGN_OBJECT = {0x51,0,0,0,0,0,0,0};
const struct quest_log_info QUEST_LOG_INFO = {0};
const struct player_slot_refresh PLAYER_SLOT_REFRESH = {0x53,0,0,0};
const struct assign_player ASSIGN_PLAYER = {0x59,0,0,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},0,0};
const struct event_messages EVENT_MESSAGES = {0};
const struct player_in_game PLAYER_IN_GAME = {0x5b,0,0,0,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},0,0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};
const struct player_left_game PLAYER_LEFT_GAME = {0x5c,0};
const struct quest_item_state QUEST_ITEM_STATE = {0x5d,0,0};
const struct townportal_state TOWNPORTAL_STATE = {0x60,0,0,0};
const struct waypoint_menu WAYPOINT_MENU = {0x63,0,0};
const struct player_kill_count PLAYER_KILL_COUNT = {0x65,0,0};
const struct npc_move NPC_MOVE = {0x67,0,0,0,0,0,0,0,0};
const struct npc_move_to_target NPC_MOVE_TO_TARGET = {0x68,0,0,0,0,0,0,0,0,0,0};
const struct npc_state NPC_STATE = {0x69,0,0,0,0,0,0};
const struct npc_action NPC_ACTION = {0x6b,0,0,0x0,0x0,0x0,0x0,0x0,0x0,0,0};
const struct npc_attack NPC_ATTACK = {0x6c,0,0,0,0,0,0};
const struct npc_stop NPC_STOP = {0x6d,0,0,0,0};
const struct player_corpse_assign PLAYER_CORPSE_ASSIGN = {0x74,0,0,0};
const struct player_party_info PLAYER_PARTY_INFO = {0x75,0,0,0,0,0};
const struct player_in_proximity PLAYER_IN_PROXIMITY = {0x76,0,0};
const struct button_actions BUTTON_ACTIONS = {0x77,0};
const struct trade_accepted TRADE_ACCEPTED = {0x78,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},0};
const struct gold_in_trade GOLD_IN_TRADE = {0x79,0,0};
const struct pet_action PET_ACTION = {0x7a,0,0,0,0,0};
const struct assign_skill_hotkey ASSIGN_SKILL_HOTKEY = {0x7b,0,0,0,0xff,0xff,0xff,0xff};
const struct use_scroll USE_SCROLL = {0x7c,0,0};
const struct set_item_state SET_ITEM_STATE = {0};
const struct ally_party_info ALLY_PARTY_INFO = {0x7f,0,0,0,0};
const struct assign_merc ASSIGN_MERC = {0x81,0,0,0,0,0,0};
const struct portal_ownership PORTAL_OWNERSHIP = {0x82,0,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},0,0};
const struct special_quest_event SPECIAL_QUEST_EVENT = {0x89,0};
const struct npc_wants_to_interact NPC_WANTS_TO_INTERACT = {0x8a,0,0};
const struct player_relationship PLAYER_RELATIONSHIP = {0x8b,0,0};
const struct relationship_update RELATIONSHIP_UPDATE = {0x8c,0,0,0};
const struct assign_player_to_party ASSIGN_PLAYER_TO_PARTY = {0x8d,0,0};
const struct corpse_assign CORPSE_ASSIGN = {0x8e,0,0,0};
const struct pong PONG = {0x8f,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
const struct party_automap_info PARTY_AUTOMAP_INFO = {0x90,0,0,0};
const struct base_skill_levels BASE_SKILL_LEVELS = {0x94,0,0,0,0,0};
const struct life_and_mana_update LIFE_AND_MANA_UPDATE = {0x95,0,0,0,0,0,0};
const struct walk_verify WALK_VERIFY = {0x96,0,0,0,0};
const struct weapon_switch WEAPON_SWITCH = {0x97};
const struct skill_triggered SKILL_TRIGGERED = {0};
const struct _merc_related__ _MERC_RELATED__ = {0x9b,0,0};
const struct item_action__world_ ITEM_ACTION__WORLD_ = {0};
const struct item_action__owned_ ITEM_ACTION__OWNED_ = {0};
const struct _byte_merc_attribute _BYTE_MERC_ATTRIBUTE = {0x9e,0,0,0};
const struct _word_merc_attribute _WORD_MERC_ATTRIBUTE = {0x9f,0,0,0};
const struct _dword_merc_attribute _DWORD_MERC_ATTRIBUTE = {0xa0,0,0,0};
const struct _byte_merc_add_exp_ _BYTE_MERC_ADD_EXP_ = {0};
const struct _word_merc_add_exp_ _WORD_MERC_ADD_EXP_ = {0};
const struct delayed_state DELAYED_STATE = {0xa7,0,0,0};
const struct set_state SET_STATE = {0xa8,0,0,0,0,0};
const struct end_state END_STATE = {0xa9,0,0,0};
const struct add_unit ADD_UNIT = {0xaa,0,0,0,0};
const struct npc_heal NPC_HEAL = {0xab,0,0,0};
const struct assign_npc ASSIGN_NPC = {0xac,0,0,0,0,0,0,0};
const struct warden_request WARDEN_REQUEST = {0xae,0,0};
const struct connection_info CONNECTION_INFO = {0xaf,0};
const struct game_connection_terminated GAME_CONNECTION_TERMINATED = {0xb0};
const struct ip_ban_ IP_BAN_ = {0xb3,0};
struct /*0x0*/ game_loading {
	u8	k;	// 0
}
struct /*0x1*/ game_flags {
	u8	k;	// 1
	u8	difficulty;
	u16	unknown;
	u16	hardcore;	// ?
	u8	expansion;
	u8	ladder;
}
struct /*0x2*/ load_successful {
	u8	k;	// 2
}
struct /*0x3*/ load_act {
	u8	k;	// 3
	u8	act;
	u32	map_id;
	u16	area_id;
	u32	unknown;
}
struct /*0x4*/ load_complete {
	u8	k;	// 4
}
struct /*0x5*/ unload_complete {
	u8	k;	// 5
}
struct /*0x6*/ game_exit_sucessful {
	u8	k;	// 6
}
struct /*0x7*/ map_reveal {
	u8	k;	// 7
	u16	tile_x;
	u16	tile_y;
	u8	area_id;
}
struct /*0x8*/ map_hide {
	u8	k;	// 8
	u16	tile_x;
	u16	tile_y;
	u8	area_id;
}
struct /*0x9*/ assign_lvl_warp__door_ {
	u8	k;	// 9
	u8	unit_type;
	u32	unit_id;
	u16	x;
	u16	y;
	u16	warp_id;
}
struct /*0xa*/ remove_object {
	u8	k;	// 10
	u8	unit_type;
	u32	unit_id;
}
struct /*0xb*/ game_handshake {
	u8	k;	// 11
	u8	unit_type;
	u32	unit_id;
}
struct /*0xc*/ npc_hit {
	u8	k;	// 12
	u8	unit_type;
	u32	unit_id;
	u16	animation_id;
	u8	life;
}
struct /*0xd*/ player_stop {
	u8	k;	// 13
	u8	unit_type;
	u32	unit_id;
	u8	unknown;
	u16	unit_x;
	u16	unit_y;
	u8	unknown1;
	u8	life;
}
struct /*0xe*/ object_state {
	u8	k;	// 14
	u8	unit_type;
	u32	unit_id;
	u8	unknown;	// (0x03)
	u8	unknown1;	// (0x00 = Can't Change Back || 0x01 = Can Change Back)
	u32	unit_state;
}
struct /*0xf*/ player_move {
	u8	k;	// 15
	u8	unit_type;
	u32	unit_id;
	u8	speed;	// (0x01 = Walk || 0x23 = Run || 0x20 = Knockback)
	u16	target_x;
	u16	target_y;
	u8	k1;	// 0
	u16	current_x;
	u16	current_y;
}
struct /*0x10*/ player_to_target {
	u8	k;	// 16
	u8	unit_type;
	u32	unit_id;
	u8	speed;	// (0x02 = Walk || 0x24 = Run)
	u8	target_type;
	u32	target_id;
	u16	current_x;
	u16	current_y;
}
struct /*0x11*/ report_kill {
	u8	k;	// 17
	u8	unit_type;
	u32	unit_id;
	u16	unknown;
}
// 0x12 26<Unknown>
// 0x13 14<Unknown>
// 0x14 18<Unknown>
struct /*0x15*/ reassign_player {
	u8	k;	// 21
	u8	unit_type;
	u32	unit_id;
	u16	x;
	u16	y;
	u8	do;	// (0x01 = True || 0x00 = False)
}
// 0x16 *<Unknown>
// 0x17 <Unused>
// 0x18 15<Unknown>
struct /*0x19*/ _byte_gold_to_inv_ {
	u8	k;	// 25
	u8	amount;
}
struct /*0x1a*/ _byte_add_exp_ {
	u8	k;	// 26
	u8	amount;
}
struct /*0x1b*/ _word_add_exp_ {
	u8	k;	// 27
	u16	amount;
}
struct /*0x1c*/ _dword_add_exp_ {
	u8	k;	// 28
	u32	amount;
}
struct /*0x1d*/ _byte_base_attribute {
	u8	k;	// 29
	u8	attribute;
	u8	amount;
}
struct /*0x1e*/ _word_base_attribute {
	u8	k;	// 30
	u8	attribute;
	u16	amount;
}
struct /*0x1f*/ _dword_base_attribute {
	u8	k;	// 31
	u8	attribute;
	u32	amount;
}
struct /*0x20*/ attribute_update {
	u8	k;	// 32
	u32	unit_id;
	u8	attribute;
	u32	amount;
}
struct /*0x21*/ update_item_oskill {
	u8	k;	// 33
	u16	unknown;
	u32	unit_id;
	u16	skill;
	u8	base_level;
	u8	bonus_amount;
	u8	unknown1;
}
struct /*0x22*/ update_item_skill {
	u8	k;	// 34
	u16	unknown;	// (Unit Type?)
	u32	unit_id;
	u16	skill;
	u8	amount;
	u16	unknown1;
}
struct /*0x23*/ set_skill {
	u8	k;	// 35
	u8	unit_type;
	u32	unit_id;
	u8	side;	// (0x00 = Right || Byte 0x01 = Left)
	u16	skill;
	u8	k1;	// 255
	u8	k2;	// 255
	u8	k3;	// 255
	u8	k4;	// 255
}
// 0x24 90<Unknown>
// 0x25 90<Unknown>
struct /*0x26*/ game_chat {
	u8	k;	// 38
	u16	type;	// (1 open chat, 2 recv whisper, 5 overhead, 6 sent whisper)
	u8	entitytype;	// (0x02 if not overhead)
	u32	entityid;	// 0x00 if not overhead
	u8	unknown;
	u8	chattype;	// (0x05 = Normal Chat || 0x01 = Whisper)
	u8*	char_name;
	u8	k1;	// 0
	u8*	message;
	u8	k2;	// 0
}
struct /*0x27*/ npc_info {
	u8	k;	// 39
	u8	unit_type;
	u32	unit_id;
	u8	unknown[34];
}
struct /*0x28*/ quest_info {
	u8*	researchincomplete;
}
struct /*0x29*/ game_quest_info {
	u8*	researchincomplete;
}
struct /*0x2a*/ npc_transaction {
	u8	k;	// 42
	u8	trade_type;
	u8	result;	// ? - 0x00 = Purchased || 0x01 = Sold || 0x0c = Insuffecient Gold
	u32	unknown;
	u32	merchandise_id;
	u32	gold_in;	// Inventory
}
// 0x2b <Unused>
struct /*0x2c*/ play_sound {
	u8	k;	// 44
	u8	unit_type;
	u32	unit_id;
	u16	sound;
}
// 0x2d <Unused>
// 0x2e <Unused>
// 0x2f <Unused>
// 0x30 <Unused>
// 0x31 <Unused>
// 0x32 <Unused>
// 0x33 <Unused>
// 0x34 <Unused>
// 0x35 <Unused>
// 0x36 <Unused>
// 0x37 <Unused>
// 0x38 <Unused>
// 0x39 <Unused>
// 0x3a <Unused>
// 0x3b <Unused>
// 0x3c <Unused>
// 0x3d <Unused>
struct /*0x3e*/ update_item_stats {
	u8*	researchincomplete;
}
struct /*0x3f*/ use_stackable_item {
	u8*	researchincomplete;
}
// 0x40 13<Unknown>
// 0x41 <Unused>
struct /*0x42*/ clear_cursor {
	u8	k;	// 66
	u8	unit_type;
	u32	player_id;
}
// 0x43 <Unused>
// 0x44 <Unused>
// 0x45 13<Unknown>
// 0x46 <Unused>
struct /*0x47*/ relator_1 {
	u8	k;	// 71
	u16	param;	// 1
	u32	unit_id;
	u32	param1;	// 2
}
struct /*0x48*/ relator_2 {
	u8	k;	// 72
	u16	param;	// 1
	u32	unit_id;
	u32	param1;	// 2
}
// 0x49 <Unused>
// 0x4a <Unused>
// 0x4b <Unused>
struct /*0x4c*/ unit_skill_on_target {
	u8	k;	// 76
	u8	unit_type;
	u32	unit_id;
	u16	skill;
	u8	unknown;
	u8	unknown1;
	u32	target_id;
	u8	k1;	// 0
	u8	k2;	// 0
}
struct /*0x4d*/ unit_cast_skill {
	u8	k;	// 77
	u8	unit_type;
	u32	unit_id;
	u32	skill;
	u8	unknown;
	u16	x;
	u16	y;
	u8	k1;	// 0
	u8	k2;	// 0
}
struct /*0x4e*/ merc_for_hire {
	u8	k;	// 78
	u16	merc_id;	// ?
	u32	unknown;
}
struct /*0x4f*/ start_merc_list {
	u8	k;	// 79
}
struct /*0x50*/ _______needs_research__ {

}
struct /*0x51*/ assign_object {
	u8	k;	// 81
	u8	object_type;
	u32	object_id;
	u16	object_code;
	u16	x;
	u16	y;
	u8	state;
	u8	interaction_type;
}
struct /*0x52*/ quest_log_info {
	u8*	researchincomplete;
}
struct /*0x53*/ player_slot_refresh {
	u8	k;	// 83
	u32	slot;	// #
	u8	unknown;	// 0x00 || 0x80
	u32	tickcount;	// ?
}
// 0x54 10<Unknown>
// 0x55 3<Unknown>
// 0x56 <Unused>
// 0x57 <Unused>
// 0x58 14<Unknown>
struct /*0x59*/ assign_player {
	u8	k;	// 89
	u32	unit_id;
	u8	char_type;
	u8	char_name[16];
	u16	x;
	u16	y;
}
struct /*0x5a*/ event_messages {
	u8*	researchincomplete;
}
struct /*0x5b*/ player_in_game {
	u8	k;	// 91
	u16	packet_length;
	u32	player_id;
	u8	char_type;
	u8	char_name[16];
	u16	char_lvl;
	u16	party_id;
	u8	k1;	// 0
	u8	k2;	// 0
	u8	k3;	// 0
	u8	k4;	// 0
	u8	k5;	// 0
	u8	k6;	// 0
	u8	k7;	// 0
	u8	k8;	// 0
}
struct /*0x5c*/ player_left_game {
	u8	k;	// 92
	u32	player_id;
}
struct /*0x5d*/ quest_item_state {
	u8	k;	// 93
	u8	unknown;	// (Id?)
	u32	state;	// ?
}
// 0x5e 38<Unknown>
// 0x5f 5<Unknown>
struct /*0x60*/ townportal_state {
	u8	k;	// 96
	u8	state;
	u8	area_id;
	u32	unit_id;
}
// 0x61 2<Unknown>61[BYTEUnknown]
// 0x62 7<Unknown>
struct /*0x63*/ waypoint_menu {
	u8	k;	// 99
	u32	unit_id;
	u8*	available_waypoints;
}
// 0x64 <Unused>
struct /*0x65*/ player_kill_count {
	u8	k;	// 101
	u32	player_id;
	u16	count;
}
// 0x66 7<Unknown>
struct /*0x67*/ npc_move {
	u8	k;	// 103
	u32	unit_id;
	u8	speed;	// 0x01 = Walk || 0x17 = Run
	u16	x;
	u16	y;
	u16	unknown;
	u8	unknown1;
	u16	unknown2;
	u8	unknown3;
}
struct /*0x68*/ npc_move_to_target {
	u8	k;	// 104
	u32	unit_id;
	u8	speed;	// 0x00 = Walk || 0x18 = Run
	u16	x;
	u16	y;
	u8	target_unit;	// Type
	u32	target_id;
	u16	unknown;
	u8	unknown1;
	u16	unknown2;
	u8	unknown3;
}
struct /*0x69*/ npc_state {
	u8	k;	// 105
	u32	unit_id;
	u8	state;
	u16	x;
	u16	y;
	u8	unit_life;
	u8	unknown;
}
// 0x6a 12<Unknown>
struct /*0x6b*/ npc_action {
	u8	k;	// 107
	u32	unit_id;
	u8	action;
	u8	k1;	// 0
	u8	k2;	// 0
	u8	k3;	// 0
	u8	k4;	// 0
	u8	k5;	// 0
	u8	k6;	// 0
	u16	x;
	u16	y;
}
struct /*0x6c*/ npc_attack {
	u8	k;	// 108
	u32	unit_id;
	u16	attack_type;
	u32	target_id;
	u8	target_type;
	u16	x;
	u16	y;
}
struct /*0x6d*/ npc_stop {
	u8	k;	// 109
	u32	unit_id;
	u16	x;
	u16	y;
	u8	unit_life;
}
// 0x6e 1<Unknown>6e
// 0x6f 1<Unknown>6f
// 0x70 1<Unknown>70
// 0x71 1<Unknown>71
// 0x72 1<Unknown>72
// 0x73 32<Unknown>
struct /*0x74*/ player_corpse_assign {
	u8	k;	// 116
	u8	assign;	// 0x00 = False || 0x01 True
	u32	owner_id;
	u32	corpse_id;
}
struct /*0x75*/ player_party_info {
	u8	k;	// 117
	u32	unit_id;
	u16	party_id;
	u16	char_level;
	u16	relationship;
	u16	in_your;	// Party? 0x00 = False || 0x01 = True
}
struct /*0x76*/ player_in_proximity {
	u8	k;	// 118
	u8	unit_type;
	u8	unit_id;
}
struct /*0x77*/ button_actions {
	u8	k;	// 119
	u8	action;
}
struct /*0x78*/ trade_accepted {
	u8	k;	// 120
	u8	char_name[16];
	u32	unit_id;
}
struct /*0x79*/ gold_in_trade {
	u8	k;	// 121
	u8	gold_owner;
	u32	amount;
}
struct /*0x7a*/ pet_action {
	u8	k;	// 122
	u8	event;	// 0x00 = Unsummoned/Lost Sight || 0x01 = Summoned/Assign
	u8	skill;
	u16	pet_type;
	u32	owner_id;
	u32	pet_id;
}
struct /*0x7b*/ assign_skill_hotkey {
	u8	k;	// 123
	u8	slot;
	u8	skill;
	u8	side;	// 0x00 = Right || 0x80 = Left
	u8	k1;	// 255
	u8	k2;	// 255
	u8	k3;	// 255
	u8	k4;	// 255
}
struct /*0x7c*/ use_scroll {
	u8	k;	// 124
	u8	type;
	u32	item_id;
}
struct /*0x7d*/ set_item_state {
	u8*	researchincomplete;
}
// 0x7e 5<Unknown>
struct /*0x7f*/ ally_party_info {
	u8	k;	// 127
	u8	unit_type;
	u16	unit_life;
	u32	unit_id;
	u32	unit_area;	// Id
}
// 0x80 <Unused>
struct /*0x81*/ assign_merc {
	u8	k;	// 129
	u8	unknown;
	u16	merc_kind;	// ?
	u32	owner_id;
	u32	merc_id;
	u32	unknown1;
	u32	unknown2;
}
struct /*0x82*/ portal_ownership {
	u8	k;	// 130
	u32	owner_id;
	u8	owner_name[16];
	u32	local_id;
	u32	remote_id;
}
// 0x83 <Unused>
// 0x84 <Unused>
// 0x85 <Unused>
// 0x86 <Unused>
// 0x87 <Unused>
// 0x88 <Unused>
struct /*0x89*/ special_quest_event {
	u8	k;	// 137
	u8	event_id;
}
struct /*0x8a*/ npc_wants_to_interact {
	u8	k;	// 138
	u8	unit_type;
	u32	unit_id;
}
struct /*0x8b*/ player_relationship {
	u8	k;	// 139
	u32	unit_id;
	u8	relation;	// 0x00 = No Party || 0x01 = In Party || 0x02 = Wants to Party
}
struct /*0x8c*/ relationship_update {
	u8	k;	// 140
	u32	player;	// 1 Id
	u32	player1;	// 2 Id
	u16	relation_state;
}
struct /*0x8d*/ assign_player_to_party {
	u8	k;	// 141
	u32	player_id;
	u16	party_id;
}
struct /*0x8e*/ corpse_assign {
	u8	k;	// 142
	u8	event;	// 0x00 = Unassign || 0x01 = Assign
	u32	owner_id;
	u32	corpse_id;
}
struct /*0x8f*/ pong {
	u8	k;	// 143
	u8	token[32];	// 0x00
}
struct /*0x90*/ party_automap_info {
	u8	k;	// 144
	u32	player_id;
	u32	player_x;
	u32	player_y;
}
// 0x91 26<Unknown>
// 0x92 6<Unknown>
// 0x93 8<Unknown>
struct /*0x94*/ base_skill_levels {
	u8	k;	// 148
	u8	amount_of;	// Skills
	u32	player_id;
	u16	skill;
	u8	level;
	u8*	rest_of;	// skills, Skill|Level repeating
}
struct /*0x95*/ life_and_mana_update {
	u8	k;	// 149
	u16	unit_life;
	u16	unit_mana;
	u16	unit_stamina;
	u16	x;
	u16	y;
	u16	unknown;
}
struct /*0x96*/ walk_verify {
	u8	k;	// 150
	u16	stamina;
	u16	x;
	u16	y;
	u16	state;
}
struct /*0x97*/ weapon_switch {
	u8	k;	// 151
}
// 0x98 7<Unknown>
struct /*0x99*/ skill_triggered {
	u8*	researchincomplete;
}
// 0x9a 17<Unknown>
struct /*0x9b*/ _merc_related__ {
	u8	k;	// 155
	u16	unknown;
	u32	unknown1;
}
struct /*0x9c*/ item_action__world_ {
	u8*	researchincomplete;
}
struct /*0x9d*/ item_action__owned_ {
	u8*	researchincomplete;
}
struct /*0x9e*/ _byte_merc_attribute {
	u8	k;	// 158
	u8	attribute;
	u32	merc_id;
	u8	amount;
}
struct /*0x9f*/ _word_merc_attribute {
	u8	k;	// 159
	u8	attribute;
	u32	merc_id;
	u16	amount;
}
struct /*0xa0*/ _dword_merc_attribute {
	u8	k;	// 160
	u8	attribute;
	u32	merc_id;
	u32	amount;
}
struct /*0xa1*/ _byte_merc_add_exp_ {
	u8*	researchincomplete;
}
struct /*0xa2*/ _word_merc_add_exp_ {
	u8*	researchincomplete;
}
// 0xa3 24<Unknown>
// 0xa4 3<Unknown>
// 0xa5 8<Unknown>
// 0xa6 *<Unknown>
struct /*0xa7*/ delayed_state {
	u8	k;	// 167
	u8	unit_type;
	u32	unit_id;
	u8	state;
}
struct /*0xa8*/ set_state {
	u8	k;	// 168
	u8	unit_type;
	u32	unit_id;
	u8	packet_length;
	u8	state;
	u8*	state_effects;
}
struct /*0xa9*/ end_state {
	u8	k;	// 169
	u8	unit_type;
	u32	unit_id;
	u8	state;
}
struct /*0xaa*/ add_unit {
	u8	k;	// 170
	u8	unit_type;
	u32	unit_id;
	u8	packet_length;
	u8*	state_info;
}
struct /*0xab*/ npc_heal {
	u8	k;	// 171
	u8	unit_type;
	u32	unit_id;
	u8	unit_life;
}
struct /*0xac*/ assign_npc {
	u8	k;	// 172
	u32	unit_id;
	u16	unit_code;
	u16	x;
	u16	y;
	u8	unit_life;
	u8	packet_length;
	u8*	state_info;
}
// 0xad 9<Unknown>
struct /*0xae*/ warden_request {
	u8	k;	// 174
	u16	packet_length;	// Excluding Header
	u8*	data;
}
struct /*0xaf*/ connection_info {
	u8	k;	// 175
	u8	protocolver;
}
struct /*0xb0*/ game_connection_terminated {
	u8	k;	// 176
}
// 0xb1 53<Unknown>
// 0xb2 *<Unknown>
struct /*0xb3*/ ip_ban_ {
	u8	k;	// 179
	u32	param;	// ?
}
