#ifndef _ACTION_H_
#define _ACTION_H_
#include <iostream>
using namespace std;

class Action
{
public:
	int act;
	int bet;
	Action(int act, int bet=0);
	string print();
};
#endif
