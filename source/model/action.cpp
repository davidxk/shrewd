#include "common.h"
#include "model/Action.h"

Action::Action(ACT aAct, int aBet):
	act(aAct), bet(aBet) { }

void Action::setBet(int bet)
{
	this->act=ACT_RAISE;
	this->bet=bet;
}

string Action::print() const
{
	string str = intToStr(bet);
	switch(act)
	{
		case ACT_RAISE: str += " raise\n"; break;
		case ACT_CALL:  str += " call\n"; break;
		case ACT_CHECK: str += " check\n"; break;
		case ACT_FOLD:  str += " fold\n"; break;
		case ACT_ALLIN: str += " allIn\n"; break;
		case ACT_BLIND: str += " blind\n"; break;
		default: str += " error\n";
	}
	return str;
}
