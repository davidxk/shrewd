#ifndef _HAND_H_
#define _HAND_H_
#include <iostream>
#include <vector>
using namespace std;

class Hand
{
public:
	vector<int> first;
	int rank;
public:
	Hand();
	Hand(int rank);
	string print();
	void printDetails();
	int compare(Hand* hand);
};

#endif
