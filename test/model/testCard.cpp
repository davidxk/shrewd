#include "model/Card.h"
#include <cassert>

int main()
{
	Card cd=Card::getCard('S', Card::ACE);
	assert(cd.print()=="sA ");
	return 0;
}
