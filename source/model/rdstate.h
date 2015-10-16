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
	int state; //in which round is last act
public:
	RdState(PlayerInfo, Action, int = -1, int = -1);
	string print();
};
#endif
