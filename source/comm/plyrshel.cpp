#include "globals.h"
#include "action.h"
#include "plyrinfo.h"
#include "rdstate.h"
#include "plyrshel.h"
//#include "folder.h"
//#include "caller.h"
//#include "snarepl.h"
#include "shrewdpl.h"
//#include "snarlpl.h"
//#include "snowpl.h"
#include "snorepl.h"
//#include "floprai.h"

//ofstream fout;

void PlayerShell::start()
{
	string filename="shel";
	filename+=player->pid;
	filename+=".log";
	//fout.open(filename.c_str());

	mailman.bindCon();
	mailman.connectCon();
	writeReg();
	
	string msg;
	int gameCnt=1;
	while(msg[0]!='g')
	{
		cout<<"Playing Game "<<gameCnt++<<endl;
		//fout<<gameCnt<<" Hand"<<endl;
		//a game
		player->init();
		readSeat(msg);
		readBlind(msg);
		readHold(msg);
		//fout<<"#THE MSG#"<<msg<<"#MSG END#"<<endl;
		//fout<<"#START WITH#"<<msg[0]<<"#END#"<<endl;
		msg=sticky(msg,"inquire/");
		while(msg[0]!='p')
		{
			//fout<<"#NEW MSG#"<<msg<<"#MSG END#"<<endl;
			//fout<<"#START WITH#"<<msg[0]<<"#END#"<<endl;
			while(msg[0]=='i'||msg[0]=='n')
			{
				if(msg[0]=='i')
				{
					readInquire(msg);
					writeAction();
					msg=mailman.read();
				}
				else
				{
					readNotify(msg);
					if(msg.empty()) msg=mailman.read();
				}
				//fout<<"#MSG WHILE#"<<msg<<"#MSG END#"<<endl;
				//fout<<"#START WITH#"<<msg[0]<<"#END#"<<endl;
			}
			while(msg[0]!='i'&&msg[0]!='n')
			{
				switch(msg[0])
				{
					case 'f': readFlop(msg); break;
					case 't': readTurn(msg); break;
					case 'r': readRiver(msg); break;
					case 's': readShowdown(msg); break;
					case 'p': break;
					default: cout<<"Error: Unknown msg, starting with "
							 <<msg[0]<<"Protocal Unmatch. "<<endl;
				}
				if(msg.empty()) msg=mailman.read();
				if(msg[0]=='p') break;
			}
		}
		readPotwin(msg);
		player->reflect();
		if(msg.empty()) msg=mailman.read();
	}
	cout<<"Player Shell: GAMEOVER! "<<endl;
	mailman.closeCon();
}

void PlayerShell::init(int ch,char* pid,char* si,char* sp,char* ci,char* cp)
{
	switch(ch)
	{
		//case 1: player=new FoldPlayer; break;
		//default: player=new Caller; break;
		//case PID_SNARL_PLAYER: player=new SnarlPlayer(pid); break;
		//case PID_SNARE_PLAYER: player=new SnarePlayer(pid); break;
		//case PID_SNOW_PLAYER: player=new SnowPlayer(pid); break;
		case PID_SNORE_PLAYER: player=new SnorePlayer(pid); break;
		//case PID_FLOP_RAISER: player=new FlopRaiser(pid); break;
		default: player=new ShrewdPlayer(pid); 
	}
	mailman.init(si,sp,ci,cp);
	player->setReg(pid,pid);
}

void PlayerShell::writeReg()
{
	vector<string> regInfo=player->sendReg();
	string msg="reg: ";
	msg+=regInfo[0]; msg+=' ';
	msg+=regInfo[1]; msg+=' ';
	msg+="need_notify "; //could choose no need_notify
	msg+="\n"; 
	mailman.write(msg);
}

void PlayerShell::writeAction()
{
	Action action=player->sendBet();
	player->lastNotify=player->state;
	string actName,moneyStr;
	char smoney[20];
	switch(action.act)
	{
		case ACT_CHECK:
			actName=STR_CHECK;
			break;
		case ACT_CALL:
			actName=STR_CALL;
			break;
		case ACT_RAISE:
			actName=STR_RAISE;
			actName+=' ';
			sprintf(smoney,"%d",action.bet);
			moneyStr.assign(smoney); //convert int to str cont
			break;
		case ACT_ALLIN:
			actName=STR_ALLIN;
			break;
		case ACT_FOLD:
			actName=STR_FOLD;
			break;
		default:break;
	}
	string msg=actName;
	msg+=moneyStr;
	msg+=' ';
	msg+='\n';
	mailman.write(msg);
}

