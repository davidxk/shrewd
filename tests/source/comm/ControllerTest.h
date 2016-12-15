#ifndef _CONTROLLERTEST_H_
#define _CONTROLLERTEST_H_

#include "ai/folder.h"
#include "comm/Controller.h"
#include "comm/Mailman.h"
#include "data/plyr.h"
#include "TestCase.h"
#include <cassert>

class TestableController: public Controller
{
friend class ControllerTest;
public:
	void setMailman(Mailman* mm) { this->mailman = mm; }
	void setPlayer(Player* pl) { this->player = pl; }
};

class ControllerTest: public TestCase
{
public:
	int runTest();
};

#endif
