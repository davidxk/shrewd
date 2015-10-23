#include "globals.h"
#include "snarepl.h"
#include "card.h"

ofstream sout;
SnarePlayer::SnarePlayer(string pid)
{
	string file="sna"; file+=pid+".log";
	sout.open(file.c_str());
}

Action SnarePlayer::sendBet()
{
	Action act;
	switch(state)
	{
		case DEAL:
		case D_BET: act=dealBet(); break;
		case FLOP:
		case F_BET: act=flopBet(); break;
		case TURN:
		case T_BET: act=flopBet(); break;
		case RIVER:
		case R_BET: act=flopBet(); break;
		default: break;
	}
	return act;
}

Action SnarePlayer::dealBet()
{
	float ee=getEE();
	int point=getPoint();
	Action act;

	sout<<pid<<" DEAL BET DECIDE!"<<endl;
	sout<<"point: "<<point<<endl;
	sout<<"ee: "<<ee<<endl;
	for(int i=0;i<HOLE_SIZE;i++)
		sout<<hole[i].print();
	sout<<endl;

	if(ee<=0.051) act.act=ACT_CALL;
	else if(ee<=0.3)
	{
		if(point<=2)act.act=ACT_FOLD;
		else act.act=ACT_CALL;
	}
	else
	{
		if(point<4)act.act=ACT_FOLD;
		else if(point<6) act.act=ACT_CALL;
		else
		{
			if(ee>0.9)act.act=ACT_ALLIN;
			else act.act=ACT_RAISE;
			act.bet=getLeastBuyin();
		}
	}
	sout<<"DECIDE ON "<<act.act<<endl;
	return act;
}

Action SnarePlayer::flopBet()
{
	float pwin;
	int cntPlyrs=0;
	for(int i=0;i<lastrd.size();i++)
		if(lastrd[i].lastAct!=ACT_FOLD)
			cntPlyrs++;
	sp.setPlayers(cntPlyrs);
	sp.setState(state,hole,comm);
	pwin=sp.simulate(500);
	float ee=getEE();

	sout<<pid<<" FLOP BET DECIDE!"<<endl;
	sout<<"pwin: "<<pwin<<"\t"<<cntPlyrs<<" players"<<endl;
	sout<<"ee: "<<ee<<endl;
	for(int i=0;i<HOLE_SIZE;i++)
		sout<<hole[i].print();
	sout<<endl;
	for(int i=0;i<comm.size();i++)
		sout<<comm[i].print();
	sout<<endl;

	Action act;
	if(pwin>0.5) act.act=ACT_CALL;
	else if(pwin>0.4)
	{
		if(ee<=0.2)
		{
			act.act=ACT_RAISE;
			act.bet=getLeastBuyin();
		}
		else
			act.act=ACT_CALL;
	}
	else if(pwin>0.3)
	{
		if(ee<=0.2) act.act=ACT_CALL;
		else act.act=ACT_FOLD;
	}
	else if(pwin>0.2)
	{
		if(ee<0.1) act.act=ACT_CALL;
		else act.act=ACT_FOLD;
	}
	else 
	{
		if(ee<0.01) act.act=ACT_CALL;
		else act.act=ACT_FOLD;
	}
	sout<<"DECIDE ON "<<act.act<<endl;
	return act;
}

int SnarePlayer::getPoint()
{
	int point=0;
	//abs
	int abs[15];
	for(int i=0;i<15;i++)
		if(i>=11) abs[i]=i-10; //J
		else abs[i]=0; 
	point+=abs[hole[0].figure];
	point+=abs[hole[1].figure];
	
	//diff
	int diff=hole[0].figure-hole[1].figure;
	diff=diff>0 ? diff:-diff;
	if(diff==0)
	{
		if(hole[0].figure>=11) point+=2;
		else if(hole[0].figure>=6) point+=4;
		else if(hole[0].figure>=2)point+=3;
	}
	else if(diff==1)
		point+=2;
	else if(diff==2)
		point+=1;
	//color
	if(hole[0].color==hole[1].color)
		point+=1;
	return point;
}

float SnarePlayer::getEE()
{
	int leastBuyin=getLeastBuyin();
	float ee=((float)lstRdBet-inBet+leastBuyin)/lstRdJet;
	sout<<"\n(lstRdBet\t"<<lstRdBet<<"\t-inBet\t"<<inBet<<endl
		<<"+lstRaise\t"<<leastBuyin<<"\t)/lsRdJet\t"<<lstRdJet<<endl;
	return ee;
}

