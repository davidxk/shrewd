#ifndef _SNORE_PLAYER_H_
#define _SNORE_PLAYER_H_

#include "player.h"
#include "action.h"
#include "simuplayer.h"
#include <iostream>
#include <fstream>
using namespace std;

//A SnorePlayer is a experimental, enhanced ShrewdPlayer
class SnorePlayer: public Player
{
public:
	SnorePlayer(string pid);
	Action sendBet();
private:
	Action dealBet();
	Action flopBet();
	int getPoint();
	float getEE();
	int getLeastRaise();
};
#endif

