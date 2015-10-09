#include <iostream>
#include <cstdlib>
#include <ctime>
#include "plyrshel.h"
using namespace std;

int main(int argc,char* argv[])
{
	PlayerShell ps;
	ps.init(PID_SNORE_PLAYER,argv[5],argv[1],argv[2],argv[3],argv[4]);
	ps.start();
	return 0;
}
