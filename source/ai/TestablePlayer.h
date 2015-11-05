#ifndef _DATA_TESTALBE_PLAYER_H_
#define _DATA_TESTALBE_PLAYER_H_

#include "data/plyr.h"

//description of the class here
class TestablePlayer: public Player
{
public:
	string reportGameInfo();
	string reportUpdate();
	string reportResult();
	Action sendBet();
};
#endif
