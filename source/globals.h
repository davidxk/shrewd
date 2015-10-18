#ifndef _GLOBALS_H_
#define _GLOBALS_H_

//basic
#define N_COLOR 4
#define N_FIGURE 13
#define ACE 14
#define FIGURE_START 2
#define HAND_SIZE 5
#define HOLE_SIZE 2
#define COMM_SIZE 5
#define N_HAND 9
#define N_FLOP 3





//wins for checkplus
#define NOT_THIS_RANK -1
#define HIGHCARD 0
#define PAIR 1
#define TWOPAIRS 2
#define TRIP 3
#define STRAIGHT 4
#define FLUSH 5
#define FULLHOUSE 6
#define FOUR 7
#define STRAIGHTFLUSH 8

//states for simuplayer
#define DEAL  -1
#define DEAL_BET 0
#define FLOP_BET 1
#define TURN_BET 2
#define RIVER_BET 3

//player action
#define ACT_RAISE 0
#define ACT_CALL -1
#define ACT_CHECK -2
#define ACT_FOLD -3
#define ACT_ALLIN -4
#define ACT_BIG_BLIND -5
#define ACT_SMALL_BLIND -6
#define ACT_BLIND -7





//player
#define PID_HUMAN_PLAYER 0
#define PID_SIMU_PLAYER 1
#define PID_FOLD_PLAYER 2
#define PID_SNARE_PLAYER 3
#define PID_SNARL_PLAYER 4
#define PID_SHREWD_PLAYER 5
#define PID_SNOW_PLAYER 6
#define PID_SNORE_PLAYER 7
#define PID_FLOP_RAISER 8
#define NAME_HUMAN_PLAYER "Huaman"
#define NAME_SIMU_PLAYER "Simu"
#define NAME_FOLD_PLAYER "Folder"
#define NAME_SNARE_PLAYER "Snare"
#define NAME_SNOW_PLAYER "Snow"
#define NAME_SNORE_PLAYER "Snore"
#define NAME_FLOP_RAISER "FlopRaiser"

//action names for handler
#define STR_CHECK "check"
#define STR_CALL "call"
#define STR_RAISE "raise"
#define STR_ALLIN "all_in"
#define STR_FOLD "fold"





//checkplus
#define FLUSH_THRESH 3
#define FLUSH_IMPOSS -1
typedef enum{ CLUB, DIAMOND, HEART, SPADE }Color;

//plyrinfo
#define EMPTY_PLAYER "-1"
#define MAX_PLAYER 8

//snarl
#define N_TURN 4
#define N_RIVER 5
#define DEALER_INDEX 0
#define SBLIND_INDEX 1
#define BBLIND_INDEX 2
#define UTG_INDEX 3

//snow
#define N_START_HAND 169

#endif
