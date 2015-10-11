#ifndef _PARSER_H_
#define _PARSER_H_

#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <regex>
#include "mailman.h"
#include "player.h"
#include "card.h"
#include "plyrinfo.h"
using namespace std;

//This class translates linear message into data structure 
class Parser
{
public:
private:
	Card getCard(string& msg); //match eol or space at end
	void matchHead(string& msg);
	void matchTail(string& msg);
	void matchWColon(string& msg); //2W: = W + 2W:
	PlayerInfo getPlayerInfo(string& msg); //match eol or space at end
};
#endif
