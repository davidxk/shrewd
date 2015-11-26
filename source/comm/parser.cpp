#include "comm/Parser.h"
#include "model/ModelMacros.h"
#define PARSER_DEBUG 1

const string Parser::STR_CHECK="check";
const string Parser::STR_CALL="call";
const string Parser::STR_RAISE="raise";
const string Parser::STR_ALLIN="all_in";
const string Parser::STR_FOLD="fold";

string Parser::writeReg(const vector<string>& regInfo)
{
	string msg = "reg: ";
	msg += regInfo[0] + ' ';
	msg += regInfo[1] + ' ';
	msg += "no need_notify \n"; //could choose no need_notify
	return msg;
}

string Parser::writeAction(const Action& action)
{
	string actName, moneyStr;
	char smoney[20];
	switch(action.act)
	{
		case Action::ACT_CHECK: actName=STR_CHECK; break;
		case Action::ACT_CALL: actName=STR_CALL; break;
		case Action::ACT_RAISE:
			actName=STR_RAISE;
			actName+=' ';
			sprintf(smoney,"%d",action.bet);
			moneyStr.assign(smoney); //convert int to str cont
			break;
		case Action::ACT_ALLIN: actName=STR_ALLIN; break;
		case Action::ACT_FOLD: actName=STR_FOLD; break;
		default:break;
	}
	string msg = actName + moneyStr + " \n";
	return msg;
}





vector<PlayerInfo> Parser::readSeat(string& msg)
{
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

	scan.matchTail(msg);
	return seat;
}
	
int Parser::readBlind(string& msg)
{
	scan.matchHead(msg);

	//int pid=scan.nextInt(msg);
	scan.matchWColon(msg);
	int bet=scan.nextInt(msg); 
	scan.matchWord(msg); //now at ^

	//no point in parsing the rest
	//consume tail if needed here
	return bet;
}

vector<Card> Parser::readHold(string& msg)
{
	scan.matchHead(msg);

	vector<Card> hole;
	for(int i=0; i<texas_holdem::HOLE_SIZE; i++)
		hole.push_back(scan.getCard(msg));

	scan.matchTail(msg);
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
	scan.matchTail(msg);
	return TableInfo(lastrd, pot);
}





vector<Card> Parser::readFlop(string& msg)
{
	scan.matchHead(msg);

	vector<Card> comm;
	for(int i=0; i<texas_holdem::N_FLOP; i++)
		comm.push_back(scan.getCard(msg));

	scan.matchTail(msg);
	return comm;
}

Card Parser::readTurn(string& msg)
{
	scan.matchHead(msg);
	Card card=scan.getCard(msg);
	scan.matchTail(msg);
	return card;
}

Card Parser::readRiver(string& msg)
{
	return readTurn(msg);
}

unordered_map<int, ShowdownInfo> Parser::readShowdown(string& msg)
{
	scan.matchHead(msg);
	scan.matchHead(msg);

	for(int i=0; i<texas_holdem::COMM_SIZE; i++)
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
		Hand::Rank nut_hand;
		switch(msg[1])
		{
			case 'I': nut_hand = Hand::HIGHCARD; break;
			case 'N': nut_hand = Hand::PAIR; break;
			case 'W': nut_hand = Hand::TWOPAIRS; break;
			case 'H': nut_hand = Hand::TRIP; break;
			case 'L': nut_hand = Hand::FLUSH; break;
			case 'U': nut_hand = Hand::FULLHOUSE; break;
			case 'O': nut_hand = Hand::FOUR; break;
			case 'T':
					  if(msg[8]=='_') nut_hand = Hand::STRAIGHTFLUSH;
					  else nut_hand = Hand::STRAIGHT;
					  break;
			default: nut_hand=Hand::NOT_THIS_RANK;
					 cout<<"Error: Unknow hand. Protocal Unmatch. "<<endl;
		}
		ShowdownInfo shwdInfo(pHole, nut_hand);
		shwdMap.insert( make_pair<int,ShowdownInfo>(pid, shwdInfo) );

		pHole.clear();
		scan.matchWord(msg);
	}
	scan.matchTail(msg);
	return shwdMap;
}

unordered_map<int, int> Parser::readPotwin(string& msg)
{
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
	return potShare;
}
