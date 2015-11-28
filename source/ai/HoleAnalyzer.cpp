#include "ai/HoleAnalyzer.h"

#include <fstream>
#include "model/ModelMacros.h"

HoleAnalyzer::HoleAnalyzer()
{
	loadData();
}

void HoleAnalyzer::loadData()
{
	//until I find a better way to address the path
	std::ifstream data("../libs/win_and_tie.txt"); 
	if(data.bad()) cout<<"Error: data-loading failed! \n";

	const int maxPlayer=10;
	const int minPlayer=2;
	const int nCombination=169;

	winMap.resize(maxPlayer+1);
	unordered_map<string, float> wins;
	string key; float value;

	for(int i=maxPlayer; i>=minPlayer; i--)
	{
		data>>key;
		for(int j=0; j<nCombination; j++)
		{
			data>>key>>value;
			if(key.size()==2) key+=' ';
			wins.insert( make_pair<string, float>(key, value) );
		}
		winMap[i]=wins;
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

	string str;
	str+=hole[0].print().at(1);
	str+=hole[1].print().at(1);
	if(isPair) str+=' ';
	else if(isSuited) str+='s';
	else str+='o';

	return str;
}

float HoleAnalyzer::getWinRate(vector<Card> hole, int nPlyrs)
{
	return winMap[nPlyrs][printSHand(hole)];
}

HoleAnalyzer::HandType HoleAnalyzer::getHandType(vector<Card> hole)
{
	//SSHE standard of typical hands with clear strategies
	switch(getHandCtgr(hole))
	{
		case BIG_OFF_BRDWY:
			return TOP_PAIR;
		case SMA_PAIRS:		case SUITED_CONN:	
			return SPECULATIVE;
		case MONSTERS:		case BIG_SU_BRDWY:	
			return POWERHOUSE;
		default:
			return NOT_TYPICAL;
	}
}

HoleAnalyzer::HandCtgr HoleAnalyzer::getHandCtgr(vector<Card> hole)
{
	//SSHE standard, with no regard to number of players
	if(hole.size() != texas_holdem::HOLE_SIZE) 
	{
		cout<<"Hole size less than two."<<endl;
		return NOT_THIS_HOLE;
	}

	int& fig0=hole[0].figure, &fig1=hole[1].figure;
	if( fig0 < fig1 ) swap( fig0, fig1 );
	bool suited=hole[0].color==hole[1].color;
	bool isPair=hole[0].figure==hole[1].figure;
	if(isPair)
	{
		switch(fig0)
		{
			case Card::ACE: case Card::KING:
				return MONSTERS;
			case Card::QUEEN: case Card::JACK: case Card::TEN:
				return BIG_PAIRS;
			case 9: case 8: case 7:
				return MID_PAIRS;
			case 6: case 5: case 4: case 3: case 2:
				return SMA_PAIRS;
			default: return NOT_THIS_HOLE;
		}
	}
	else if(suited)
	{
		if( fig0+fig1 >= Card::KING + Card::JACK )
			return BIG_SU_BRDWY;
		else if(fig0+fig1 >= Card::JACK+Card::TEN && fig1 >= Card::TEN)
			return LTL_SU_BRDWY;
		else if(fig0==Card::ACE) return SUITED_ACES;
		else if(fig0==Card::KING) return SUITED_KINGS;
		else 
		{
			switch(fig0-fig1)
			{
				case 1: if(fig0>=5) return SUITED_CONN;
				case 2: if(fig0>=6) return SUITED_CONN;
				case 3: if(fig0>=9) return SUITED_CONN;
				case 4: if(fig0>=Card::QUEEN) return SUITED_CONN;
				case 5: if(fig0>=Card::JACK) return SUITED_CONN;
			}
		}
	}
	else
	{
		if(fig0+fig1 >= Card::KING+Card::QUEEN) return BIG_OFF_BRDWY;
		else if(fig1 >= Card::TEN) return LTL_OFF_BRDWY;
	}
	return JUNK_HAND;
}
