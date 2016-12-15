#include "comm/ControllerTest.h"
#include "comm/PsudoMailman.h"

int ControllerTest::runTest()
{
	TestableController ctrl;
	//ctrl.init(new FoldPlayer,"5555","folder","","","","");
	Player* ply = new FoldPlayer;
	ply->setReg("5555","folder");
	ctrl.setPlayer(ply);
	Mailman* mm = new PsudoMailman;
	mm->init("5555","folder","1.1.1.1","2.2.2.2");
	ctrl.setMailman(mm);

	ctrl.start();
	return 0;
}
