#include "comm/Controller.h"

int main()
{
	Controller ctrl;
	cout<<"Hello!\n";
	ctrl.init(1,"5555","folder","","","","");
	//cout<<"I am here!"<<endl;
	ctrl.start();
	//cout<<"Oh lala\n";
	return 0;
}
