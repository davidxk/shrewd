#include "comm/Mailman.h"

//ofstream tcp_log;
void Mailman::init(const char* si, const char* sp, const char* ci, const char* cp)
{
	strcpy(server_ip, si);
	strcpy(server_port, sp);
	strcpy(client_ip, ci);
	strcpy(client_port, cp);
	//tcp_log.open("./tcp.log");
}

void Mailman::bindCon()
{
	//create socket
	if((socket_fd=socket(AF_INET,SOCK_STREAM,0))<0)
   	{
		//tcp_log<<"create socket error"<<endl;
		exit(0);
	}
	//init serv_addr
	memset(&client_addr,0,sizeof(client_addr));
	client_addr.sin_family = AF_INET;
	client_addr.sin_port = htons(atoi(client_port));
	//parse const char* type client_ip to client_addr.sin_addr
	if(inet_pton(AF_INET,client_ip,&client_addr.sin_addr)<=0)
	{
		//tcp_log<<"inet_pton error for s\n";
		exit(0);
	}
	//binding socket and serv_addr
	while(bind(socket_fd,(struct sockaddr*)&client_addr,sizeof(struct sockaddr))==-1)
	{
        //tcp_log<<"bind error! "<<endl;
    }
}

void Mailman::connectCon()
{
	//init server_addr
	memset(&server_addr,0,sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(atoi(server_port));
	//parse const char* type server_ip to server_addr.sin_addr
	if(inet_pton(AF_INET,server_ip,&server_addr.sin_addr)<=0)
	{
		//tcp_log<<"inet_pton error for s\n";
		exit(0);
	}
	//build connection
	int errorNum;
	while((errorNum=connect(socket_fd,(struct sockaddr*)&server_addr,sizeof(server_addr)))<0)
	{
		usleep(100*1000);
		//tcp_log<<"Connection Error: "<<errorNum<<endl;
	}
}

void Mailman::closeCon()
{
	close(socket_fd);
}





void Mailman::setMsg(string msg)
{
	strcpy(message, msg.c_str());
}

string Mailman::getMsg()
{
	string msg(message);
	//tcp_log<<"Converted to string:\n"<<msg<<endl;
	return msg;
}

string Mailman::read()
{
	int len;
	if((len=(recv(socket_fd,message,MAXDATASIZE,0)))==-1)
	{ /*tcp_log<<"recv error\n";*/ }
	else message[len]='\0';
	return getMsg();
}

void Mailman::write()
{
	while(send(socket_fd,message,strlen(message),0)<0)
	{ /*tcp_log<<"send error.\n";*/ }
}

void Mailman::write(string msg)
{
	setMsg(msg);
	write();
}
