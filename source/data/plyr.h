#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream>
#include "../globals.h"
#include "../model/Round.h"
#include "../model/card.h"
#include "../model/rdstate.h"
using namespace std;

//A player archives the info retrived from handler for future reference
//A specific player base his dicision on cards, bets, nPlayers, pos and jettons
class Player
{
public:
	//reg info
	int pid;
	string name;

	//game state
	int state;		//[DEAL ~ RIVER_BET]
	int BB;			//[@? == 1BB]
	int pot;		//[@? on table]
	int mySeat;		//[SB? BB? UTG?]
	int nPlyr;		//[n(#) inGame]
	vector<Card> comm;	//[3 ~ 5]
	vector<int> seat;	//[SB# ~ DEALER#]
	vector<RdState> plyrStates;	//last round info record

	//my state
	RdState myState;
	vector<Card> hole;

	//record
	vector<vector<RdState> > rdRecords;	//[DEAL_BET ~ RIVER_BET][SB# ~ ]
	Round rd;

	//result 
	vector<Card> opHole[MAX_PLAYER];	//[#][2]
	int phand[MAX_PLAYER];
	int potsh[MAX_PLAYER];
	
	//lasting record

public:
	void init(); //clear vectors at the start of a game
	void setReg(char* pid, char* name);
	vector<string> sendReg();
	void rcvSeat(vector<PlayerInfo> players); //blind is a oppo action
	void rcvBlind(int bet);
	void rcvHole(vector<Card> hole);
	virtual Action sendBet()=0; //the way player bets differ 


	void rcvPot(int pot);
	void rcvFlop(vector<Card> flop);
	void rcvTurn(Card card);
	void rcvRiver(Card card);
	void rcvLstRound(vector<RdState> lastrd);
	void rcvOppoAct(int pid, Action act);
	void rcvPHole(int pid, Card card);
	void rcvPHand(int pid, int hand);
	void rcvPotwin(int pid, int share);
};
#endif
