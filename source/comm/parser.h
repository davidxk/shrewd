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
	Player* player;
	Mailman* mailman;
	Scanner scan;
public:
	Parser(Player*, Mailman*);
	void writeReg();
	vector<PlayerInfo> readSeat(string& message)
	int Parser::readBlind(string& message)
	vector<Card> Parser::readHold(string& message)
	TableInfo Parser::readInquire(string& msg, int&)
	void writeAction();

	vector<Card> Parser::readFlop(string& msg)
	Card Parser::readTurn(string& msg)
	Card Parser::readRiver(string& msg)
	unordered_map<int, ShowdownInfo> Parser::readShowdown(string& msg)
	unordered_map<int, int> Parser::readPotwin(string& message)
	string sticky(string& message, string header);
};
#endif
