#include "comm/Controller.h"

#include "comm/Mailman.h"
#include "comm/Parser.h"
//#include "data/plyrInclude.h"

void Controller::init(int ch, char* pid, char* name, 
		char* si, char* sp, char* ci, char* cp)
{
	/*switch(ch)
	{
		case PID_SNORE_PLAYER: player=new SnorePlayer(pid); break;
		default: player=new ShrewdPlayer(pid); 
	}*/
	mailman.init(si, sp, ci, cp);
	player->setReg(pid, name);
}

void Controller::start()
{
	mailman.bindCon();
	mailman.connectCon();
	mailman.write( psr.writeReg( player->sendReg() ) );
	
	string msg;
	int gameCnt=1;
	while(msg[0]!='g')
	{
		cout<<"Playing Game "<<gameCnt++<<endl;
		player->init();
		gameStart(msg);

		msg=sticky(msg,"inquire/");
		while(msg[0]!='p')
			mainLoop(msg);

		msg=sticky(message, "pot-win/");
		player->rcvPotwin( prs.readPotwin(msg) );

		//player->reflect();
		if(msg.empty()) msg=mailman.read();
	}
	cout<<"Player: GAMEOVER! "<<endl;
	mailman.closeCon();
}

void Controller::gameStart(string& msg)
{
	msg=sticky(message, "seat/");
	player->rcvSeat( prs.readSeat(msg) );
	msg=sticky(message, "blind/");
	player->rcvBlind( psr.readBlind(msg) );
	msg=sticky(message, "hold/");
	player->rcvHole( psr.readHold(msg) );
}

void Controller::mainLoop(string& msg)
{
	while(msg[0]=='i'||msg[0]=='n')
	{
		if(msg[0]=='i')
		{
			player->rcvLstRound( psr.readInquire(msg) );
			mailman.wirte( psr.writeAction( player->sendBet() ) );
			msg=mailman.read();
		}
		else
		{
			//player->rcvNotify( psr.readNotify(msg) );
			if(msg.empty()) msg=mailman.read();
		}
	}
	while(msg[0]!='i'&&msg[0]!='n')
	{
		switch(msg[0])
		{
			case 'f': player->rcvFlop( prs.readFlop(msg) ); break;
			case 't': player->rcvTurn( prs.readTurn(msg) ); break;
			case 'r': player->rcvRiver( prs.readRiver(msg) ); break;
			case 's': player->rcvShowdown( psr.readShowdown(msg) ); break;
			case 'p': break;
			default: cout<<"Error: Unknown msg, starting with "
					 <<msg[0]<<"Protocal Unmatch. "<<endl;
		}
		if(msg.empty()) msg=mailman.read();
		if(msg[0]=='p') break;
	}
}




string Controller::sticky(string& message, string header)
{
	//msg is a copy of the message
	int start=message.find(header);
	if(start==-1) 
		message=mailman.read();
	else message=message.substr(start, message.size()-start);
	return message;
}
