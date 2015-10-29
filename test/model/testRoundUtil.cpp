#include "model/RoundUtil.h"

int main()
{
	RoundUtil rdu;
	int seat1[]={ 0,1,2,3, 0,1,2, 0,1,2,3, 0,1, 0,1,2, 0, 0,1,2 };
	int act1[]={ -7,-7,-1,0, -1,-1,-1, -2,0,0,-3, -1,-1, 0,0,-1,-1, -2,-2,-2 };

	int seat2[]={ 0, 1, 2, 3, 0, 1, 0, 1, 2, 3, 0, 0, 3, 0, 3, 0, 3 };
	int act2[]={-7, -7, -1, -1, -1, -2, 0, -3, -3, 0, -1, -2, -2, -2, 0, 0, -3};

	int seat3[]={ 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 7, 0, 0, 1, 0 };
	int act3[]={ -7,  -7,  -1,  -3,  -3,  -3,  -3,  -1,  -1,  0,  -3,  -3,  -1, -2,  0,  -3 };

	rdu.init(4);
	for(int i=0; i<sizeof(seat1)/sizeof(int); i++)
	{
		if(rdu.getNextSeat()!=seat1[i])
			cout<<"seat expectation error: 1st test, round "<<i<<endl
				<<"Seat h"<<seat1[i]<<" act"<<act1[i]
				<<" expect"<<rdu.getNextSeat()<<endl;
		rdu.rcvAction(seat1[i], act1[i]);
		cout<<rdu.getState()<<endl;
	}

	rdu.init(4);
	for(int i=0; i<sizeof(seat2)/sizeof(int); i++)
	{
		if(rdu.getNextSeat()!=seat2[i])
			cout<<"seat expectation error: 2nd test, round "<<i<<endl
				<<"Seat h"<<seat2[i]<<" act"<<act2[i]
				<<" expect"<<rdu.getNextSeat()<<endl;
		rdu.rcvAction(seat2[i], act2[i]);
	}

	rdu.init(8);
	for(int i=0; i<sizeof(seat3)/sizeof(int); i++)
	{
		//implement the repeat action problem upon using
		if(rdu.getNextSeat()!=seat3[i]) i++;
		if(rdu.getNextSeat()!=seat3[i])
			cout<<"seat expectation error: 2nd test, round "<<i<<endl
				<<"Seat h"<<seat3[i]<<" act"<<act3[i]
				<<" expect"<<rdu.getNextSeat()<<endl;
		rdu.rcvAction(seat3[i], act3[i]);
	}

	return 0;
}
