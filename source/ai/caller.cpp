#include "globals.h"
#include "caller.h"

Action Caller::sendBet()
{
	Action act;
	act.act=ACT_CALL;
	return act;
}