void PlayerShell::readSeat(string& message)
{
	string msg=sticky(message,"seat/");

	int jetton, money;
	string pid;
	vector<PlayerInfo> seat;
	//fout<<"#MSG IN SEAT#"<<msg<<"#END#"; //test

	for(int i=0;i<3;i++)
	{
		if(msg[0]!='s'&&msg[0]!='b') break;
		matchWord(msg); //now at blind
		//fout<<"blind\t"<<msg[0]<<endl;
		matchWord(msg); //now at pid
		//fout<<"pid\t"<<msg[0]<<endl;
		pid=nextWord(msg); //now at jetton
		//fout<<"jetton\t"<<msg[0]<<endl;
		jetton=nextInt(msg); //now at money
		//fout<<"money\t"<<msg[0]<<endl;
		money=nextInt(msg); //now at eol
		//fout<<"eol\t"<<msg[0]<<endl;
		matchChar(msg);
		//fout<<"^\t"<<msg[0]<<endl;
		PlayerInfo pi(pid,jetton,money);
		seat.push_back(pi);
	}
	while(msg[0]!='/')
	{
		pid=nextWord(msg); //now at jetton
		//fout<<"jetton\t"<<msg[0]<<endl;
		jetton=nextInt(msg); //now at money
		//fout<<"money\t"<<msg[0]<<endl;
		money=nextInt(msg); //now at eol
		//fout<<"eol\t"<<msg[0]<<endl;
		matchChar(msg); //now at ^
		//fout<<"^\t"<<msg[0]<<endl;
		PlayerInfo pi(pid,jetton,money);
		seat.push_back(pi);
	}
	player->rcvSeat(seat);
}
	
void PlayerShell::readBlind(string& message)
{
	string msg=sticky(message,"blind/");

	//fout<<"#MSG IN BLIND#"<<msg<<"#END#"; //test
	string pid;
	int bet, act=ACT_BLIND;

	nextWord(msg); //now at eol
	//fout<<"eol\t"<<msg[0]<<endl;
	matchChar(msg); //now at pid
	//fout<<"pid\t"<<msg[0]<<endl;
	pid=nextWord(msg); //now at space
	//fout<<"space\t"<<msg[0]<<endl;
	matchChar(msg); //now at bet
	//fout<<"bet\t"<<msg[0]<<endl;
	bet=nextInt(msg); //now at eol
	//fout<<"eol\t"<<msg[0]<<endl;
	matchChar(msg); //now at ^
	//fout<<"^\t"<<msg[0]<<endl;


	Action sact;
	sact.act=act;
	sact.bet=bet;
	sact.state=D_BET;
	player->rcvOppoAct(pid,sact);
	player->SBlindId=pid;
	player->bigBlind=bet*2;

	if(msg[0]!='/')
	{
		pid=nextWord(msg); //now at space 
		//fout<<"space\t"<<msg[0]<<endl;
		matchChar(msg); //now at bet
		//fout<<"bet\t"<<msg[0]<<endl;
		bet=nextInt(msg); //now at ^
		//fout<<"^\t"<<msg[0]<<endl;

		Action bact;
		bact.act=act;
		bact.bet=bet;
		sact.state=D_BET;
		player->rcvOppoAct(pid,sact);
	}
}

void PlayerShell::readHold(string& message)
{
	string msg=sticky(message,"hold/");

	//fout<<"#MSG IN HOLD#"<<msg<<"#HOLD END#"<<endl; //test
	vector<Card> hole;
	int figure; char color;

	nextWord(msg); //now at eol
	matchChar(msg);
	//fout<<"^\t"<<msg[0]<<endl;

	for(int i=0;i<HOLE_SIZE;i++)
	{
		color=msg[0];
		matchWord(msg); //now at point
		//fout<<"figure\t"<<msg[0]<<endl;
		figure=nextInt(msg); //now at eol
		//fout<<"eol\t"<<msg[0]<<endl;
		matchChar(msg);
		//fout<<"^\t"<<msg[0]<<endl;
		hole.push_back(Card::getCard(color,figure));
	}
	player->rcvHole(hole);
}

