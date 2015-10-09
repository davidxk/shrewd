#include "globals.h"
#include "shrewdpl.h"
#include "card.h"

ofstream dout;
ShrewdPlayer::ShrewdPlayer(string pid)
{
	string file="shr"; file+=pid+".log";
	dout.open(file.c_str());
}

Action ShrewdPlayer::sendBet()
{
	Action act;
	switch(state)
	{
		case D_BET: act=dealBet(); break;
		case F_BET: act=flopBet(); break;
		case T_BET: act=flopBet(); break;
		case R_BET: act=flopBet(); break;
		default: break;
	}
	return act;
}

Action ShrewdPlayer::dealBet()
{
	Action act;

	float pwin;
	int cntFold=0, cntPlyrs=0;
	for(int i=0;i<lastrd.size();i++)
		if(lastrd[i].lastAct==ACT_FOLD)
			cntFold++;
	cntPlyrs=pstate.size()-cntFold;

	SimuPlayer sp;
	sp.setPlayers(cntPlyrs);
	sp.setState(state,hole,comm);
	pwin=sp.simulate(800);

	int leastBuyin=getLeastBuyin();
	float potodds=(float)leastBuyin/(leastBuyin+pot);
	int bet;
	if(pwin==1.0) act.act=ACT_ALLIN;
	else bet=act.bet=pwin*pot/(1-pwin);

	if(pwin<potodds) act.act=ACT_FOLD;
	else if(pwin>0.22) act.act=ACT_RAISE;
	else if(pwin<0.16) act.act=ACT_FOLD;
	else if(leastBuyin<jetton*0.2)act.act=ACT_CALL;
	else act.act=ACT_FOLD;

	if(act.act==ACT_RAISE)
		if(act.bet>jetton*0.4)
			if(leastBuyin<jetton*0.4)
				act.bet=jetton*0.4;

	dout<<pid<<" DEAL BET DECIDE!"<<endl;
	for(int i=0;i<hole.size();i++)
		dout<<hole[i].print();
	dout<<endl;
	for(int i=0;i<comm.size();i++)
		dout<<comm[i].print();
	dout<<endl;
	dout<<"pwin="<<pwin<<"\tpotodds="<<potodds<<endl
		<<"of "<<cntPlyrs<<"\tin state "<<state<<endl
		<<"leastBuyin="<<leastBuyin<<endl
		<<"pwin "<<pwin<<" * pot "<<pot<<endl
		<<"/( 1 - pwin"<<pwin<<")"<<endl
		<<"bet= "<<act.bet<<endl;

	dout<<"DECIDE ON "<<act.act<<endl<<endl;
	return act;
}

Action ShrewdPlayer::flopBet()
{
	Action act;

	float pwin;
	int cntPlyrs=0;
	for(int i=0;i<lastrd.size();i++)
		if(lastrd[i].lastAct!=ACT_FOLD)
			cntPlyrs++;

	SimuPlayer sp;
	sp.setPlayers(cntPlyrs);
	sp.setState(state,hole,comm);
	pwin=sp.simulate(800);

	int leastBuyin=getLeastBuyin();
	float potodds=(float)leastBuyin/(leastBuyin+pot);
	if(pwin<potodds) act.act=ACT_FOLD;
	else act.act=ACT_RAISE;
	if(pwin==1.0) act.act=ACT_ALLIN;
	else act.bet=pwin*pot/(1-pwin);

	dout<<pid<<" BET "<<state<<" DECIDE!"<<endl<<endl;
	for(int i=0;i<hole.size();i++)
		dout<<hole[i].print();
	dout<<endl;
	for(int i=0;i<comm.size();i++)
		dout<<comm[i].print();
	dout<<endl;
	dout<<"pwin="<<pwin<<"\tpotodds="<<potodds<<endl
		<<"of "<<cntPlyrs<<"\tin state "<<state<<endl
		<<"leastBuyin="<<leastBuyin<<endl
		<<"pwin "<<pwin<<" * pot "<<pot<<endl
		<<"/( 1 - pwin"<<pwin<<")"<<endl
		<<"bet= "<<act.bet<<endl;

	dout<<"DECIDE ON "<<act.act<<endl<<endl;
	return act;
}
