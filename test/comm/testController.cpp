#include "comm/Controller.h"
#include <cassert>

int main()
{
	Controller ctrl;
	ctrl.init(0,"5555","caller","","","","");
	ctrl.start();
	return 0;
}
