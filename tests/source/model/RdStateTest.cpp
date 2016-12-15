#include "model/RdState.h"
#include "TestCase.h"
#include <cassert>

class RdStateTest: public TestCase
{
	int runTest()
	{
		RdState rs(PlayerInfo(7777, 30, 250), Action(Action::ACT_RAISE, 100), 0);
		assert(rs.print()=="Player #7777\t@30\t$250\n100 raise\n0inBet\n");
		return 0;
	}
};
