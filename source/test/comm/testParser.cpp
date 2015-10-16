#include <string>
#include "../../comm/parser.h"

int main()
{
	Parser psr;
	const int nTestCase=9;
	string msg[nTestCase];
	int i=0;

	msg[i]="asd-fgh/ \njkl\n/asd-fgh \nqwe/ \nrty";
	psr.matchHead(msg[i]);
	cout<<"case "<<i<<": "<<msg[i]<<endl;
	i++;

	msg[i]= "/asd-fgh \njkl";
	psr.matchTail(msg[i]);
	cout<<"case "<<i<<": "<<msg[i]<<endl;
	i++;

	msg[i]= "asd: fgh";
	psr.matchWColon(msg[i]);
	cout<<"case "<<i<<": "<<msg[i]<<endl;
	i++;

	msg[i]= "HEARTS 3 \nCLUBS K \n";
	Card card1=psr.getCard(msg[i]);
	cout<<"case "<<i<<": "<<msg[i]<<endl;
	cout<<card1.print();
	i++;

	msg[i]= "HEARTS 3 CLUBS K \n";
	psr.matchTail(msg[i]);
	Card card2=psr.getCard(msg[i]);
	cout<<"case "<<i<<": "<<msg[i]<<endl;
	cout<<card2.print();
	i++;

	msg[i]= "7777 30 250 \nsmall blind: ";
	PlayerInfo pi1=psr.getPlayerInfo(msg[i]);
	cout<<"case "<<i<<": "<<msg[i]<<endl;
	cout<<pi1.print();
	i++;

	msg[i]="7777 1900 8000 100 call";
	PlayerInfo pi2=psr.getPlayerInfo(msg[i]);
	cout<<"case "<<i<<": "<<msg[i]<<endl;
	cout<<pi2.print();
	i++;

	msg[i]= "100 call \n4444 ";
	Action action=psr.getAction(msg[i]);
	cout<<"case "<<i<<": "<<msg[i]<<endl;
	cout<<action.print();
	i++;

	msg[i]= "5555 1900 8000 100 call \n4444 2000 8000 0 fold ";
	RdState rdstate=psr.getRdState(msg[i]);
	cout<<"case "<<i<<": "<<msg[i]<<endl;
	cout<<rdstate.print();
	i++;

	return 0;
}
