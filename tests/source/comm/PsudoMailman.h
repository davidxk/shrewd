#ifndef _PSUDOMAILMAN_H_
#define _PSUDOMAILMAN_H_
#include "comm/Mailman.h"
#include <iostream>
using namespace std;

class PsudoMailman: public Mailman
{
private:
	string msg[100];
	int cnt=0;
public:
	void init(const char* si, const char* sp, const char* ci, const char* cp);
	void bindCon() { }
	void connectCon() { }
	void closeCon() { }

	string read();
	void write(string msg);
};
#endif
