#ifndef _AI_HOLE_ANALYZER_H_
#define _AI_HOLE_ANALYZER_H_

#include <unordered_map>
#include <vector>
#include "model/Card.h"

//Starting Hand Analyzer gether intel on starting hand
//Provides basic information of a given card pair
//1326 Hole: vector<Card> hole[2]
//169 sHand: "AKo"
//3 HandType: { TOP_PAIR, SPECULATIVE, POWERHOUSE, NON_PROFITABLE }
//12 HandCtg: { MONSTERS, BIG_PAIRS, .. }
class HoleAnalyzer
{
public:
	enum HandType { TOP_PAIR, SPECULATIVE, POWERHOUSE, NON_PROFITABLE };
	enum HandCtg { MONSTERS, BIG_PAIRS, MID_PAIRS, SMA_PAIRS, BIG_SU_BRDWY, 
		LTL_SU_BRDWY, SUITED_ACES, SUITED_KINGS, SUITED_CONN, BIG_OFF_BRDWY, 
		LTL_OFF_BRDWY, JUNK_HAND, NOT_THIS_HOLE };
public:
	vector<unordered_map<string,float> > winMap;	//winMap[2~10]["sHand"]

	void loadData();
	string printSHand(vector<Card> hole);
	float getWinRate(vector<Card> hole, int nPlyrs);
	HandType getHandType(vector<Card> hole);
	HandCtg getHandCtg(vector<Card> hole);
};
#endif