void PlayerShell::readInquire(string msg)
{
	//fout<<"#MSG IN INQUIRE#"<<msg<<"#INQUIRE END#"<<endl; //test
	int jetton, money, bet, act;
	string pid;
	vector<RdState> states;

	nextWord(msg); //now at eol
	matchChar(msg);
	//fout<<"^\t"<<msg[0]<<endl;

	while(msg[0]!='t')
	{
		pid=nextWord(msg); //now at jetton
		//fout<<"jetton\t"<<msg[0]<<endl;
		jetton=nextInt(msg); //now at money
		//fout<<"money\t"<<msg[0]<<endl;
		money=nextInt(msg); //now at bet
		//fout<<"bet\t"<<msg[0]<<endl;

		bet=nextInt(msg); //now at act
		//fout<<"act\t"<<msg[0]<<endl;
		switch(msg[3])
		{
			case 'n': act=ACT_BLIND; break;
			case 'c': act=ACT_CHECK; break;
			case 'l': act=ACT_CALL; break;
			case 's': act=ACT_RAISE; break;
			case '_': act=ACT_ALLIN; break;
			case 'd': act=ACT_FOLD; break;
			default: cout<<"Error: Unknown act. Protocal unmatch. "<<endl;
					 act=ACT_SMALL_BLIND;
		}
		nextWord(msg); //now at eol
		//fout<<"eol\t"<<msg[0]<<endl;
		matchChar(msg);
		//fout<<"^\t"<<msg[0]<<endl;

		Action sact;
		sact.act=act;
		sact.bet=bet;
		//mark state
		sact.state=player->state;
		if(!player->isThisRd(pid)&&player->state>D_BET) sact.state-=2;
		//fout<<"player->state "<<player->state<<"\t"<<pid<<endl
			//<<"cntRd "<<player->cntRd<<"\tindex"<<player->findIndex(pid)<<endl
			//<<"sact.state "<<sact.state<<endl;

		player->rcvOppoAct(pid,sact);

		RdState rs(pid,jetton,money,bet,act,player->state);
		states.push_back(rs);
	}
	matchWord(msg); //now at pot
	//fout<<"pot\t"<<msg[0]<<endl;
	matchWord(msg); //now at num
	//fout<<"num\t"<<msg[0]<<endl;
	int pot=nextInt(msg);
	//fout<<"eol\t"<<msg[0]<<endl;
	player->rcvPot(pot);
	player->rcvLstRound(states);
	player->cntRd++;
}

void PlayerShell::readNotify(string& msg)
{
	//fout<<"#MSG IN NOTIFY#"<<msg<<"#NOTIFY END#"<<endl; //test
	int jetton, money, bet, act;
	string pid;
	vector<RdState> states;

	nextWord(msg); //now at eol
	matchChar(msg);
	//fout<<"^\t"<<msg[0]<<endl;

	while(msg[0]!='t')
	{
		pid=nextWord(msg); //now at jetton
		//fout<<"jetton\t"<<msg[0]<<endl;
		jetton=nextInt(msg); //now at money
		//fout<<"money\t"<<msg[0]<<endl;
		money=nextInt(msg); //now at bet
		//fout<<"bet\t"<<msg[0]<<endl;

		bet=nextInt(msg); //now at act
		//fout<<"act\t"<<msg[0]<<endl;
		switch(msg[3])
		{
			case 'n': act=ACT_BLIND; break;
			case 'c': act=ACT_CHECK; break;
			case 'l': act=ACT_CALL; break;
			case 's': act=ACT_RAISE; break;
			case '_': act=ACT_ALLIN; break;
			case 'd': act=ACT_FOLD; break;
			default: cout<<"Error: Unknown act. Protocal unmatch. "<<endl;
					 act=ACT_SMALL_BLIND;
		}
		nextWord(msg); //now at eol
		//fout<<"eol\t"<<msg[0]<<endl;
		matchChar(msg);
		//fout<<"^\t"<<msg[0]<<endl;

		Action sact;
		sact.act=act;
		sact.bet=bet;
		//mark state
		sact.state=player->lastNotify;
		//fout<<"player->lastNotify "<<player->lastNotify<<"\t"<<pid<<endl
			//<<"cntRd "<<player->cntRd<<"\tindex"<<player->findIndex(pid)<<endl
			//<<"sact.state "<<sact.state<<endl
			//<<"myIndex"<<player->findIndex(player->pid)<<endl;

		player->rcvOppoAct(pid,sact);

		RdState rs(pid,jetton,money,bet,act,player->state);
		states.push_back(rs);
	}
	matchWord(msg); //now at pot
	//fout<<"pot\t"<<msg[0]<<endl;
	matchWord(msg); //now at num
	//fout<<"num\t"<<msg[0]<<endl;
	int pot=nextInt(msg);
	//fout<<"eol\t"<<msg[0]<<endl;
	matchChar(msg);
	//fout<<"^\t"<<msg[0]<<endl;

	//fout<<"#ENDING NOTIFY#"<<msg<<"#/NOTIFY#"<<endl;
	nextWord(msg); //now at eol
	//fout<<"eol\t"<<msg[0]<<endl;
	matchChar(msg);
	if(!msg.empty())
		//fout<<"^\t"<<msg[0]<<endl;

	if(player->lastNotify<player->state)player->lastNotify=player->state;
	player->rcvPot(pot);
	player->rcvLstRound(states);
	player->cntRd++;
}

