//A Handler send/rcv msg from mailman analyze it with parser 
// and passes the data it to player
//A Handler works closely with the mailman, the parser and the player
//A Handler is a private class internal to the Controller 
//View it as an assembly of private methods 

void PlayerShell::writeReg()
{
	vector<string> regInfo=player->sendReg();
	string msg = "reg: ";
	msg += regInfo[0] + ' ';
	msg += regInfo[1] + ' ';
	msg += "need_notify \n"; //could choose no need_notify
	mailman.write(msg);
}

void PlayerShell::readSeat(string& message)
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
	
void PlayerShell::readBlind(string& message)
{
	string msg=sticky(message,"blind/");
	psr->matchHead(msg);

	int bet, pid, act=ACT_BLIND;
	char pid_ch[20];

	pid=psr->nextInt(msg);
	sprintf(pid_ch, "%d", pid);
	psr->matchWColon(msg);
	bet=psr->nextInt(msg); //now at eol
	psr->matchChar(msg); //now at ^

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

void PlayerShell::readHold(string& message)
{
	string msg=sticky(message,"hold/");
	psr->matchHead(msg);

	vector<Card> hole;
	for(int i=0;i<HOLE_SIZE;i++)
		hole.push_back(psr->getCard(msg));

	player->rcvHole(hole);
}

void PlayerShell::readInquire(string msg)
{

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
