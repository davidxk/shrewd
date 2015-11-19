#include "model/PlayerInfo.h"
#include <cassert>

class PlayerInfoTest
{
public:
	int onEnter()
	{
		PlayerInfo pi(7777, 30, 250);
		assert(pi.print()=="Player #7777	@30	$250\n");
		return 0;
	}
};
