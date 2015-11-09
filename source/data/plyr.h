#ifndef _DATA_PLAYER_H_
#define _DATA_PLAYER_H_

#include <cstdio>
#include <fstream>

#include <iostream>
#include <unordered_map>
#include <vector>

#include "model/Card.h"
#include "model/RdState.h"
#include "model/RoundUtil.h"
#include "model/ShowdownInfo.h"
#include "model/TableInfo.h"
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
	int BB;			//[@? == 1BB]
	int mySeat;		//[SB? BB? UTG?]
	vector<Card> hole;
	vector<int> seat;	//[SB# ~ DEALER#]
	unordered_map<int, int> pidToSeat;

	//changing state
	int state;		//[DEAL ~ RIVER_BET]
	int pot;		//[@? on table]
	vector<Card> comm;	//[3 ~ 5]
	unordered_map<int, RdState> plyrStates;	//last round info record
	vector<RdState> lastRdV;
	RdState myState;

	//record
	vector<vector<RdState> > rdRecords;	//[PRE_FLOP_BET ~ RIVER_BET][SB# ~ ]
	RoundUtil rdu;

	//result 
	//vector<Card>, int hand, int potShare
	unordered_map<int, ShowdownInfo> shwdMap;	
	unordered_map<int, int> potShare;
	
	//lasting record

public:
	void init(); //clear vectors at the start of a game
	void setReg(const char* pid, const char* name);
	vector<string> sendReg();
	void rcvSeat(const vector<PlayerInfo>& players); 
	void rcvBlind(int bet);
	void rcvHole(const vector<Card>& hole);
	virtual Action sendBet()=0; //the way player bets differ 
	//virtual void reflect()=0;

	void rcvFlop(const vector<Card>& flop);
	void rcvTurn(const Card& card);
	void rcvRiver(const Card& card);
	void rcvLstRound(const TableInfo& tableInfo);
	void rcvShowdown(const unordered_map<int, ShowdownInfo>& shwdMap);
	void rcvPotwin(const unordered_map<int, int>& potShare);
private:
	unordered_map<int, RdState> initialStates;
};
#endif
