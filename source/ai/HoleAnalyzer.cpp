#include "HoleAnalyzer.h"

#include <unordered_map>
#include <vector>
#include "model/Card.h"

//Starting Hand Analyzer gether intel on starting hand
//Provides basic information of a given card pair
//1326 Hole: vector<Card> hole[2]
//169 SHand: "AKo"
//3 HandType: { TOP_PAIR, SPECULATIVE, POWERHOUSE }
//12 HandCtg: { MONSTERS, BIG_PAIRS, .. }
void HoleAnalyzer::loadData()
{
	//TODO: address TDB
	fstream data("win_and_tie.txt"); 
	const int maxPlayer=10;
	const int nCombination=169;

	vector<unordered_map<string,float> > winMap;
	winMap.resize(maxPlayer);
	unordered_map<string,float> wins;
	string key; float value;

	for(int i=0; i<maxPlayer; i++)
	{
		fin>>key;
		for(int j=0; j<nCombination; j++)
		{
			fin>>key>>value;
			if(key.size()==2) key+=' ';
			wins.insert( make_pair<string,float>(key, value) );
		}
		winMap[maxPlayer-i]=wins;
		wins.clear();
	}
}

string HoleAnalyzer::printSHand(vector<Card> hole)
{
	//prints as one of 169 starting hand string
	if(hole.size()!=2) return "EE Hole size not 2!";
	bool isPair=hole[0].figure==hole[1].figure;
	bool isSuited=hole[0].color==hole[1].color;
	if(hole[0].figure<hole[1].figure) swap(hole[0], hole[1]);

	string str=hole[0].print().at(1);
	str+=hole[1].print().at(1);
	if(!isPair && isSuited) str+='s';
	else if(!isSuited && !isSuited) str+='o';
	else str+=' ';
	return str;
}

float HoleAnalyzer::getWinRate(vector<Card> hole, int nPlyrs)
{
	return winMap[nPlyrs][printHole(hole)];
}
