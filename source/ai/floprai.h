#ifndef _FLOP_RAISER_H_
#define _FLOP_RAISER_H_

#include "player.h"
#include "action.h"

//A FlopRaiser calls at preflop and raises at flop-bet
class FlopRaiser: public Player
{
public:
	FlopRaiser(string pid);
	Action sendBet(); 
private:
	Action dealBet();
	Action flopBet();
};
#endif

