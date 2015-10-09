#ifndef _PLAYER_INFO_H_
#define _PLAYER_INFO_H_

#include <iostream>
#include <string>
using namespace std;

class PlayerInfo;
class PlayerInfo
{
public:
	string pid;
	int jetton;
	int money;
	bool inGame;
public:
	PlayerInfo();
	PlayerInfo(string pid, int jetton, int money);
	void setPlayerInfo(string pid, int jetton, int money);
	bool match(PlayerInfo* plyr);
};

#endif

