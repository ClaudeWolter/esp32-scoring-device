//Copyright (c) Piet Wauters 2022 <piet.wauters@gmail.com>
#ifndef EVENTDEFINITIONS_H
#define EVENTDEFINITIONS_H
// Typedefinition to access individual bytes of a 32 bit unsigned
union mix_t
{
    std::uint32_t theDWord;
    std::uint8_t theBytes[4];
};

// An event is represented as a 32 bit unsigned integer
// The most significant 8 bits represent the Main Type
// The least significant 24 bits represent either
// A subtype of the Main Type or
// The data corresponding to the event of Main Type

#define MAIN_TYPE_MASK  0xff000000
#define SUB_TYPE_MASK  0x00ffffff
#define DATA_24BIT_MASK  0x00ffffff
#define DATA_BYTE0_MASK  0x000000ff
#define DATA_BYTE1_MASK  0x0000ff00
#define DATA_BYTE2_MASK  0x00ff0000
#define EVENT_ALL 0xffffffff

// The next section contains all the main event types

#define EVENT_LIGHTS 0x00000000
#define EVENT_TIMER 0x01000000
#define EVENT_ROUND 0x02000000
#define EVENT_COMPETITOR_STATUS 0x03000000
#define EVENT_WEAPON 0x04000000
#define EVENT_COMPETITOR 0x05000000
#define EVENT_UI_INPUT 0x06000000
#define EVENT_UI_INPUT_SPECIAL_SETTINGS 0x07000000

#define EVENT_SCORE_LEFT 0x07000000
#define EVENT_SCORE_RIGHT 0x08000000
#define EVENT_PRIO 0x09000000
#define EVENT_YELLOW_CARD_LEFT 0x0a000000
#define EVENT_YELLOW_CARD_RIGHT 0x0b000000
#define EVENT_RED_CARD_LEFT 0x0c000000
#define EVENT_RED_CARD_RIGHT 0x0d000000
#define EVENT_BLACK_CARD_LEFT 0x0e000000
#define EVENT_BLACK_CARD_RIGHT 0x0f000000
#define EVENT_TIMER_STATE 0x10000000
#define EVENT_IDLE_100_MS 0x11000000
#define EVENT_P_CARD 0x12000000
#define EVENT_UW2F_TIMER 0x13000000
#define EVENT_TOGGLE_BUZZER 0x14000000



// Below are mask definitions to get the actual weapon from the weapon event
#define WEAPON_MASK_FOIL 0x00000001
#define WEAPON_MASK_EPEE 0x00000002
#define WEAPON_MASK_SABRE 0x00000004
#define WEAPON_MASK_UNKNOWN 0x00000008

// Below are event definitions related to User Interface (leds, displays, ... keys, remote control, ...)
// Events generated by "input" devices e.g. keys, remote control, BLYNK io, ... (input towards the state machine)
// These are subtypes, The MS Byte is always 0x06 for a UI event, the LSB determines the event SUB_TYPE_MASK
// The 'middle' bytes can be used for data

#define UI_SUB_TYPE_MASK  0x00ffffff
#define UI_DATA_MASK  0x000000ff
#define UI_INPUT_START_TIMER 0x00000001
#define UI_INPUT_STOP_TIMER 0x00000002
#define UI_INPUT_RESET 0x00000003
#define UI_INPUT_INCR_SCORE_LEFT 0x00000005
#define UI_INPUT_DECR_SCORE_LEFT 0x00000006
#define UI_INPUT_INCR_SCORE_RIGHT 0x00000007
#define UI_INPUT_DECR_SCORE_RIGHT 0x00000008
#define UI_INPUT_ROUND 0x0000000a
#define UI_INPUT_PRIO  0x00000010
#define UI_INPUT_TOGGLE_TIMER 0x00000011
#define UI_INPUT_CYCLE_WEAPON 0x00000012
#define UI_INPUT_YELLOW_CARD_LEFT 0x00000013
#define UI_INPUT_YELLOW_CARD_LEFT_DECR 0x0000ff13
#define UI_INPUT_YELLOW_CARD_RIGHT 0x00000014
#define UI_INPUT_YELLOW_CARD_RIGHT_DECR 0x0000ff14
#define UI_INPUT_RED_CARD_LEFT 0x00000015
#define UI_INPUT_RED_CARD_LEFT_DECR 0x0000ff15
#define UI_INPUT_RED_CARD_RIGHT 0x00000016
#define UI_INPUT_RED_CARD_RIGHT_DECR 0x0000ff16
#define UI_INPUT_P_CARD 0x00000017
#define UI_BUZZ 0x00000018
#define UI_MINUTE_BREAK 0x00000020
#define UI_NEXT_PERIOD 0x00000021


#define UI_INPUT_RESTORE_UW2F_TIMER 0x00000019
#define UI_SWAP_FENCERS 0x0000001a
#define UI_RESERVE_LEFT 0x0000001b
#define UI_RESERVE_RIGHT 0x0000001c

#define UI_INPUT_CYRANO_NEXT 0x00000101
#define UI_INPUT_CYRANO_PREV 0x00000102
#define UI_INPUT_CYRANO_BEGIN 0x00000103
#define UI_INPUT_CYRANO_END 0x00000104


#define UI_CYCLE_BRIGHTNESS 0x00000030

// Special settings like PisteId
#define SPECIAL_SETTING_SUBTYPE_MASK  0x00ff0000
#define SPECIAL_SETTING_DATA_MASK  0x0000ffff
#define UI_SET_PISTE_NR 0x00010000
#define UI_START_WIFI_PORTAL 0x00020000
#define UI_START_OTA_PORTAL 0x00030000
#define UI_CONNECT_TO_WIFI 0x00040000

// Below are the subtype definitions for P-Card related events
#define EVENT_NO_P_CARD 0x00000000
#define EVENT_YELLOW_P_CARD 0x00000001
#define EVENT_RED_P_CARD1 0x00000002
#define EVENT_RED_P_CARD2 0x00000003
#define EVENT_BLACK_P_CARD 0x00000004
#define EVENT_BLACK_P_CARD2 0x00000005

// Below are the subtype definitions for Timerstate related events
/*, BREAK, INJURY, ADDITIONAL_MINUTE, MATCH_ENDED,UNDEFINED
// Currently: 0 NOT running, running is everything else

#define EVENT_NO_P_CARD 0x00000000
#define FIGHTING 0x00000001
#define EVENT_RED_P_CARD1 0x00000002
#define EVENT_RED_P_CARD2 0x00000003
#define EVENT_BLACK_P_CARD 0x00000004
#define EVENT_BLACK_P_CARD2 0x00000005*/

// Machine Status: 'U' undefined; 'W' Waiting; 'H' Halted; 'F' Fencing; 'E' Ending; 'P' Paused; '5' Received NAK
#define EVENT_CYRANO_STATE 0x30000000
#define EVENT_CYRANO_STATE_U 0x30000055
#define EVENT_CYRANO_STATE_H 0x30000048
#define EVENT_CYRANO_STATE_W 0x30000057
#define EVENT_CYRANO_STATE_F 0x30000046
#define EVENT_CYRANO_STATE_P 0x30000050
#define EVENT_CYRANO_STATE_NAK 0x30000035


#endif // EVENTDEFINITIONS_H
