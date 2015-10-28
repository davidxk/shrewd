#ifndef _MODEL_PLAYER_INFO_H_
#define _MODEL_PLAYER_INFO_H_

#include <iostream>
#include <string>
using namespace std;

class PlayerInfo
{
public:
	int pid;
	int jetton;
	int money;
public:
	PlayerInfo();
	PlayerInfo(int pid, int jetton, int money);
	bool match(PlayerInfo* plyr);
	string print();
};

#endif
