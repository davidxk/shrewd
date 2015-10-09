#ifndef _ROUND_STATE_H_
#define _ROUND_STATE_H_
#include <iostream>
using namespace std;

class RdState
{
public:
	string pid;
	int jetton;
	int money;
	int inBet;
	int lastAct;
	int state; //in which round is last act
public:
	RdState(string,int,int,int,int,int);
};
#endif
