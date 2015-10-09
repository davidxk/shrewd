#include "globals.h"
#include "plyrinfo.h"

PlayerInfo::PlayerInfo()
{
	jetton=0;
	money=0;
	inGame=true;
}

PlayerInfo::PlayerInfo(string pid, int jetton, int money)
{
	setPlayerInfo(pid,jetton,money);
}

void PlayerInfo::setPlayerInfo(string pid, int jetton, int money)
{
	this->pid=pid;
	this->jetton=jetton;
	this->money=money;
}

bool PlayerInfo::match(PlayerInfo* plyr)
{
	return plyr->pid==this->pid&&
		plyr->jetton==this->jetton&&
		plyr->money==this->money;
}
