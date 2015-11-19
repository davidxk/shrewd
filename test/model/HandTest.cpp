#include "model/Hand.h"
#include <cassert>

class HandTest
{
public:
	int onEnter()
	{
		Hand hand(Hand::STRAIGHTFLUSH);
		assert(hand.print()=="StFlush");
		return 0;
	}
};
