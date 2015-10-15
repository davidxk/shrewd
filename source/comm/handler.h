#ifndef _HANDLER_H_
#define _HANDLER_H_

#include "action.h"
#include "card.h"
#include "plyrinfo.h"
#include "rdstate.h"
#include "parser.h"

//A Handler send/rcv msg from mailman analyze it with parser 
// and passes the data it to player
//A Handler works closely with the mailman, the parser and the player
//A Handler is a private class internal to the Controller 
//View it as an assembly of private methods 
class Handler
{
	void writeReg();
	void readSeat(string& message);
	void readBlind(string& message);
	void readHold(string& message);
	void readInquire(string msg);
	void writeAction();
	void readFlop(string& msg);
	void readTurn(string& msg);
	void readRiver(string& msg);
	void readShowdown(string& msg);
	void readPotwin(string& msg);
	string sticky(string& message, string header);
};
#endif
