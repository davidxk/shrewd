#include "handler.h"

void Handler::writeReg()
{
	vector<string> regInfo=player->sendReg();
	string msg = "reg: ";
	msg += regInfo[0] + ' ';
	msg += regInfo[1] + ' ';
	msg += "need_notify \n"; //could choose no need_notify
	mailman.write(msg);
}

void PlayerShell::writeAction()
{
	Action action=player->sendBet();
	player->lastNotify=player->state;
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
	mailman.write(msg);
}

void Handler::readSeat(string& message)
{
	string msg=sticky(message,"seat/");
	psr->matchHead(msg);
	vector<PlayerInfo> seat;

	for(int i=0;i<3;i++)
	{
		if(msg[0]!='s'&&msg[0]!='b') break;
		if(i>0) psr->matchWord(msg);
		seat.push_back(psr->matchWColon(msg));
	}
	while(msg[0]!='/')
		seat.push_back( psr->getPlayerInfo(msg) );

	player->rcvSeat(seat);
	//consume tail if needed here
}
	
void Handler::readBlind(string& message)
{
	string msg=sticky(message,"blind/");
	psr->matchHead(msg);

	int bet, pid, act=ACT_BLIND;
	char pid_ch[20];

	pid=psr->nextInt(msg);
	sprintf(pid_ch, "%d", pid);
	psr->matchWColon(msg);
	bet=psr->nextInt(msg); //now at eol
	psr->matchWord(msg); //now at ^

	Action sact;
	sact.act=act;
	sact.bet=bet;
	sact.state=D_BET;
	player->rcvOppoAct(string(pid_ch), sact);
	//optimize here later
	player->SBlindId=pid;
	player->bigBlind=bet*2;

	if(msg[0]!='/')
	{
		sscanf(message.c_str(), "%d:", &pid);
		sprintf(pid_ch, "%d", pid);
		psr->matchWColon(msg);
		bet=psr->nextInt(msg); //now at eol
		psr->matchChar(msg); //now at ^

		Action bact;
		bact.act=act;
		bact.bet=bet;
		sact.state=D_BET;
		player->rcvOppoAct(pid, sact);
	}
}

void Handler::readHold(string& message)
{
	string msg=sticky(message,"hold/");
	psr->matchHead(msg);

	vector<Card> hole;
	for(int i=0;i<HOLE_SIZE;i++)
		hole.push_back(psr->getCard(msg));

	player->rcvHole(hole);
	//consume tail if needed here
}

void Handler::readInquire(string msg)
{
	//A player reads what he expects to see so the handler simply passes on

}

void Handler::readFlop(string& msg)
{
	psr->matchHead(msg);

	vector<Card> comm;
	for(int i=0;i<N_FLOP;i++)
		comm.push_back(psr->getCard(msg));
	//caution here, plyrshel judged if msg empty here 

	player->rcvFlop(comm);
	player->cntRd=0; //optimize here later
	//consume tail if needed here
}

void Handler::readTurn(string& msg)
{
	psr->matchHead(msg);

	player->rcvTurn( psr->getCard(msg) );
	//caution here, plyrshel judged if msg empty here 
	player->cntRd=0; //optimize here later
}

void Handler::readRiver(string& msg)
{
	psr->matchHead(msg);

	player->rcvRiver( psr->getCard(msg) );
	//caution here, plyrshel judged if msg empty here 
	player->cntRd=0; //optimize here later
}

void Handler::readShowdown(string& msg)
{
	psr->matchHead(msg);
	psr->matchHead(msg);

	int pid, nut_hand;
	char pid_ch[20];

	for(int i=0;i<COMM_SIZE;i++)
		psr->getCard(msg);
	psr->matchTail();

	while(msg[0]!='/')
	{
		psr->matchWColon(msg);

		pid=psr->nextInt(msg);
		sprintf(pid_ch, "%d", pid);
		psr->matchWord(msg);

		for(int i=0;i<2;i++)
			player->rcvPHole(string(pid_ch), psr->getCard(msg));
		
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
		player->rcvPHand(string(pid_ch), nut_hand);
		psr->matchWord(msg);
	}
	psr->matchTail(msg);
}

void Handler::readPotwin(string& msg)
{
	string msg=sticky(message, "pot-win/");
	psr->matchHead(msg);

	int pid, share;
	char pid_ch[20];

	while(msg[0]!='/')
	{
		pid=psr->nextInt(msg);
		sprintf(pid_ch, "%d", pid);
		psr->matchWColon(msg);
		share=psr->nextInt(msg); //now at eol
		psr->matchWord(msg); //now at ^

		player->rcvPotwin(string(pid_ch), share);
	}
	psr->matchTail(msg);
}





string Handler::sticky(string& message, string header)
{
	//msg is a copy of the message
	int start=message.find(header);
	if(start==-1) 
		message=mailman.read();
	else message=message.substr(start, message.size()-start);
	return message;
}
