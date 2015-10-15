#include "action.h"

Action::Action(int act, int bet, int state)
{
	this->act=act;
	this->bet=bet;
	this->state=state;
}

string Action::print()
{
	string str;
	char bet_ch[20], sta_ch[20];
	sprintf(bet_ch, "%d", bet);
	sprintf(sta_ch, "%d", state);
	str += string(bet_ch);
	switch(act)
	{
		case ACT_RAISE: str+=" raise\n"; break;
		case ACT_CALL: str+=" call\n"; break;
		case ACT_CHECK: str+=" check\n"; break;
		case ACT_FOLD: str+=" fold\n"; break;
		case ACT_ALLIN: str+=" allIn\n"; break;
		case ACT_BLIND: str+=" blind\n"; break;
		default: str+=" error\n";
	}
	return str;
}
