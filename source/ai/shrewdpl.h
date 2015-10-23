#ifndef _SHREWD_PLAYER_H_
#define _SHREWD_PLAYER_H_

#include "player.h"
#include "action.h"
#include "simuplayer.h"
#include <iostream>
#include <fstream>
using namespace std;

//A ShrewdPlayer is a shrewd cunning player
class ShrewdPlayer: public Player
{
public:
	ShrewdPlayer(string pid);
	Action sendBet();
private:
	Action dealBet();
	Action flopBet();
	int getPoint();
	float getEE();
	int getLeastRaise();
};
#endif
