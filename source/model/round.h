#ifndef _ROUND_H_
#define _ROUND_H_

#include <iostream>
#include <vector>
using namespace std;

//class Round is part of the model
//it helps to identify the next player to make a move
//it maintains the list of in-game players and provide relative services
//it is concerned with seats only
class Round
{
public:
	void init(int nPlyr);
	void rcvAction(int seatNo, int action);
	int getNextSeat();

	int getPrev(int seatNo);
	int getNext(int seatNo);
	int getThis(int seatNo);
	vector<bool> inGame;

	int getNInGame();
	vector<bool> getInGame();
private:
	int next;
	int rdEnd;
	int nPlyr;
	int nInGame;
	int state;
};
#endif
