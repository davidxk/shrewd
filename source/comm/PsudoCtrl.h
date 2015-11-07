#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>

#include "comm/Parser.h"
#include "data/plyr.h"

#define IS_DEBUGGING 1
#define DEBUG_CONTROL
#ifndef DEBUG_CONTROL
	#include "comm/Mailman.h"
#else
	#include "comm/PsudoMailman.h"
#endif
using namespace std;

//Controller initiates manages the whole communication process
//Controller performs the tasks by calling on the parser
//Controller only manages the order of the steps
class Controller
{
public:
	Player* player;
	Mailman mailman;
	Parser psr;
public:
	void init(int ch, const char* id, const char* name, 
			const char* si, const char* sp, const char* ci, const char* cp); //init
	void start();
private:
	void gameStart(string& msg);
	void mainLoop(string& msg);
	string sticky(string& message, string header);
};
#endif
