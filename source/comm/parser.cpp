#include "parser.h"

Card Parser::getCard(string& msg)
{
	char color = msg[0], tmp[20];
	int figure;

	sscanf(msg.c_str(), "%s %d", &tmp, &figure); //careful on %s

	const regex pattern("\w* \w*.");
	string replace;
	msg = regex_replace(msg, pattern, replace);

	return Card::getCard(color, figure);
}

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

PlayerInfo Parser::getPlayerInfo(string& msg)
{
	int pid, jetton, money;
	sscanf(msg.c_str(),"%d %d %d", &pid, &jetton, &money);

	const regex pattern("\d* \d* \d*.");
	string replace;
	msg = regex_replace(msg, pattern, replace);

	char tmp[20];
	sprintf(tmp, "%d", pid);

	return PlayerInfo(string(pid), jetton, money);
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
	const regex pattern("\w*: ");
	string replace;
	msg = regex_replace(msg, pattern, replace);
}
