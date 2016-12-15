#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>

#include "comm/Parser.h"
#include "data/plyr.h"

#include "comm/Mailman.h"
using namespace std;

//Controller initiates manages the whole communication process
//Controller performs the tasks by calling on the parser
//Controller only manages the order of the steps
class Controller
{
protected:
	Player* player;
	Mailman* mailman;
	Parser psr;
public:
	void init(Player* ply, const char* id, const char* name, const char* si,
			const char* sp, const char* ci, const char* cp); //init
	void start();
	~Controller();
protected:
	void gameStart(string& msg);
	void mainLoop(string& msg);
	string sticky(string& message, string header);
};
#endif
