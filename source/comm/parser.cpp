#include "parser.h"

void Parser::matchHead(string& msg)
{
	const regex pattern("[\w-]*/ \n"); //watch out for
	string replace;
	msg = regex_replace(msg, pattern, replace);
}

void Parser::matchTail(string& msg)
{
	const regex pattern("/[\w-]* \n");
	string replace;
	msg = regex_replace(msg, pattern, replace);
}

void Parser::matchWColon(string& msg)
{
	const regex pattern("\w*: ");
	string replace;
	msg = regex_replace(msg, pattern, replace);
}




Card Parser::getCard(string& msg)
{
	char color = msg[0], tmp[20];
	int figure;

	sscanf(msg.c_str(), "%s %d", &tmp, &figure); //careful on %s

	const regex pattern("\w* \w* ");
	string replace;
	msg = regex_replace(msg, pattern, replace);
	if(msg[0]=='\n') matchChar(msg);

	return Card::getCard(color, figure);
}

PlayerInfo Parser::getPlayerInfo(string& msg)
{
	int pid, jetton, money;
	sscanf(msg.c_str(),"%d %d %d", &pid, &jetton, &money);

	const regex pattern("\d* \d* \d* ");
	string replace;
	msg = regex_replace(msg, pattern, replace);
	if(msg[0]=='\n') matchChar(msg);

	char pid_ch[20];
	sprintf(pid_ch, "%d", pid);

	return PlayerInfo(string(pid_ch), jetton, money);
}

RdState Parser::getRdState(string& msg)
{
	PlayerInfo info=getPlayerInfo(msg);
	Action anAct=getAction(string& msg);
	return RdState();
}

Action Parser::getAction(string& msg)
{
	int bet=psr->nextInt(msg); 
	matchWord(msg); //now at act

	int act;
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
	matchWord(msg); //now at next line ^

	Action sact;
	sact.act=act;
	sact.bet=bet;
	sact.state; //optimize here later
	return sact;
}




int Parser::nextInt(string& msg)
{
	int num;
	sscanf(msg.c_str(), "%d", &num);
	return num;
}

void Parser::matchChar(string& msg)
{
	msg=msg.substr(1,msg.size()-1);
}

void Parser::matchWord(string& msg)
{
	const regex pattern("\w* ");
	string replace;
	msg = regex_replace(msg, pattern, replace);
}
