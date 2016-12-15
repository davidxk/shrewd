#ifndef _MODEL_SHOWDOWN_INFO_H_
#define _MODEL_SHOWDOWN_INFO_H_

#include "model/Card.h"
#include "model/Hand.h"
#include <vector>

class ShowdownInfo
{
public:
	vector<Card> pHole;
	Hand hand;
public:
	ShowdownInfo(vector<Card> aPHole, Hand::Rank rank);
	ShowdownInfo(vector<Card> aPHole, Hand aHand);
	string print() const;
};
#endif
