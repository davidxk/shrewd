#ifndef _SCANNER_H_
#define _SCANNER_H_

#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <regex>
#include "../model/card.h"
#include "../model/plyrinfo.h"
#include "../model/rdstate.h"
#include "../model/action.h"
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
