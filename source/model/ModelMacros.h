
namespace texas_holdem{

//states of bet rounds
enum State { DEAL=-1, PRE_FLOP_BET=0, FLOP_BET=1, TURN_BET=2, RIVER_BET=3 };
enum Seat { SBLIND_INDEX=0, BBLIND_INDEX=1, UTG_INDEX=2, UTG_1_INDEX=3,
	UTG_2_INDEX=4, MID_1_INDEX=5, MID_2_INDEX=6, 
	HIJACL_INDEX=7, CUTOFF_INDEX=8, DEALER_INDEX=-1, };

//basic constants
const int HOLE_SIZE=2;
const int COMM_SIZE=5;
const int HAND_SIZE=5;
const int N_FLOP=3;

}
