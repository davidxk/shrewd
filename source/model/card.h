#ifndef _MODEL_CARD_H_
#define _MODEL_CARD_H_

#include <iostream>
using namespace std;

class Card
{
public: 
	enum Color { CLUB=0, DIAMOND=1, HEART=2, SPADE=3 };
	static const int ACE=14, FIGURE_START=2, N_COLOR=4, N_FIGURE=13;
public:
	int figure;		//2~14
	Color color;	//Suite
public:
	Card(Color color=CLUB, int figure=2);
	bool is(Card card);
	static Card inputCard();
	static Card getCard(char color, int figure);
	string print();
};

#endif
