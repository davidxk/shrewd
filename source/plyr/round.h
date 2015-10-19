#ifndef _ROUND_H_
#define _ROUND_H_

//include here

//description of the class here
class Round
{
public:
	void init(nPlyr);
	void rcvAction(int seatNo, int action);
	int getNextSeat();

	int getPrev(int seatNo);
	int getNext(int seatNo);
	int getThis(int seatNo);
	vector<bool> inGame;

	int getNInGame();
	int getNPlyr();
private:
	int next;
	int rdEnd;
	int nPlyr;
	int nInGame;
};
#endif
