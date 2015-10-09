#ifndef _CHECK_PLUS_H_
#define _CHECK_PLUS_H_
#include <iostream>
#include <vector>
#include "card.h"
#include "hand.h"
using namespace std;

class FigCnt
{
public:
	int figure;
	int color;
};

class CheckerPlus
{
public:
	static Hand checkHand(vector<Card> hand);
private:
	//static int mostColor; //the most frequent color, -1 if flush impossible
	static vector<FigCnt> figCnt;
	static vector<int> commDiff;
public:
	//static void prepare(vector<Card>& hand);
	static void sort(vector<Card>& hand);
	static bool checkHighCard(vector<Card> hand, Hand& ret);
	static bool checkPair(vector<Card> hand, Hand& ret) ; //repeat
	static bool checkTwoPairs(vector<Card> hand, Hand& ret); //higher lower
	static bool checkTrip(vector<Card> hand, Hand& ret); //repeat
	static bool checkStraight(vector<Card> hand, Hand& ret); //start
	static bool checkFlush(vector<Card> hand, Hand& ret); //color leading
	static bool checkFullHouse(vector<Card> hand, Hand& ret); //trip two
	static bool checkFour(vector<Card> hand, Hand& ret); //repeat
	static bool checkStraightFlush(vector<Card> hand, Hand& ret); 
	static void findMostColor(vector<Card> handcard, int& mostColor, int& theColor);
};
#endif
