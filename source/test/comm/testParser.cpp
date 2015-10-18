#include "../../comm/parser.h"
#include "../../comm/mailman.h"
#include "../../plyr/player.h"
#include "../../plyr/folder.h"

int main()
{
	Mailman mailman;
	FoldPlayer player;
	Parser psr(&player, &mailman);
	string msg;

	msg= "seat/ \nbutton: 4444 2000 8000 \nsmall blind: 5555 2000 8000 \nbig blind: 8888 2000 8000 \n2222 2000 8000 \n3333 2000 8000 \n7777 2000 8000 \n1111 2000 8000 \n6666 2000 8000 \n/seat \n";
	psr.readSeat(msg);
	cout<<"case: "<<msg<<endl;

	msg= "blind/ \n5555: 50 \n8888: 100 \n/blind \n";
	psr.readBlind(msg);
	cout<<"case: "<<msg<<endl;

	msg= "hold/ \nDIAMONDS 4 \nSPADES K \n/hold \n";
	psr.readHold(msg);
	cout<<"case: "<<msg<<endl;

	msg= "flop/ \nHEARTS 6 \nDIAMONDS 3 \nCLUBS 10 \n/flop \n";
	psr.readFlop(msg);
	cout<<"case: "<<msg<<endl;

	msg= "turn/ \nDIAMONDS 7 \n/turn \n";
	psr.readTurn(msg);
	cout<<"case: "<<msg<<endl;

	msg= "showdown/ \ncommon/ \nHEARTS 6 \nDIAMONDS 3 \nCLUBS 10 \nDIAMONDS 7 \nSPADES 9 \n/common \n4: 5555 DIAMONDS 4 SPADES K HIGH_CARD \n3: 8888 HEARTS 3 CLUBS K ONE_PAIR \n4: 3333 HEARTS 5 HEARTS K HIGH_CARD \n2: 7777 CLUBS 6 SPADES 6 THREE_OF_A_KIND \n1: 6666 SPADES 7 CLUBS 7 THREE_OF_A_KIND \n/showdown \n";
	psr.readShowdown(msg);
	cout<<"case: "<<msg<<endl;

	msg= "pot-win/ \n7777: 250 \n1111: 250 \n/pot-win \n";
	psr.readPotwin(msg);
	cout<<"case: "<<msg<<endl;

	return 0;
}
