#include "comm/parser.h"
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





vector<PlayerInfo> Parser::readSeat(string& message)
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

	//consume tail if needed here
	if(PARSER_DEBUG) message=msg;
	return seat;
}
	
int Parser::readBlind(string& message)
{
	string msg=sticky(message,"blind/");
	scan.matchHead(msg);

	int pid=scan.nextInt(msg);
	scan.matchWColon(msg);
	int bet=scan.nextInt(msg); 
	scan.matchWord(msg); //now at ^

	//no point in parsing the rest
	//consume tail if needed here
	if(PARSER_DEBUG) message=msg;
	return bet;
}

vector<Card> Parser::readHold(string& message)
{
	string msg=sticky(message,"hold/");
	scan.matchHead(msg);

	vector<Card> hole;
	for(int i=0;i<HOLE_SIZE;i++)
		hole.push_back(scan.getCard(msg));

	//consume tail if needed here
	if(PARSER_DEBUG) message=msg;
	return hole;
}

TableInfo Parser::readInquire(string& msg)
{
	//A player reads what he expects to see so the handler simply passes on
	scan.matchHead(msg);
	unordered_map<int, RdState> lastrd;
	while(msg[0]!='t')
	{
		PlayerInfo pi = scan.getPlayerInfo(msg);
		Action act = scan.getAction(msg);
		RdState rdstate(pi, act, 0);

		lastrd.insert( make_pair<int,RdState>(pi.pid, rdstate) );
	}

	scan.matchWord(msg);
	scan.matchWColon(msg);
	int pot = scan.nextInt(msg);
	scan.matchWord(msg);
	//consume tail if needed here
	return TableInfo(lastrd, pot);
}





vector<Card> Parser::readFlop(string& msg)
{
	scan.matchHead(msg);

	vector<Card> comm;
	for(int i=0;i<N_FLOP;i++)
		comm.push_back(scan.getCard(msg));

	//consume tail if needed here
	return comm;
}

Card Parser::readTurn(string& msg)
{
	scan.matchHead(msg);
	return scan.getCard(msg);
}

Card Parser::readRiver(string& msg)
{
	return readTurn(msg);
}

unordered_map<int, ShowdownInfo> Parser::readShowdown(string& msg)
{
	scan.matchHead(msg);
	scan.matchHead(msg);

	for(int i=0;i<COMM_SIZE;i++)
		scan.getCard(msg);
	scan.matchTail(msg);

	unordered_map<int, ShowdownInfo> shwdMap;

	while(msg[0]!='/')
	{
		scan.matchWColon(msg);

		int pid=scan.nextInt(msg);
		scan.matchWord(msg);

		vector<Card> pHole;
		for(int i=0; i<2; i++)
			pHole.push_back(scan.getCard(msg));
		
		//deal with nut hand with switch(msg[1]) cont
		int nut_hand;
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
		ShowdownInfo shwdInfo(pHole, nut_hand);
		shwdMap.insert( make_pair<int,ShowdownInfo>(pid, shwdInfo) );

		pHole.clear();
		scan.matchWord(msg);
	}
	scan.matchTail(msg);
	return shwdMap;
}

unordered_map<int, int> Parser::readPotwin(string& message)
{
	string msg=sticky(message, "pot-win/");
	scan.matchHead(msg);

	unordered_map<int, int> potShare;
	while(msg[0]!='/')
	{
		int pid=scan.nextInt(msg);
		scan.matchWColon(msg);
		int share=scan.nextInt(msg); 
		scan.matchWord(msg); //now at ^

		potShare.insert( make_pair<int,int>(pid, share) );
	}
	scan.matchTail(msg);
	if(PARSER_DEBUG) message=msg;
	return potShare;
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
