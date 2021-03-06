#include "common.h"
#include "model/PlayerInfo.h"

PlayerInfo::PlayerInfo(): pid(0), jetton(0), money(0) { }

PlayerInfo::PlayerInfo(int aPid, int aJetton, int aMoney):
	pid(aPid), jetton(aJetton), money(aMoney) { }

bool PlayerInfo::match(PlayerInfo* plyr)
{
	return plyr->pid==this->pid&&
		plyr->jetton==this->jetton&&
		plyr->money==this->money;
}

string PlayerInfo::print() const
{
	string str="Player #"; 
	str += intToStr(pid) + "\t@";
	str += intToStr(jetton) + "\t$";
	str += intToStr(money) + "\n";
	return str;
}
