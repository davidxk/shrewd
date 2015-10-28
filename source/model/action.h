#ifndef _MODEL_ACTION_H_
#define _MODEL_ACTION_H_
#include <iostream>
using namespace std;

class Action
{
public:
	int act;
	int bet;
	Action(int act=-1, int bet=0);
	string print();
};
#endif
