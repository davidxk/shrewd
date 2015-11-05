#include <iostream>
#include "comm/Controller.h"
using namespace std;

int main(int argc,char* argv[])
{
	Controller ctrl;
	ctrl.init(PID_SNORE_PLAYER, argv[5], "shrewd_plry", 
			argv[1], argv[2], argv[3], argv[4]);
	ctrl.start();
	return 0;
}
