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
//Controller performs the tasks by calling on the parser
//Controller only manages the order of the steps
class PlayerShell
{
//friend class Parser;
public:
	Player* player;
	Mailman mailman;
public:
	void init(int ch, char* id, char* si, char* sp, char* ci, char* cp); //init
	void start();
};
#endif
