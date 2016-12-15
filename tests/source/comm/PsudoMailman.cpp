#include "comm/PsudoMailman.h"
#include <fstream>

void PsudoMailman::init(const char* si, const char* sp, const char* ci, const char* cp) 
{ 
	int i=0;
	cout<<"-----Testing Controller-----\n";
	cout.flush();
	ifstream fin("input/input2.txt");
	while( getline(fin, msg[i++], '#') );
	//for (int j=0; j<100; j++)
		//cout<<msg[j]<<endl;
		//cout<<"Got line"<<i-1<<": "<<msg[i-1]<<endl;
}

string PsudoMailman::read()
{
	if(msg[cnt].empty()) exit(0);
	return msg[cnt++];
}

void PsudoMailman::write(string msg)
{
	cout<<msg;
}
