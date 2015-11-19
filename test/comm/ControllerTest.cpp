#include "comm/Controller.h"
#include <cassert>

class ControllerTest
{
public:
	int onEnter()
	{
		Controller ctrl;
		ctrl.init(0,"5555","caller","","","","");
		ctrl.start();
		return 0;
	}
};
