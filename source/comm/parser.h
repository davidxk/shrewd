#ifndef _PARSER_H_
#define _PARSER_H_

#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <regex>
#include "card.h"
#include "plyrinfo.h"
#include "rdstate.h"
#include "action.h"
using namespace std;

//This class translates linear message into data structure 
class Parser
{
public:
	void matchHead(string& msg);
	void matchTail(string& msg);
	void matchWColon(string& msg);
	Card getCard(string& msg);
	PlayerInfo getPlayerInfo(string& msg);
	RdState getRdState(string& msg);
	Action getAction(string& msg);
	int nextInt(string& msg);
	void matchChar(string& msg);
	void matchWord(string& msg);
};
#endif
