#ifndef _SNRAL_PLAYER_H_
#define _SNRAL_PLAYER_H_

#include "player.h"
#include "action.h"
#include "simuplayer.h"
#include <iostream>
#include <fstream>
using namespace std;

//A SnarlPlayer is a rational player 
class SnarlPlayer: public Player
{
public:
	SnarlPlayer(string pid);
	Action sendBet();
	virtual void reflect();
public:
	bool firstTime;
	float playerBluff[MAX_PLAYER];
	float playerWin[MAX_PLAYER];
	int cntRaise[MAX_PLAYER];
	string indexOf[MAX_PLAYER];
private:
	Action dealBet();
	Action flopBet();
	int getPoint();
	int cntPlayers(int iPlayer, int jAction);
	int findPerPl(string pid);
	SimuPlayer sp;
};
#endif
