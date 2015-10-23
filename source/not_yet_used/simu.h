#ifndef _SIMU_H_
#define _SIMU_H_
#include <vector>
#include <cstdlib>
#include "card.h"

//Simu is the base class of all Simu-series classes
class Simu
{
public:
	vector<Card> deck; //a real deck for dealing
	int nPlayers; //num of players
	//cards are stored at both sides
public:
	void initDeck();
	void printDeck(); //for deck
	void shuffle(); 
	void setPlayers(int nPlayers); //for nPlayers
	//the dealing process varies
};
#endif
