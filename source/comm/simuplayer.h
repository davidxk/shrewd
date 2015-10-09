#ifndef _SIMU_PLAYER_H_
#define _SIMU_PLAYER_H_
#include <cstdlib>
#include <ctime>
#include "card.h"
#include "hand.h"
#include "simu.h"

//A Simu Player make decision on every bet based on simulation
class SimuPlayer: public Simu
{
private:
	int state; //state of the game
	vector<Card> comm; //common card
	vector<Card> reco;
	vector<Card> hole; //hole card of main player
	vector<Card> seen; //all seen cards in comm and hole
	vector<Card> oppoHole; //hole card of opponents: 2*nPlayers-2
	bool mainWin;
	Hand myHand;
	vector<Hand> oppoHand;
public:
	SimuPlayer();
	void setState(int state, vector<Card> hole, vector<Card> comm);
	float simulate(int times);
	void print();
private:
	void deal(); //deal to other players: called multiple times
	bool isWin(); 
	void flop();
	void turn();
	void river();
	void dealNextUnseen(vector<Card>& vec);
};
#endif
