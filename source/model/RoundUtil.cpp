#include "model/RoundUtil.h"

void RoundUtil::init(int nPlyr)
{
	state=PRE_FLOP_BET;
	next=SBLIND_INDEX;
	rdEnd=BBLIND_INDEX;

	this->nPlyr=nInGame=nPlyr;
	vector<bool> inGame(nPlyr, true);
	this->inGame=inGame;
}

void RoundUtil::rcvAction(int seatNo, Action action)
{
	switch(action.act)
	{
		case Action::ACT_RAISE: case Action::ACT_ALLIN:
			rdEnd=getPrev(seatNo); break;
		case Action::ACT_FOLD: 
			inGame[seatNo]=false; nInGame--; break;
		case Action::ACT_BLIND: 
			next++; return;
		default: break;
	}

	if(next!=rdEnd) next=getNext(next);
	else 
	{
		state++;
		next=getThis(SBLIND_INDEX); 
		rdEnd=getPrev(next);
	}
}

int RoundUtil::getNextSeat()
{
	return next;
}



int RoundUtil::getPrev(int seatNo)
{
	int prevNo = seatNo-1>=0 ? seatNo-1 : nPlyr-1;
	while(!inGame[prevNo])
		prevNo = prevNo-1>=0 ? prevNo-1 : nPlyr-1;
	return prevNo;
}

int RoundUtil::getNext(int seatNo)
{
	int nextNo = seatNo+1<nPlyr ? seatNo+1 : 0;
	while(!inGame[nextNo])
		nextNo = nextNo+1<nPlyr ? nextNo+1 : 0;
	return nextNo;
}

int RoundUtil::getThis(int seatNo)
{
	while(!inGame[seatNo])
		seatNo = seatNo+1<nPlyr ? seatNo+1 : 0;
	return seatNo;
}





int RoundUtil::getState()
{
	return state;
}

int RoundUtil::getNInGame()
{
	return nInGame;
}

vector<bool> RoundUtil::getInGame()
{
	return inGame;
}
