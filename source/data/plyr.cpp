#include "plyr.h"
#include "common.h"

//static ofstream pout;
void Player::init()
{
	//pout.open("ply.log");
	for(int i=0; i<rdRecords.size(); i++)
		rdRecords[i].clear();

	rdRecords.resize(RIVER_BET+1);
	comm.clear();
	seat.clear();
	hole.clear();
	plyrStates.clear();
	potShare.clear();

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





void Player::rcvSeat(const vector<PlayerInfo>& players)
{
	//this msg contains seat[SB# ~], plyr[@? $?], my[@? $?] and [n(#)] info
	//get seat[SB# ~] info and my [@? $?] and mySeat
	for(int i=0; i<players.size(); i++)
	{
		//start from small blind
		int wrap_i = i+1<players.size() ? i+1 : 0;
		seat.push_back(players[wrap_i].pid);
		pidToSeat.insert( make_pair<int,int>(players[wrap_i].pid, i) );

		if(players[wrap_i].pid==pid)
			myState.pi=players[wrap_i], mySeat=i;
	}

	rdu.init(players.size());
	for(int i=0; i<players.size(); i++)
		plyrStates.insert( make_pair<int,RdState>(players[i].pid,
					RdState(players[i])) );
}

void Player::rcvBlind(int bet)
{
	BB=2*bet;
}

void Player::rcvHole(const vector<Card>& hole)
{
	this->hole=hole;
	state=DEAL_BET;
}

void Player::rcvFlop(const vector<Card>& flop)
{
	this->comm=flop;
	state=FLOP_BET;
}

void Player::rcvTurn(const Card& card)
{
	comm.push_back(card);
	state=TURN_BET;
}

void Player::rcvRiver(const Card& card)
{
	comm.push_back(card);
	state=RIVER_BET;
}





void Player::rcvLstRound(const TableInfo& tableInfo)
{
	//This msg contains my[@? $?], act[#? $?], 
	const unordered_map<int, RdState> lastrd = tableInfo.lastrd;
	//reinit my state for round
	myState = lastrd.find(pid)->second;

	//append on rdRecords
	int next = rdu.getNextSeat();
	do	//run at least once
	{
		//get #next's state
		RdState rs = lastrd.find(seat[next])->second;
		//archive action
		rdu.rcvAction(next, rs.lstAct.act);
		rdRecords[rdu.getState()].push_back(rs);
		//maintain inBet attribute & current plyrStates
		rs.inBet = plyrStates.find(seat[next])->second.inBet + rs.lstAct.bet;
		plyrStates.find(seat[next])->second = rs;
		//step to next cycle
		next=rdu.getNextSeat();
	}
	while( next != mySeat );	//all until my turn(right now)
}

void Player::rcvShowdown(const unordered_map<int, ShowdownInfo>& shwdMap)
{
	this->shwdMap = shwdMap;
}

void Player::rcvPotwin(const unordered_map<int, int>& potShare)
{
	this->potShare = potShare;
}

