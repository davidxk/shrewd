#ifndef _SNARE_PLAYER_H_
#define _SNARE_PLAYER_H_

#include "player.h"
#include "action.h"
#include "simuplayer.h"
#include <iostream>
#include <fstream>
using namespace std;

//A SnarePlayer is a timid player with little experience
class SnarePlayer: public Player
{
public:
	SnarePlayer(string pid);
	Action sendBet();
private:
	Action dealBet();
	Action flopBet();
	int getPoint();
	float getEE();
	SimuPlayer sp;
};
#endif
