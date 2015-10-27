#ifndef _COMM_SCANNER_H_
#define _COMM_SCANNER_H_

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <regex>

#include "model/Action.h"
#include "model/Card.h"
#include "model/RdState.h"
#include "model/PlayerInfo.h"
using namespace std;

//This class translates linear message into data structure 
class Scanner
{
public:
	void matchHead(string& msg);
	void matchTail(string& msg);
	void matchWColon(string& msg);
	Card getCard(string& msg);
	PlayerInfo getPlayerInfo(string& msg);
	Action getAction(string& msg);
	RdState getRdState(string& msg);
	int nextInt(string& msg);
	void matchChar(string& msg);
	void matchWord(string& msg);
};
#endif
