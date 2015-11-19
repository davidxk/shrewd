#include "model/Action.h"
#include <cassert>

class ActionTest
{
public:
	int onEnter()
	{
		Action act(Action::ACT_RAISE, 100);
		assert(act.print()=="100 raise\n");
		return 0;
	}
};
