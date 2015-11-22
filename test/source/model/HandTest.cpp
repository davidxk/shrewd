#include "model/Hand.h"
#include "TestCase.h"
#include <cassert>

class HandTest: public TestCase
{
public:
	int runTest()
	{
		Hand hand(Hand::STRAIGHTFLUSH);
		assert(hand.print()=="StFlush");
		return 0;
	}
};
