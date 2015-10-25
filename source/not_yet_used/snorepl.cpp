#include "globals.h"
#include "snorepl.h"
#include "card.h"

//static ofstream dout;
SnorePlayer::SnorePlayer(string pid)
{
	//string file="shr"; file+=pid+".log";
	//dout.open(file.c_str());
}

Action SnorePlayer::sendBet()
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

Action SnorePlayer::dealBet()
{
	Action act;

	float pwin;
	int cntFold=0, cntPlyrs=pstate.size();
	//make more when in advantage 
	for(int i=0;i<pstate.size();i++)
	{
		bool found=false;
		for(int j=0;j<lastrd.size();j++)
			if(lastrd[j].pid==pstate[i].pid)
			{
				found=true;
				if(lastrd[j].lastAct==ACT_FOLD)
					cntPlyrs--;
				else if(pstate[i].jetton * 5 < jetton)
					cntPlyrs--;
				break;
			}
		if(found) continue;
		if(pstate[i].jetton * 5 < jetton)
			cntPlyrs--;
	}

	/*for(int i=0;i<lastrd.size();i++)
		if(lastrd[i].lastAct==ACT_FOLD)
			cntFold++;
		else if(pstate[i].jetton * 5 > jetton)
			cntFold++;
	cntPlyrs=pstate.size()-cntFold;*/
	//snow here
	SimuPlayer sp;
	sp.setPlayers(cntPlyrs);
	sp.setState(state,hole,comm);
	pwin=sp.simulate(800);

	int leastBuyin=getLeastBuyin();
	float potodds=(float)leastBuyin/(leastBuyin+pot);
	int bet;
	if(pwin==1.0) act.act=ACT_ALLIN;
	else bet=act.bet=pwin*pot/(1-pwin);

	//call of high hand 
	int& move=act.act;
	if(pwin>potodds)
	{
		if(pwin>1.14/cntPlyrs) move=ACT_RAISE;
		else if(leastBuyin<jetton*0.30) move=ACT_CALL;
		else move=ACT_FOLD;
	}
	else
	{
		if(pwin>1.42/cntPlyrs && pwin>findIndex(pid)/cntPlyrs) 
			move=ACT_RAISE;
		else if(pwin>1.14/cntPlyrs && leastBuyin<jetton*0.15)
			move=ACT_CALL;
		else move=ACT_FOLD;
	}

	if(act.act==ACT_RAISE)
		if(act.bet>jetton*0.4)
			if(leastBuyin<jetton*0.4)
				act.bet=jetton*0.4;

	/*dout<<pid<<" DEAL BET DECIDE!"<<endl;
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
		<<"bet= "<<act.bet<<endl
		<<"cntRd "<<cntRd<<endl;

	dout<<"DECIDE ON "<<act.act<<endl<<endl;*/
	return act;
}

Action SnorePlayer::flopBet()
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
	int& move=act.act;
	if(pwin>potodds)
	{
		if(leastBuyin+inBet<getStartJetton()*pwin)
		{
			if(pwin>1.14/cntPlyrs) move=ACT_RAISE;
			//not positive 
			else if(leastBuyin<jetton*0.30 &&
					pwin>1.0/cntPlyrs) move=ACT_CALL;
			else move=ACT_FOLD;
		}
	}
	else act.act=ACT_FOLD;

	if(pwin==1.0) act.act=ACT_CALL;
	else act.bet=pwin*pot/(1-pwin);

	/*dout<<pid<<" BET "<<state<<" DECIDE!"<<endl<<endl;
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

	dout<<"DECIDE ON "<<act.act<<endl<<endl;*/
	return act;
}
