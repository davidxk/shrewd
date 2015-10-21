#include "../../model/round.h"

int main()
{
	Round rd;
	rd.init(4);
	int pid1[]={ 0,1,2,3, 0,1,2, 0,1,2,3, 0,1, 0,1,2, 0, 0,1,2 };
	int act1[]={ -7,-7,-1,0, -1,-1,-1, -2,0,0,-3, -1,-1, 0,0,-1,-1, -2,-2,-2 };

	int pid2[]={ 0, 1, 2, 3, 0, 1, 0, 1, 2, 3, 0, 0, 3, 0, 3, 0, 3 };
	int act2[]={-7, -7, -1, -1, -1, -2, 0, -3, -3, 0, -1, -2, -2, -2, 0, 0, -3};

	for(int i=0; i<sizeof(pid1)/sizeof(int); i++)
	{
		if(rd.getNextSeat()!=pid1[i])
			cout<<"pid expectation error: 1st test, round "<<i<<endl
				<<"Seat h"<<pid1[i]<<" act"<<act1[i]
				<<" expect"<<rd.getNextSeat()<<endl;
		rd.rcvAction(pid1[i], act1[i]);
	}

	rd.init(4);
	for(int i=0; i<sizeof(pid2)/sizeof(int); i++)
	{
		if(rd.getNextSeat()!=pid2[i])
			cout<<"pid expectation error: 2nd test, round "<<i<<endl
				<<"Seat h"<<pid2[i]<<" act"<<act2[i]
				<<" expect"<<rd.getNextSeat()<<endl;
		rd.rcvAction(pid2[i], act2[i]);
	}

	return 0;
}
