#include "rdstate.h"
#include "../common.h"

RdState::RdState(PlayerInfo aPi, Action aLstAct, int aInBet, int aState):
	pi(aPi), lstAct(aLstAct), inBet(aInBet), state(aState) { }

string RdState::print()
{
	string str;
	str += pi.print() + lstAct.print() + intToStr(inBet);
	str += "inBet @state";
	str += intToStr(state) + "\n";
	return str;
}
