#ifndef _COMM_MAIL_MAN_H_
#define _COMM_MAIL_MAN_H_

#define MAXDATASIZE 4096
#define MAXLEN 20
#include <arpa/inet.h>
#include <cstdio>
#include <cstdlib>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//Mailmab is the interface facing the internet
class Mailman
{
public:
	virtual void init(const char* si, const char* sp, const char* ci, const char* cp);
	virtual void bindCon();
	virtual void connectCon();
	virtual void closeCon();

	virtual string read();
	virtual void write(string msg);
	virtual ~Mailman() { }

private:
	void setMsg(string msg);
	string getMsg();
	void write();
private:
	int socket_fd;
	struct sockaddr_in server_addr;
    struct sockaddr_in client_addr; 
	char message[MAXDATASIZE];
	char server_ip[MAXLEN], server_port[MAXLEN];
	char client_ip[MAXLEN], client_port[MAXLEN];
};
#endif
