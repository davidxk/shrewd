#include "model/Card.h"
#include "TestCase.h"
#include <cassert>

class CardTest: public TestCase
{
public:
	int runTest()
	{
		Card cd=Card::getCard('S', Card::ACE);
		assert(cd.print()=="sA ");
		return 0;
	}
};
