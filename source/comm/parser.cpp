#include "parser.h"
#define PARSER_DEBUG 1

Parser::Parser(Player* pPlayer, Mailman* pMailman):
	player(pPlayer), mailman(pMailman) { }

void Parser::writeReg()
{
	vector<string> regInfo=player->sendReg();
	string msg = "reg: ";
	msg += regInfo[0] + ' ';
	msg += regInfo[1] + ' ';
	msg += "need_notify \n"; //could choose no need_notify
	if(!PARSER_DEBUG) mailman->write(msg);
}

void Parser::writeAction()
{
	Action action=player->sendBet();
	//player->lastNotify=player->state;
	string actName, moneyStr;
	char smoney[20];
	switch(action.act)
	{
		case ACT_CHECK: actName=STR_CHECK; break;
		case ACT_CALL: actName=STR_CALL; break;
		case ACT_RAISE:
			actName=STR_RAISE;
			actName+=' ';
			sprintf(smoney,"%d",action.bet);
			moneyStr.assign(smoney); //convert int to str cont
			break;
		case ACT_ALLIN: actName=STR_ALLIN; break;
		case ACT_FOLD: actName=STR_FOLD; break;
		default:break;
	}
	string msg = actName + moneyStr + " \n";
	if(!PARSER_DEBUG) mailman->write(msg);
}





void Parser::readSeat(string& message)
{
	string msg=sticky(message,"seat/");
	scan.matchHead(msg);
	vector<PlayerInfo> seat;

	for(int i=0;i<3;i++)
	{
		if(msg[0]!='s'&&msg[0]!='b') break;
		if(i>0) scan.matchWord(msg);
		scan.matchWColon(msg);
		seat.push_back( scan.getPlayerInfo(msg) );
	}
	while(msg[0]!='/')
		seat.push_back( scan.getPlayerInfo(msg) );

	player->rcvSeat(seat);
	//consume tail if needed here
	if(PARSER_DEBUG) message=msg;
}
	
void Parser::readBlind(string& message)
{
	string msg=sticky(message,"blind/");
	scan.matchHead(msg);

	int bet, pid;

	pid=scan.nextInt(msg);
	scan.matchWColon(msg);
	bet=scan.nextInt(msg); 
	scan.matchWord(msg); //now at ^

	player->rcvBlind(bet);

	//no point in parsing the rest
	//consume tail if needed here
	if(PARSER_DEBUG) message=msg;
}

void Parser::readHold(string& message)
{
	string msg=sticky(message,"hold/");
	scan.matchHead(msg);

	vector<Card> hole;
	for(int i=0;i<HOLE_SIZE;i++)
		hole.push_back(scan.getCard(msg));

	player->rcvHole(hole);
	//consume tail if needed here
	if(PARSER_DEBUG) message=msg;
}

void Parser::readInquire(string& msg)
{
	//A player reads what he expects to see so the handler simply passes on
	scan.matchHead(msg);
	vector<RdState> lastrd;
	while(msg[0]!='t')
	{
		PlayerInfo pi = scan.getPlayerInfo(msg);
		Action act = scan.getAction(msg);
		RdState rdstate(pi, act, 0);

		lastrd.push_back(rdstate);
	}
	player->rcvLstRound(lastrd);

	scan.matchWord(msg);
	scan.matchWColon(msg);
	int pot = scan.nextInt(msg);
	player->rcvPot(pot);
	scan.matchWord(msg);
	//consume tail if needed here
}





void Parser::readFlop(string& msg)
{
	scan.matchHead(msg);

	vector<Card> comm;
	for(int i=0;i<N_FLOP;i++)
		comm.push_back(scan.getCard(msg));

	player->rcvFlop(comm);
	//consume tail if needed here
}

void Parser::readTurn(string& msg)
{
	scan.matchHead(msg);
	player->rcvTurn( scan.getCard(msg) );
}

void Parser::readRiver(string& msg)
{
	scan.matchHead(msg);
	player->rcvRiver( scan.getCard(msg) );
}

void Parser::readShowdown(string& msg)
{
	scan.matchHead(msg);
	scan.matchHead(msg);

	int pid, nut_hand;

	for(int i=0;i<COMM_SIZE;i++)
		scan.getCard(msg);
	scan.matchTail(msg);

	while(msg[0]!='/')
	{
		scan.matchWColon(msg);

		pid=scan.nextInt(msg);
		scan.matchWord(msg);

		for(int i=0; i<2; i++)
			player->rcvPHole(pid, scan.getCard(msg));
		
		//deal with nut hand with switch(msg[1]) cont
		switch(msg[1])
		{
			case 'I': nut_hand=HIGHCARD; break;
			case 'N': nut_hand=PAIR; break;
			case 'W': nut_hand=TWOPAIRS; break;
			case 'H': nut_hand=TRIP; break;
			case 'L': nut_hand=FLUSH; break;
			case 'U': nut_hand=FULLHOUSE; break;
			case 'O': nut_hand=FOUR; break;
			case 'T':
					  if(msg[8]=='_') nut_hand=STRAIGHTFLUSH;
					  else nut_hand=STRAIGHT;
					  break;
			default: cout<<"Error: Unknow hand. Protocal Unmatch. "<<endl;
		}
		player->rcvPHand(pid, nut_hand);
		scan.matchWord(msg);
	}
	scan.matchTail(msg);
}

void Parser::readPotwin(string& message)
{
	string msg=sticky(message, "pot-win/");
	scan.matchHead(msg);

	int pid, share;

	while(msg[0]!='/')
	{
		pid=scan.nextInt(msg);
		scan.matchWColon(msg);
		share=scan.nextInt(msg); 
		scan.matchWord(msg); //now at ^

		player->rcvPotwin(pid, share);
	}
	scan.matchTail(msg);
	if(PARSER_DEBUG) message=msg;
}





string Parser::sticky(string& message, string header)
{
	//msg is a copy of the message
	int start=message.find(header);
	if(start==-1 && !PARSER_DEBUG) 
		message=mailman->read();
	else message=message.substr(start, message.size()-start);
	return message;
}
