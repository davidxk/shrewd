#ifndef _MODEL_SHOWDOWN_INFO_H_
#define _MODEL_SHOWDOWN_INFO_H_

#include "model/Card.h"
#include <vector>

class ShowdownInfo
{
public:
	vector<Card> pHole;
	int hand;
public:
	ShowdownInfo(vector<Card> aPHole, int aHand);
	string print();
};
#endif
