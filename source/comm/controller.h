#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include "mailman.h"
#include "player.h"
#include "card.h"
using namespace std;

//Controller initiates manages the whole communication process
//Controller performs the tasks by calling on the handler
//Controller only manages the order of the steps
class PlayerShell
{
public:
	Player* player;
	Mailman mailman;
public:
	void init(int ch, char* id, char* si, char* sp, char* ci, char* cp); //init
	void start();

	void writeReg();
	void readSeat(string& msg);
	void readBlind(string& msg);
	void readHold(string& msg);
	void readInquire(string msg);
	void readNotify(string& msg);
	void writeAction();
	void readFlop(string& msg);
	void readTurn(string& msg);
	void readRiver(string& msg);
	void readShowdown(string& msg);
	void readPotwin(string& msg);
	~PlayerShell();
	//void readNotify(string msg);
	//void end();
private:
	void matchWord(string& piece); //return the string after cutting word<space>
	void matchChar(string& piece); //return the string after cutting a char
	int nextInt(string& piece); //shortens the string
	string nextWord(string& piece); //delim by <space> or <colon>
	string sticky(string& message, string header);
};
#endif
