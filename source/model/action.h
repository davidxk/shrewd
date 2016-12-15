#ifndef _MODEL_ACTION_H_
#define _MODEL_ACTION_H_
#include <iostream>
using namespace std;

class Action
{
public:
	enum ACT { ACT_RAISE, ACT_CALL, ACT_CHECK, ACT_FOLD,
	   	ACT_ALLIN, ACT_BLIND };

public:
	ACT act;
	int bet;
public:
	Action(ACT act=ACT_CALL, int bet=0);
	void setBet(int bet);
	string print() const;
};
#endif
