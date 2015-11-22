#include "model/PlayerInfo.h"
#include "TestCase.h"
#include <cassert>

class PlayerInfoTest: public TestCase
{
public:
	int runTest()
	{
		PlayerInfo pi(7777, 30, 250);
		assert(pi.print()=="Player #7777	@30	$250\n");
		return 0;
	}
};
