#include "card.h"

Card::Card(int aColor, int aFigure):
	color(aColor), figure(aFigure) { }

bool Card::is(Card card)
{
	return card.figure==this->figure&&card.color==this->color;
}

Card Card::inputCard()
{
	char color;
	int figure;
	cin>>color>>figure;
	return getCard(color,figure);
}

Card Card::getCard(char color, int figure)
{
	Card card;
	card.figure=figure;
	switch(color)
	{
		case 's': case 'S': 
			card.color=(int)SPADE; break;
		case 'h': case 'H':
			card.color=(int)HEART; break;
		case 'd': case 'D':
			card.color=(int)DIAMOND; break;
		case 'c': case 'C':
			card.color=(int)CLUB; break;
		default:
			cout<<"Error: Invalid color: "<<color<<endl;
	}
	return card;
}

string Card::print()
{
	string str;
	switch(color)
	{
		case SPADE: str+='s'; break;
		case HEART: str+='h'; break;
		case DIAMOND: str+='d'; break;
		case CLUB: str+='c'; break;
		default: str+='e'; break;
	}
	if(figure<10&&figure>1)str+=(char)(figure+'0');
	else
		switch(figure)
		{
			case 10: str+='T'; break;
			case 11: str+='J'; break;
			case 12: str+='Q'; break;
			case 13: str+='K'; break;
			case 14: str+='A'; break;
			default: str+='E'; break;
		}
	str+=" ";
	return str;
}
