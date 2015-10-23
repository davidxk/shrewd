#ifndef _PARSER_H_
#define _PARSER_H_

#include "scanner.h"
#include "mailman.h"
#include "../plyr/plyr.h"

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
	void readSeat(string& message);
	void readBlind(string& message);
	void readHold(string& message);
	void readInquire(string& msg);	//caution: plyrshell didn't use ref here
	void writeAction();
	void readFlop(string& msg);
	void readTurn(string& msg);
	void readRiver(string& msg);
	void readShowdown(string& msg);
	void readPotwin(string& msg);
	string sticky(string& message, string header);
};
#endif
