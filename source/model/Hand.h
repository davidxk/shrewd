#ifndef _MODEL_HAND_H_
#define _MODEL_HAND_H_

#include <iostream>
#include <vector>
using namespace std;

class Hand
{
public:
	enum Rank { NOT_THIS_RANK, HIGHCARD, PAIR, TWOPAIRS, TRIP, STRAIGHT, FLUSH, FULLHOUSE, FOUR, STRAIGHTFLUSH };

public:
	vector<int> first;
	Rank rank;
public:
	Hand(Rank rank=HIGHCARD);
	string print();
	void printDetails();
	int compare(Hand* hand);
};

#endif
