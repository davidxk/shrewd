#ifndef _COMM_PSUDO_MAIL_MAN_H_
#define _COMM_PSUDO_MAIL_MAN_H_

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//Mailmab is the interface facing the internet
class Mailman
{
private:
	string msg[100];
	int cnt=0;
public:
	void init(char* si, char* sp, char* ci, char* cp);
	void bindCon();
	void connectCon();
	void closeCon();

	string read();
	void write(string msg);
};
#endif
