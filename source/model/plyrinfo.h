#ifndef _PLAYER_INFO_H_
#define _PLAYER_INFO_H_

#include <iostream>
#include <string>
using namespace std;

class PlayerInfo
{
public:
	int pid;
	int jetton;
	int money;
	bool inGame;
public:
	PlayerInfo();
	PlayerInfo(int pid, int jetton, int money);
	void setPlayerInfo(int pid, int jetton, int money);
	bool match(PlayerInfo* plyr);
	string print();
};

#endif

