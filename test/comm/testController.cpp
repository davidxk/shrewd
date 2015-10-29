#include "comm/Controller.h"

int main()
{
	Controller ctrl;
	cout<<"Hello!\n";
	ctrl.init(0,"5555","caller","","","","");
	cout<<"I am here!"<<endl;
	ctrl.start();
	cout<<"Oh lala\n";
	return 0;
}
