#ifndef _CARD_H_
#define _CARD_H_
#include <iostream>
#include "../globals.h"
using namespace std;

class Card
{
public:
	int figure; //2~14
	int color; //As Color
public:
	Card(int color=(int)CLUB, int figure=2);
	bool is(Card card);
	static Card inputCard();
	static Card getCard(char color, int figure);
	string print();
};

#endif
