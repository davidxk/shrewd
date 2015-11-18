#include "model/Action.h"

#include <cassert>
#include "globals.h"

int main()
{
	Action act(Action::ACT_RAISE, 100);
	assert(act.print()=="100 raise\n");
	return 0;
}
