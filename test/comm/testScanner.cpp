#include <string>
#include "../../comm/scanner.h"

int main()
{
	Scanner scan;
	const int nTestCase=9;
	string msg[nTestCase];
	int i=0;

	msg[i]="asd-fgh/ \njkl\n/asd-fgh \nqwe/ \nrty";
	scan.matchHead(msg[i]);
	cout<<"case "<<i<<": "<<msg[i]<<endl;
	i++;

	msg[i]= "/asd-fgh \njkl";
	scan.matchTail(msg[i]);
	cout<<"case "<<i<<": "<<msg[i]<<endl;
	i++;

	msg[i]= "asd: fgh";
	scan.matchWColon(msg[i]);
	cout<<"case "<<i<<": "<<msg[i]<<endl;
	i++;

	msg[i]= "HEARTS 3 \nCLUBS K \n";
	Card card1=scan.getCard(msg[i]);
	cout<<"case "<<i<<": "<<msg[i]<<endl;
	cout<<card1.print();
	i++;

	msg[i]= "HEARTS 3 CLUBS K \n";
	scan.matchTail(msg[i]);
	Card card2=scan.getCard(msg[i]);
	cout<<"case "<<i<<": "<<msg[i]<<endl;
	cout<<card2.print();
	i++;

	msg[i]= "7777 30 250 \nsmall blind: ";
	PlayerInfo pi1=scan.getPlayerInfo(msg[i]);
	cout<<"case "<<i<<": "<<msg[i]<<endl;
	cout<<pi1.print();
	i++;

	msg[i]="7777 1900 8000 100 call";
	PlayerInfo pi2=scan.getPlayerInfo(msg[i]);
	cout<<"case "<<i<<": "<<msg[i]<<endl;
	cout<<pi2.print();
	i++;

	msg[i]= "100 call \n4444 ";
	Action action=scan.getAction(msg[i]);
	cout<<"case "<<i<<": "<<msg[i]<<endl;
	cout<<action.print();
	i++;

	msg[i]= "5555 1900 8000 100 call \n4444 2000 8000 0 fold ";
	RdState rdstate=scan.getRdState(msg[i]);
	cout<<"case "<<i<<": "<<msg[i]<<endl;
	cout<<rdstate.print();
	i++;

	return 0;
}
