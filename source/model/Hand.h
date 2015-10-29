#ifndef _MODEL_HAND_H_
#define _MODEL_HAND_H_

#include <iostream>
#include <vector>
#include "globals.h"
using namespace std;

class Hand
{
public:
	vector<int> first;
	int rank;
public:
	Hand(int rank=HIGHCARD);
	string print();
	void printDetails();
	int compare(Hand* hand);
};

#endif
