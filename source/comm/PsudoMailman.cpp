#include "comm/PsudoMailman.h"

void Mailman::init(char* si, char* sp, char* ci, char* cp) 
{ 
	int i=0;
	cout<<"-----Testing Controller-----\n";
	cout.flush();
	while( getline(cin, msg[i++], '#') );
		//cout<<"Got line"<<i-1<<": "<<msg[i-1]<<endl;
}

void Mailman::bindCon() { }
void Mailman::connectCon() { }
void Mailman::closeCon() { }

string Mailman::read()
{
	if(msg[cnt].empty()) exit(0);
	return msg[cnt++];
}

void Mailman::write(string msg)
{
	cout<<msg;
}
