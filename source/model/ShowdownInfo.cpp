#include "model/ShowdownInfo.h"
#include "model/Hand.h"

ShowdownInfo::ShowdownInfo(vector<Card> aPHole, Hand::Rank rank):
	pHole(aPHole), hand(Hand(rank)) { }

ShowdownInfo::ShowdownInfo(vector<Card> aPHole, Hand aHand):
	pHole(aPHole), hand(aHand) { }

string ShowdownInfo::print()
{
	string str;
	for(int i=0; i<pHole.size(); i++)
		str+=pHole[i].print();
	Hand oHand(hand);
	str+=oHand.print();
	return str;
}
