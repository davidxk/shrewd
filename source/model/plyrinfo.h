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
public:
	PlayerInfo(int pid, int jetton, int money);
	bool match(PlayerInfo* plyr);
	string print();
};

#endif
