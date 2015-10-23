#include "../globals.h"
#include "folder.h"

FoldPlayer::FoldPlayer()
{
	pid=PID_FOLD_PLAYER;
	name=NAME_FOLD_PLAYER;
}

Action FoldPlayer::sendBet()
{
	Action act(ACT_FOLD, 0);
	return act;
}
