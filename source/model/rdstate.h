#ifndef _MODEL_ROUND_STATE_H_
#define _MODEL_ROUND_STATE_H_
#include <iostream>
#include "model/Action.h"
#include "model/PlayerInfo.h"
using namespace std;

class RdState
{
public:
	PlayerInfo pi;
	Action lstAct;
	int inBet;
public:
	RdState();
	RdState(PlayerInfo);
	RdState(PlayerInfo, Action, int = 0);
	string print() const;
};
#endif