void PlayerShell::readFlop(string& msg)
{
	//fout<<"#MSG IN FLOP#"<<msg<<"#FLOP END#"<<endl; //test
	vector<Card> comm;
	int figure; char color;

	nextWord(msg); //now at eol
	//fout<<"eol\t"<<msg[0]<<endl;
	matchChar(msg);
	//fout<<"^\t"<<msg[0]<<endl;

	for(int i=0;i<N_FLOP;i++)
	{
		color=msg[0];
		matchWord(msg); //now at point
		//fout<<"point\t"<<msg[0]<<endl;
		figure=nextInt(msg); //now at eol
		//fout<<"eol\t"<<msg[0]<<endl;
		matchChar(msg);
		//fout<<"^\t"<<msg[0]<<endl;
		comm.push_back(Card::getCard(color,figure));
	}
	//fout<<"#ENDING FLOP#"<<msg<<"#/FLOP#"<<endl;
	nextWord(msg); //now at eol
	//fout<<"eol\t"<<msg[0]<<endl;
	matchChar(msg);
	if(!msg.empty())
		//fout<<"^\t"<<msg[0]<<endl;

	player->rcvFlop(comm);
	player->cntRd=0;
}

void PlayerShell::readTurn(string& msg)
{
	//fout<<"#MSG IN TURN#"<<msg<<"#TURN END#"<<endl; //test
	int figure; char color;

	nextWord(msg); //now at eol
	//fout<<"eol\t"<<msg[0]<<endl;
	matchChar(msg);
	//fout<<"^\t"<<msg[0]<<endl;

	color=msg[0];
	matchWord(msg); //now at point
	//fout<<"point\t"<<msg[0]<<endl;
	figure=nextInt(msg); //now at eol
	//fout<<"eol\t"<<msg[0]<<endl;
	matchChar(msg);
	//fout<<"^\t"<<msg[0]<<endl;

	//fout<<"#ENDING TURN#"<<msg<<"#/TURN#"<<endl;
	nextWord(msg); //now at eol
	//fout<<"eol\t"<<msg[0]<<endl;
	matchChar(msg);
	if(!msg.empty())
		//fout<<"^\t"<<msg[0]<<endl;

	player->rcvTurn( Card::getCard(color,figure) );
	player->cntRd=0;
}

void PlayerShell::readRiver(string& msg)
{
	//fout<<"#MSG IN RIVER#"<<msg<<"#RIVER END#"<<endl; //test
	int figure; char color;

	nextWord(msg); //now at eol
	matchChar(msg);

	color=msg[0];
	matchWord(msg); //now at point
	figure=nextInt(msg); //now at eol
	matchChar(msg);

	//fout<<"#ENDING RIVER#"<<msg<<"#/RIVER#"<<endl;
	nextWord(msg); //now at eol
	//fout<<"eol\t"<<msg[0]<<endl;
	matchChar(msg);
	if(!msg.empty())
		//fout<<"^\t"<<msg[0]<<endl;

	player->rcvRiver( Card::getCard(color,figure) );
	player->cntRd=0;
}

