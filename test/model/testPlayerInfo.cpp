#include "model/PlayerInfo.h"
#include <cassert>

int main()
{
	PlayerInfo pi(7777, 30, 250);
	assert(pi.print()=="Player #7777	@30	$250\n");
	return 0;
}
