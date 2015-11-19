#include "comm/Parser.h"
#include <cassert>

class ParserTest
{
public:
	int onEnter()
	{
		Parser psr;
		string msg, out;

		msg= "seat/ \nbutton: 4444 2000 8000 \nsmall blind: 5555 2000 8000 \nbig blind: 8888 2000 8000 \n2222 2000 8000 \n3333 2000 8000 \n7777 2000 8000 \n1111 2000 8000 \n6666 2000 8000 \n/seat \n";
		psr.readSeat(msg);
		assert(msg.empty());

		msg= "blind/ \n5555: 50 \n8888: 100 \n/blind \n";
		psr.readBlind(msg);
		assert(msg=="8888: 100 \n/blind \n");

		msg= "hold/ \nDIAMONDS 4 \nSPADES K \n/hold \n";
		psr.readHold(msg);
		assert(msg.empty());

		msg= "inquire/ \n5555 1900 8000 100 call \n4444 2000 8000 0 fold \n6666 1900 8000 100 call \n1111 2000 8000 0 fold \n7777 1900 8000 100 call \n3333 1900 8000 100 call \n2222 2000 8000 0 fold \n8888 1900 8000 100 blind \ntotal pot: 500 \n/inquire \n";
		psr.readInquire(msg);
		assert(msg.empty());

		msg= "flop/ \nHEARTS 6 \nDIAMONDS 3 \nCLUBS 10 \n/flop \n";
		psr.readFlop(msg);
		assert(msg.empty());

		msg= "turn/ \nDIAMONDS 7 \n/turn \n";
		psr.readTurn(msg);
		assert(msg.empty());

		msg= "showdown/ \ncommon/ \nHEARTS 6 \nDIAMONDS 3 \nCLUBS 10 \nDIAMONDS 7 \nSPADES 9 \n/common \n4: 5555 DIAMONDS 4 SPADES K HIGH_CARD \n3: 8888 HEARTS 3 CLUBS K ONE_PAIR \n4: 3333 HEARTS 5 HEARTS K HIGH_CARD \n2: 7777 CLUBS 6 SPADES 6 THREE_OF_A_KIND \n1: 6666 SPADES 7 CLUBS 7 THREE_OF_A_KIND \n/showdown \n";
		psr.readShowdown(msg);
		assert(msg.empty());

		msg= "pot-win/ \n7777: 250 \n1111: 250 \n/pot-win \n";
		psr.readPotwin(msg);
		assert(msg.empty());

		return 0;
	}
};