void PlayerShell::readShowdown(string& msg)
{
	//fout<<"#MSG IN SHOWDOWN#"<<msg<<"#SHOWDOWN END#"<<endl; //test
	int figure; char color;
	vector<int> pHand;
	string pid; int nut_hand;

	for(int i=0;i<2;i++)
	{
		nextWord(msg); //now at eol
		//fout<<"eol\t"<<msg[0]<<endl;
		matchChar(msg);
		//fout<<"^\t"<<msg[0]<<endl;
	}

	for(int i=0;i<COMM_SIZE;i++)
	{
		matchWord(msg); //now at point
		//fout<<"point\t"<<msg[0]<<endl;
		nextInt(msg); //now at eol
		//fout<<"eol\t"<<msg[0]<<endl;
		matchChar(msg);
		//fout<<"^\t"<<msg[0]<<endl;
	}
	nextWord(msg); //now at eol
	//fout<<"eol\t"<<msg[0]<<endl;
	matchChar(msg);
	//fout<<"^\t"<<msg[0]<<endl;

	while(msg[0]!='/')
	{
		vector<Card> pHole;
		matchWord(msg); //now at pid
		//fout<<"pid\t"<<msg[0]<<endl;
		pid=nextWord(msg); //now at color
		//fout<<"color\t"<<msg[0]<<endl;
		for(int i=0;i<2;i++)
		{
			color=msg[0];
			matchWord(msg); //now at point
			//fout<<"point\t"<<msg[0]<<endl;
			figure=nextInt(msg); //now at nut_hand
			//fout<<"nt_hand\t"<<msg[0]<<endl;
			player->rcvPHole(pid, Card::getCard(color,figure));
		}
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
		player->rcvPHand(pid,nut_hand);
		nextWord(msg); //now at eol
		//fout<<"eol\t"<<msg[0]<<endl;
		matchChar(msg);
		//fout<<"^\t"<<msg[0]<<endl;
	}

	//fout<<"#ENDING SHOWDOWN#"<<msg<<"#/SHOWDOWN#"<<endl;
	nextWord(msg); //now at eol
	//fout<<"eol\t"<<msg[0]<<endl;
	matchChar(msg);
	//if(!msg.empty())
		//fout<<"^\t"<<msg[0]<<endl;
}

void PlayerShell::readPotwin(string& msg)
{
	//fout<<"#MSG IN POTWIN#"<<msg<<"#POTWIN END#"<<endl; //test
	string pid; 
	int share;

	nextWord(msg); //now at eol
	//fout<<"eol\t"<<msg[0]<<endl;
	matchChar(msg);
	//fout<<"^\t"<<msg[0]<<endl;

	while(msg[0]!='/')
	{
		pid=nextWord(msg); //now at space
		//fout<<"space\t"<<msg[0]<<endl;
		matchChar(msg); //now at num
		//fout<<"num\t"<<msg[0]<<endl;
		share=nextInt(msg); //now at eol
		//fout<<"eol\t"<<msg[0]<<endl;
		matchChar(msg);
		//fout<<"^\t"<<msg[0]<<endl;
		player->rcvPotwin(pid,share);
	}

	//fout<<"#ENDING POTWIN#"<<msg<<"#/POTWIN#"<<endl;
	nextWord(msg); //now at eol
	//fout<<"eol\t"<<msg[0]<<endl;
	matchChar(msg);
	//if(!msg.empty())
		//fout<<"^\t"<<msg[0]<<endl;
}

void PlayerShell::matchWord(string& piece) 
{
	int start=piece.find(" ")+1;
	piece=piece.substr(start,piece.size()-start);
}

void PlayerShell::matchChar(string& piece)
{
	piece=piece.substr(1,piece.size()-1);
}

int PlayerShell::nextInt(string& piece)
{
	char ch[3]={ ' ',':','\n' };
	int start=100;
	for(int i=0;i<3;i++)
	{
		int pos=piece.find(ch[i])+1;
		if(pos==0) pos=100;
		if(pos<start) start=pos;
	}
	int num=-1;
	if(isdigit(piece[0]))
	{
		string word=piece.substr(0,start-1);
		piece=piece.substr(start,piece.size()-start);
		num=atoi(word.c_str());
	}
	else
	{
		switch(piece[0])
		{
			case 'J': num=11; break;
			case 'Q': num=12; break;
			case 'K': num=13; break;
			case 'A': num=14; break;
			default: break;
		}
		string word=piece.substr(0,start-1);
		piece=piece.substr(start,piece.size()-start);
	}
	return num;
}

string PlayerShell::nextWord(string& piece)
{
	char ch[3]={ ' ',':','\n' };
	int start=100;
	for(int i=0;i<3;i++)
	{
		int pos=piece.find(ch[i])+1;
		if(pos==0) pos=100;
		if(pos<start) start=pos;
	}
	string word=piece.substr(0,start-1);
	piece=piece.substr(start,piece.size()-start);
	return word;
}

PlayerShell::~PlayerShell()
{
	delete player;
}

string PlayerShell::sticky(string& message, string header)
{
	//msg is a copy of the message
	int start=message.find(header);
	if(start==-1) 
		message=mailman.read();
	else message=message.substr(start, message.size()-start);
	return message;
}
