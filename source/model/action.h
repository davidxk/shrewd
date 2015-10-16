#ifndef _ACTION_H_
#define _ACTION_H_
#include <iostream>
#include "../globals.h"
using namespace std;

class Action
{
public:
	int act;
	int bet;
	int state;
	Action(int act=-1, int bet=-1, int state=-1);
	string print();
};
#endif
