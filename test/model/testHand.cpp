#include "model/Hand.h"
#include <cassert>

int main()
{
	Hand hand(Hand::STRAIGHTFLUSH);
	assert(hand.print()=="StFlush");
	return 0;
}
