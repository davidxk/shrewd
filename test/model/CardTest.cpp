#include "model/Card.h"
#include <cassert>

class CardTest
{
public:
	int onEnter()
	{
		Card cd=Card::getCard('S', Card::ACE);
		assert(cd.print()=="sA ");
		return 0;
	}
};
