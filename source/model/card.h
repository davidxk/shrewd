#ifndef _MODEL_CARD_H_
#define _MODEL_CARD_H_

#include <iostream>
using namespace std;

class Card
{
public: 
	enum Color { CLUB=0, DIAMOND=1, HEART=2, SPADE=3 };
	static const int ACE=14, KING=13, QUEEN=12, JACK=11, TEN=10;
	static const int FIGURE_START=2, N_COLOR=4, N_FIGURE=13;
public:
	Color color;	//Suite
	int figure;		//2~14
public:
	Card(Color color=CLUB, int figure=2);
	bool is(Card card);
	static Card inputCard();
	static Card getCard(char color, int figure);
	string print() const;
};

#endif
