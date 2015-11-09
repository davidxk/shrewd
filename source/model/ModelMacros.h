

//states of bet rounds
enum State { DEAL=-1, PRE_FLOP_BET=0, FLOP_BET=1, TURN_BET=2, RIVER_BET=3 };
enum Seat { SBLIND_INDEX=0, BBLIND_INDEX=1, UTG_INDEX=2, DEALER_INDEX=-1 };

#define HOLE_SIZE 2
#define COMM_SIZE 5
#define HAND_SIZE 5
#define N_FLOP 3

