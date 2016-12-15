#include "common.h"
#include "model/RdState.h"

RdState::RdState(): inBet(0) { }

RdState::RdState(PlayerInfo aPi): pi(aPi), inBet(0) { }

RdState::RdState(PlayerInfo aPi, Action aLstAct, int aInBet):
	pi(aPi), lstAct(aLstAct), inBet(aInBet) { }

string RdState::print() const
{
	string str;
	str += pi.print() + lstAct.print() + intToStr(inBet);
	str += "inBet\n";
	return str;
}
