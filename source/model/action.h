#ifndef _ACTION_H_
#define _ACTION_H_
#include <iostream>
using namespace std;

class Action
{
public:
	int act;
	int bet;
	int state;
	Action(int act, int bet, int state);
	string print();
};
#endif
