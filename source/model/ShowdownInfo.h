#ifndef _MODEL_SHOWDOWN_INFO_H_
#define _MODEL_SHOWDOWN_INFO_H_

#include "model/Card.h"

class ShowdownInfo
{
public:
	vector<Card> pHole;
	int hand;

	ShowdownInfo(vector<Card> aPHole, int aHand);
};
#endif
