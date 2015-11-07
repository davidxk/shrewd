#include "ai/folder.h"

FoldPlayer::FoldPlayer()
{
	pid=7000;
	name="Fold Player";
}

Action FoldPlayer::sendBet()
{
	Action act(Action::ACT_FOLD, 0);
	return act;
}
