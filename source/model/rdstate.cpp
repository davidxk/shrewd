#include "rdstate.h"

RdState::RdState(string pid, int jetton, int money, int inBet, int lastAct, int state)
{
	this->pid=pid;
	this->jetton=jetton;
	this->money=money;
	this->inBet=inBet;
	this->lastAct=lastAct;
	this->state=state;
}
