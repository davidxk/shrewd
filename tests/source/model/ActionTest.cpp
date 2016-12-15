#include "model/Action.h"
#include "TestCase.h"
#include <cassert>

class ActionTest: public TestCase
{
public:
	int runTest()
	{
		Action act(Action::ACT_RAISE, 100);
		assert(act.print()=="100 raise\n");
		return 0;
	}
};
