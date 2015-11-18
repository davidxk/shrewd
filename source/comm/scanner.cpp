#include "comm/Scanner.h"

void Scanner::matchHead(string& msg)
{
	const regex pattern("[\\w-]*/ \n"); //watch out for
	string replace;
	msg = regex_replace(msg, pattern, replace, 
			regex_constants::format_first_only);
}

void Scanner::matchTail(string& msg)
{
	const regex pattern("/[\\w-]* \n");
	string replace;
	msg = regex_replace(msg, pattern, replace,
			regex_constants::format_first_only);
}

void Scanner::matchWColon(string& msg)
{
	const regex pattern("\\w*: ");
	string replace;
	msg = regex_replace(msg, pattern, replace,
			regex_constants::format_first_only);
}




Card Scanner::getCard(string& msg)
{
	char color = msg[0], tmp[20];
	int figure;

	sscanf(msg.c_str(), "%s %d", tmp, &figure); //careful on %s

	const regex pattern("\\w* \\w* ");
	string replace;
	msg = regex_replace(msg, pattern, replace, 
			regex_constants::format_first_only);
	if(msg[0]=='\n') matchChar(msg);

	return Card::getCard(color, figure);
}

PlayerInfo Scanner::getPlayerInfo(string& msg)
{
	int pid, jetton, money;
	sscanf(msg.c_str(),"%d %d %d", &pid, &jetton, &money);

	const regex pattern("\\d* \\d* \\d* ");
	string replace;
	msg = regex_replace(msg, pattern, replace,
			regex_constants::format_first_only);
	if(msg[0]=='\n') matchChar(msg);

	return PlayerInfo(pid, jetton, money);
}

Action Scanner::getAction(string& msg)
{
	int bet=nextInt(msg); 
	matchWord(msg); //now at act

	Action::ACT act;
	switch(msg[3])
	{
		case 'n': act = Action::ACT_BLIND; break;
		case 'c': act = Action::ACT_CHECK; break;
		case 'l': act = Action::ACT_CALL; break;
		case 's': act = Action::ACT_RAISE; break;
		case '_': act = Action::ACT_ALLIN; break;
		case 'd': act = Action::ACT_FOLD; break;
		default: cout<<"Error: Unknown act. Protocal unmatch. "<<endl;
				 act = Action::ACT_BLIND;
	}
	matchWord(msg); //now at next line ^

	Action sact(act, bet);
	return sact;
}

RdState Scanner::getRdState(string& msg)
{
	PlayerInfo info=getPlayerInfo(msg);
	Action anAct=getAction(msg);
	return RdState(info, anAct);
}




int Scanner::nextInt(string& msg)
{
	int num;
	sscanf(msg.c_str(), "%d", &num);
	return num;
}

void Scanner::matchChar(string& msg)
{
	msg=msg.substr(1,msg.size()-1);
}

void Scanner::matchWord(string& msg)
{
	const regex pattern("\\w* ");
	string replace;
	msg = regex_replace(msg, pattern, replace, 
			regex_constants::format_first_only);
	if(msg[0]=='\n') matchChar(msg);
}
