#ifndef _GLOBALS_H_
#define _GLOBALS_H_

//basic
#define HAND_SIZE 5
#define HOLE_SIZE 2
#define COMM_SIZE 5
#define N_HAND 9
#define N_FLOP 3





//states for simuplayer
#define DEAL  -1
#define DEAL_BET 0
#define FLOP_BET 1
#define TURN_BET 2
#define RIVER_BET 3





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





//checkplus
#define FLUSH_THRESH 3
#define FLUSH_IMPOSS -1

//plyrinfo
#define EMPTY_PLAYER "-1"
#define MAX_PLAYER 8

//snarl
#define N_TURN 4
#define N_RIVER 5

//snow
#define N_START_HAND 169

#endif
