#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "../globals.h"
#include "../model/card.h"
#include "../model/plyrinfo.h"
#include "../model/rdstate.h"
#include "../model/action.h"
using namespace std;

//A player reads the bet of others and bets
//A player base his dicision on cards, bets, nPlayers, pos and jettons
//A player is the core of intelligence of the AI system 
//all players must inherit this base class
class Player
{
public:
	//reg info
	int type;
	int pid;
	string name;
	//game state
	int state;
	int bigBlind;
	int pot;
	int cntRd;
	string SBlindId;
	//Cards
	vector<Card> hole;
	vector<Card> comm;
	vector<Card> opHole[MAX_PLAYER];
	vector<int> shareOfPot;
	int phand[MAX_PLAYER];
	int potsh[MAX_PLAYER];
	//my state
	int jetton;
	int money;
	int inBet;
	int lstRdBet;
	int lstRdJet;
	bool tmp;
	int lastNotify;

	vector<Action> action[MAX_PLAYER];
	vector<PlayerInfo> pstate;
	vector<RdState> lastrd;
public:
	void init(); //clear vectors at the start of a game
	void setReg(char* pid, char* name);
	vector<string> sendReg();
	void rcvSeat(vector<PlayerInfo> players); //blind is a oppo action
	void rcvHole(vector<Card> hole);
	virtual Action sendBet()=0; //the way player bets differ 
	void rcvPot(int pot);
	void rcvFlop(vector<Card> flop); //start set state=flop, end state++
	void rcvTurn(Card card);
	void rcvRiver(Card card);
	void rcvLstRound(vector<RdState> lastrd);
	void rcvOppoAct(int pid, Action act);
	void rcvPHole(int pid, Card card);
	void rcvPHand(int pid, int hand);
	void rcvPotwin(int pid, int share);
	bool isAfterSB(int thePid);
	bool isThisRd(int pid);
	int getLeastBuyin();
	int getStartJetton();
	int getInPlayers();
	float getPotOdds();
	//void rcvGameover();
	int findIndex(int pid);
	virtual void reflect();
	virtual ~Player();
};

#endif
