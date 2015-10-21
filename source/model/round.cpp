#include "round.h"
#include "../globals.h"

void Round::init(int nPlyr)
{
	state=DEAL;
	next=SBLIND_INDEX;
	rdEnd=BBLIND_INDEX;

	this->nPlyr=nInGame=nPlyr;
	vector<bool> inGame(nPlyr, true);
	this->inGame=inGame;
}

void Round::rcvAction(int seatNo, int action)
{
	switch(action)
	{
		case ACT_RAISE: case ACT_ALLIN:
			rdEnd=getPrev(seatNo); break;
		case ACT_FOLD: 
			inGame[seatNo]=false; nInGame--; break;
		case ACT_BLIND: 
			next++; return;
	}

	//int last=next;
	if(next!=rdEnd) next=getNext(next);
	else 
	{
		state++;
		next=getThis(SBLIND_INDEX); 
		rdEnd=getPrev(next);
	}
	//if(last==next) rdEnd=next, next=getNext(next);
}

int Round::getNextSeat()
{
	return next;
}



int Round::getPrev(int seatNo)
{
	int prevNo = seatNo-1>=0 ? seatNo-1 : nPlyr-1;
	while(!inGame[prevNo])
		prevNo = prevNo-1>=0 ? prevNo-1 : nPlyr-1;
	return prevNo;
}

int Round::getNext(int seatNo)
{
	int nextNo = seatNo+1<nPlyr ? seatNo+1 : 0;
	while(!inGame[nextNo])
		nextNo = nextNo+1<nPlyr ? nextNo+1 : 0;
	return nextNo;
}

int Round::getThis(int seatNo)
{
	while(!inGame[seatNo])
		seatNo = seatNo+1<nPlyr ? seatNo+1 : 0;
	return seatNo;
}





vector<bool> Round::getInGame()
{
	return inGame;
}

int Round::getNInGame()
{
	return nInGame;
}
