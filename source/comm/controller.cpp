#include "comm/Controller.h"

#include "ai/plyrInclude.h"
#include "comm/Parser.h"

void Controller::init(int ch, char* pid, char* name, 
		char* si, char* sp, char* ci, char* cp)
{
	switch(ch)
	{
		case 0: player=new FoldPlayer(); break;
	}
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

		while(msg[0]!='p')
			mainLoop(msg);

		msg=sticky(msg, "pot-win/");
		player->rcvPotwin( psr.readPotwin(msg) );

		//player->reflect();
		if(msg.empty()) msg=mailman.read();
	}
	cout<<"Player: GAMEOVER! "<<endl;
	mailman.closeCon();
}

void Controller::gameStart(string& msg)
{
	msg=sticky(msg, "seat/");
	player->rcvSeat( psr.readSeat(msg) );
	msg=sticky(msg, "blind/");
	player->rcvBlind( psr.readBlind(msg) );
	msg=sticky(msg, "hold/");
	player->rcvHole( psr.readHold(msg) );
}

void Controller::mainLoop(string& msg)
{
	while(msg[0]=='i'||msg[0]=='n')
	{
		if(msg[0]=='i')
		{
			player->rcvLstRound( psr.readInquire(msg) );
			mailman.write( psr.writeAction( player->sendBet() ) );
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
			case 'f': player->rcvFlop( psr.readFlop(msg) ); break;
			case 't': player->rcvTurn( psr.readTurn(msg) ); break;
			case 'r': player->rcvRiver( psr.readRiver(msg) ); break;
			case 's': player->rcvShowdown( psr.readShowdown(msg) ); break;
			case 'p': break;
			default: cout<<"Error: Unknown msg, starting with '"
					 <<msg[0]<<"'. Protocal Unmatch. "<<endl;
		}
		if(msg.empty()) msg=mailman.read();
		if(msg[0]=='p') break;
	}
}




string Controller::sticky(string& message, string header)
{
	int start=message.find(header);
	if(start==-1) 
		message=mailman.read();
	else message=message.substr(start, message.size()-start);
	return message;
}
