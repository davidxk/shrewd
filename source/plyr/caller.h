#ifndef _CALLER_H_
#define _CALLER_H_

#include "player.h"
#include "action.h"
class Caller: public Player
{
public:
	Action sendBet();
};
#endif
