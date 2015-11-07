#ifndef _MODEL_ROUND_UTIL_H_
#define _MODEL_ROUND_UTIL_H_

#include "model/Action.h"
#include "model/ModelMacros.h"
#include <iostream>
#include <vector>
using namespace std;

//class RoundUtil is part of the model
//it helps to identify the next player to make a move
//it maintains the list of in-game players and provide relative services
//it is concerned with seats only
class RoundUtil
{
public:
	void init(int nPlyr);
	void rcvAction(int seatNo, Action action);
	int getNextSeat();

	int getPrev(int seatNo);
	int getNext(int seatNo);
	int getThis(int seatNo);
	vector<bool> inGame;

	int getState();
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
