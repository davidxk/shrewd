#ifndef _COMM_PARSER_H_
#define _COMM_PARSER_H_

#include <unordered_map>
#include <vector>

#include "comm/Mailman.h"
#include "comm/Scanner.h"
#include "data/plyr.h"
#include "model/Card.h"
#include "model/PlayerInfo.h"
#include "model/ShowdownInfo.h"
#include "model/TableInfo.h"

//A Parser analyzes message it with parser and passes the data it to player
//A Parser works closely with the mailman, the scanner and the player
//A Parser is a private class internal to the Controller 
//View it as an assembly of private methods 
class Parser
{
public:
	Scanner scan;
public:
	string writeReg(const vector<string>& regInfo);
	vector<PlayerInfo> readSeat(string& message);
	int readBlind(string& message);
	vector<Card> readHold(string& message);
	TableInfo readInquire(string& msg);
	string writeAction(const Action& action);

	vector<Card> readFlop(string& msg);
	Card readTurn(string& msg);
	Card readRiver(string& msg);
	unordered_map<int, ShowdownInfo> readShowdown(string& msg);
	unordered_map<int, int> readPotwin(string& message);
};
#endif
