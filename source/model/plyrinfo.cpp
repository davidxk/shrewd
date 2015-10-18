#include "../globals.h"
#include "plyrinfo.h"

PlayerInfo::PlayerInfo()
{
	pid=-1;
	jetton=0;
	money=0;
	inGame=true;
}

PlayerInfo::PlayerInfo(int pid, int jetton, int money)
{
	setPlayerInfo(pid,jetton,money);
}

void PlayerInfo::setPlayerInfo(int pid, int jetton, int money)
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

string PlayerInfo::print()
{
	char pid_ch[20], jet_ch[20], mon_ch[20];
	sprintf(pid_ch, "%d", pid);
	sprintf(jet_ch, "%d", jetton);
	sprintf(mon_ch, "%d", money);

	string str="Player #"; str += pid_ch;
	str += "\t@"; str += jet_ch;
	str += "\t$"; str += mon_ch;
	str += inGame ? "\tinGame\n" : "\tFold\n";
	return str;
}
