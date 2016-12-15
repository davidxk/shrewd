#include "comm/Scanner.h"
#include "TestCase.h"
#include <cassert>

class ScannerTest: public TestCase
{
public:
	int runTest()
	{
		Scanner scan;
		const int nTestCase=9;
		string msg[nTestCase]={
			"asd-fgh/ \njkl\nzxc-vbn/ \nqwe",
			"/asd-fgh \njkl\n/zxc-vbn \nqwe",
			"asd: fgh",
			"HEARTS 3 \nCLUBS K \n",
			"HEARTS 3 CLUBS K \n",
			"7777 30 250 \nsmall blind: ",
			"7777 1900 8000 100 call",
			"100 call \n4444 ",
			"5555 1900 8000 100 call \n4444 2000 8000 0 fold "
		};
		int i=0;

		scan.matchHead(msg[i]);
		assert(msg[i]=="jkl\nzxc-vbn/ \nqwe");
		i++;

		scan.matchTail(msg[i]);
		assert(msg[i]=="jkl\n/zxc-vbn \nqwe");
		i++;

		scan.matchWColon(msg[i]);
		assert(msg[i]=="fgh");
		i++;

		Card card1=scan.getCard(msg[i]);
		assert(msg[i]=="CLUBS K \n");
		assert(card1.print()=="h3 ");
		i++;

		scan.matchTail(msg[i]);
		Card card2=scan.getCard(msg[i]);
		assert(msg[i]=="CLUBS K \n");
		assert(card2.print()=="h3 ");
		i++;

		PlayerInfo pi1=scan.getPlayerInfo(msg[i]);
		assert(msg[i]=="small blind: ");
		assert(pi1.print()=="Player #7777	@30	$250\n");
		i++;

		PlayerInfo pi2=scan.getPlayerInfo(msg[i]);
		assert(msg[i]=="100 call");
		assert(pi2.print()=="Player #7777	@1900	$8000\n");
		i++;

		Action action=scan.getAction(msg[i]);
		assert(msg[i]=="4444 ");
		assert(action.print()=="100 call\n");
		i++;

		RdState rdstate=scan.getRdState(msg[i]);
		assert(msg[i]=="4444 2000 8000 0 fold ");
		assert(rdstate.print()=="Player #5555\t@1900\t$8000\n100 call\n0inBet\n");
		i++;

		return 0;
	}
};
