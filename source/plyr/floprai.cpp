#include "globals.h"
#include "floprai.h"

FlopRaiser::FlopRaiser(string pid)
{
}

Action FlopRaiser::sendBet()
{
	Action act;
	switch(state)
	{
		case DEAL:
		case D_BET: act=dealBet(); break;
		case FLOP:
		case F_BET: act=flopBet(); break;
		case TURN:
		case T_BET: act=dealBet(); break;
		case RIVER:
		case R_BET: act=dealBet(); break;
		default: break;
	}
	return act;
}

Action FlopRaiser::dealBet()
{
	Action act;
	act.act=ACT_CALL;
	return act;
}

Action FlopRaiser::flopBet()
{
	Action act;
	act.act=ACT_RAISE;
	act.bet=100;
	return act;
}
