#include "player.h"
#include "../common.h"

//static ofstream pout;
void Player::init()
{
	//pout.open("ply.log");
	for(int i=0; i<MAX_PLAYER; i++)
	{
		opHole[i].clear();
		phand[i]=NOT_THIS_RANK;
		potsh[i]=-1;
	}
	for(int i=0; i<lastrd.size(); i++)
		rdRecords[i].clear();

	rdRecords.resize(RIVER_BET+1);
	comm.clear();
	seat.clear();
	hole.clear();

	state=DEAL;
}

void Player::setReg(char* pid, char* name)
{
	sscanf(pid, "%d", &(this->pid));
	this->name.assign(name);
}

vector<string> Player::sendReg()
{
	vector<string> reg;
	reg.push_back(intToStr(pid));
	reg.push_back(name);
	return reg;
}





void Player::rcvSeat(vector<PlayerInfo> players)
{
	//this msg contains [SB# ~], [@? $?] and [n(#)] info
	//get [SB# ~] info and my [@ $]
	for(int i=0; i<players.size(); i++)
	{
		//start from small blind
		int wrap_i = i+1<players.size() ? i+1 : 0;
		seat.push_back(players[wrap_i].pi.pid);
		if(players[wrap_i].pid==pid)
			myState.pi=players[wrap_i];
	}

	nPlyr=players.size();
	startStates=players;
}

void Player::rcvBlind(int pid, int bet)
{
	BB=2*bet;
}

void Player::rcvHole(vector<Card> hole)
{
	this->hole=hole;
	state=DEAL_BET;
}

void Player::rcvPot(int pot)
{
	this->pot=pot;
}

void Player::rcvFlop(vector<Card> flop)
{
	this->comm=flop;
	state=FLOP_BET;
}

void Player::rcvTurn(Card card)
{
	comm.push_back(card);
	state=TURN_BET;
}

void Player::rcvRiver(Card card)
{
	comm.push_back(card);
	state=RIVER_BET;
}





void Player::rcvLstRound(vector<RdState> lastrd)
{
	//start from here
	//reinit my state for round
	if(lastrd.size()>0 && lastrd[lastrd.size()-1].pi.pid==pid)
		myState=lastrd[i];

	for(int i=lastrd.size()-1; i>=0; i--)
		if(!newRd)
			rdRecords[state].push_back(lastrd);

		else
		{
			if(compareSeat(lastrd[i].pi.pid, rdEndPid)==_B_A_)
				rdRecords[state].push_back(lastrd);
			else
				rdRecords[state-1].push_back(lastrd);
		}
}

void Player::rcvOppoAct(int pid, Action act)
{
}

void Player::rcvPHole(int pid, Card card)
{
	opHole[ findSeat(pid) ].push_back(card);
}

void Player::rcvPHand(int pid, int hand)
{
	phand[ findSeat(pid) ]=hand;
}

void Player::rcvPotwin(int pid, int share)
{
	potsh[ findSeat(pid) ]=share;
}





int Player::findSeat(int pid)
{
	for(int i=0; i<seat.size(); i++)
		if(pid==seat[i])
			return i;
	cout<<"pid not found in seat info"<<endl;
	return -1;
}
