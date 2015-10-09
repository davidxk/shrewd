#include "globals.h"
#include "folder.h"

FoldPlayer::FoldPlayer()
{
	pid=PID_FOLD_PLAYER;
	name=NAME_FOLD_PLAYER;
}

Action FoldPlayer::sendBet()
{
	Action act;
	act.act=ACT_FOLD;
	return act;
}
