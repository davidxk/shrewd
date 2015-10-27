#ifndef _SNOW_PLAYER_H_
#define _SNOW_PLAYER_H_

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "player.h"
#include "shand.h"
#include "card.h"
using namespace std;

//A SnowPlayer base pre-flop bet on loaded data
class SnowPlayer:public Player
{
public:
	vector<StartHand> PWins[MAX_PLAYER+1];
public:
	SnowPlayer(string pid);
	Action sendBet();
public:
	float findWins();
};
#endif
