#include "rdstate.h"
#include "../common.h"

RdState::RdState(PlayerInfo aPi, Action aLstAct, int aInBet):
	pi(aPi), lstAct(aLstAct), inBet(aInBet) { }

string RdState::print()
{
	string str;
	str += pi.print() + lstAct.print() + intToStr(inBet);
	str += "inBet\n";
	return str;
}
