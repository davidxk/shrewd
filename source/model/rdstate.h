#ifndef _ROUND_STATE_H_
#define _ROUND_STATE_H_
#include <iostream>
#include "plyrinfo.h"
#include "action.h"
using namespace std;

class RdState
{
public:
	PlayerInfo pi;
	Action lstAct;
	int inBet;
public:
	RdState(PlayerInfo, Action, int = 0);
	string print();
};
#endif
