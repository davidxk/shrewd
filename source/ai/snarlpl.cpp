#include "globals.h"
#include "snarlpl.h"
#include "card.h"
#include <cmath>

static ofstream sout;
static ofstream rout;
static ofstream aout;
SnarlPlayer::SnarlPlayer(string pid)
{
	string file="gnar"; file+=pid+".log";
	sout.open(file.c_str());
	rout.open("reflect.log");
	aout.open("mist.log");
	firstTime=false;
}

Action SnarlPlayer::sendBet()
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

Action SnarlPlayer::dealBet()
{
	if(firstTime)
		for(int i=0;i<pstate.size();i++)
			indexOf[i]=pstate[i].pid;

	float ee=getPotOdds();
	int point=getPoint();
	int lstBuyin=getLeastBuyin();
	Action act;
	//A Block For Testing 
	sout<<pid<<" DEAL BET DECIDE!"<<endl;
	sout<<"point: "<<point<<endl;
	sout<<"ee: "<<ee<<endl;
	for(int i=0;i<HOLE_SIZE;i++)
		sout<<hole[i].print();
	sout<<endl;

	switch(point)
	{
		case 0: case 1:
			if(ee<=0.01) act.act=ACT_CALL;
			else act.act=ACT_FOLD;
			break;
		case 2:
			if(ee<=0.05) act.act=ACT_CALL;
			else act.act=ACT_FOLD;
			break;
		case 3: case 4: 
			if(ee<=0.1) act.act=ACT_RAISE,act.bet=2*lstBuyin;
			else if(ee<=0.3) act.act=ACT_CALL;
			else act.act=ACT_FOLD;
			break;
		case 5: case 6:
			if(ee<=0.25)
			{
			   	act.act=ACT_RAISE; 
				act.bet=lstBuyin*pow(((float)point/2),1.5);
			}
			else if(ee<=0.4) act.act=ACT_CALL;
			else act.act=ACT_FOLD;
			break;
		default:
			act.act=ACT_ALLIN;
	}
	if(act.act==ACT_CALL) act.bet=lstBuyin;
	sout<<"DECIDE ON "<<act.act<<" "<<act.bet<<endl<<endl;
	return act;
}

Action SnarlPlayer::flopBet()
{
	float ee=getPotOdds();

	float pwin=1.0, pwin1;
	sp.setPlayers(2);
	sp.setState(state,hole,comm);
	pwin1=sp.simulate(800);

	/*int cntPlyrs=0;
	for(int i=0;i<lastrd.size();i++)
		if(lastrd[i].lastAct!=ACT_FOLD)
			cntPlyrs++;
	pwin=pow(pwin1,cntPlyrs);*/
	for(int i=0;i<lastrd.size();i++)
		if(lastrd[i].lastAct!=ACT_FOLD)
		{
			int perIndex=findIndex(lastrd[i].pid);
			float& bluff=playerBluff[perIndex];
			float& win=playerBluff[perIndex];

			float temp = ( pwin1 + (0.5 - win) ) * ( 1 + bluff );
			temp=temp<1 ? temp:1;
			pwin*=temp;
		}
	
	float rpot;
	int jettonStart=getStartJetton();
	rpot=pot/jettonStart;

	int lstBuy=getLeastBuyin();

	//A Block For Testing 
	sout<<pid<<" FLOP BET DECIDE!"<<endl;
	sout<<"pwin:  "<<pwin<<"\trpot: "<<rpot<<endl
		<<"pot:   "<<pot<<"\tjett: "<<jettonStart<<endl
		<<"pwin1: "<<pwin1<<"\tleastBuyin: "<<lstBuy<<endl;
	for(int i=0;i<HOLE_SIZE;i++)
		sout<<hole[i].print();
	sout<<endl;
	for(int i=0;i<comm.size();i++)
		sout<<comm[i].print();
	sout<<endl;

	Action act;
	int& move=act.act;
	int& amount=act.bet;
	if(pwin>=0.5) 
	{
		if(rpot<=2.0)
		{
			if(ee<=0.3)
			{
				move=ACT_RAISE;
				amount=lstBuy*(1/(1-pwin));
			}
			else move=ACT_CALL;
		}
		else move=ACT_ALLIN;
	}
	else if(pwin>=0.4)
	{
		if(rpot<=1.0)
		{
			if(ee<=0.2)
			{
				move=ACT_RAISE;
				amount=2*lstBuy;
			}
			else move=ACT_CALL;
		}
		else
		{
			if(ee<=0.2)
			{
				move=ACT_RAISE;
				amount=2*lstBuy;
			}
			else move=ACT_ALLIN;
		}
	}
	else if(pwin>=0.3)
	{
		if(rpot<=1.0)
		{
			if(ee<=0.05) move=ACT_CALL;
			else move=ACT_FOLD;
		}
		else 
		{
			if(ee<=(1-1/rpot)) move=ACT_CALL;
			else  move=ACT_FOLD;
		}
	}
	else if(pwin>=0.2)
	{
		if(rpot<=1.0)
		{
			if(ee<=0.01) move=ACT_CALL;
			else move=ACT_FOLD;
		}
		else 
		{
			if(ee<=(1-1/sqrt(rpot))) move=ACT_CALL;
			else  move=ACT_FOLD;
		}
	}
	else 
	{
		if(ee<=0.01) act.act=ACT_CALL;
		else act.act=ACT_FOLD;
	}

	sout<<"DECIDE ON "<<act.act<<endl<<endl;
	return act;
}

int SnarlPlayer::getPoint()
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

void SnarlPlayer::reflect()
{
	for(int i=0;i<MAX_PLAYER;i++)
	{
		for(int j=0;j<action[i].size();j++)
		{
			bool  nextPlayer=false;
			if(action[i].at(j).act==ACT_RAISE||
					action[i].at(j).act==ACT_ALLIN)
			{
				string pid=pstate[i].pid;
				vector<Card> hole=this->opHole[i];
				if(hole.size()==0)
				{
					nextPlayer=true;
					break;
				}	

				vector<Card> comm;
				int state=action[i].at(j).state, nn;
				aout<<"first"<<endl;

				switch(state)
				{
					case D_BET: nn=0; break;
					case F_BET: nn=3; break;
					case T_BET: nn=4; break;
					case R_BET: nn=5; break;
					default: cout<<"Unexpected state "<<state<<endl;
				}
				for(int k=0;k<nn;k++)
					comm.push_back(this->comm[k]);
				int cntPlyrs=cntPlayers(i,j);

				for(int k=0;k<hole.size();k++)
					rout<<hole[k].print();
				rout<<endl;
				for(int k=0;k<nn;k++)
					rout<<comm[k].print();
				rout<<endl;

				//SimuPlayer sp;
				sp.setPlayers(cntPlyrs);
				sp.setState(state,hole,comm);
				float pwin=sp.simulate(300);

				int perIndex=findIndex(pid);
				int& count=cntRaise[perIndex];
				float& bluff=playerBluff[perIndex];
				float& win=playerWin[perIndex];
				aout<<"sec"<<endl;

				if(pwin<0.2) 
					bluff=(bluff*count+pwin)/(float)(count+1);
				else
					win=(win*count+pwin)/(float)(count+1);
				count++;

				rout<<pid<<"\t\tcntRai: "<<count<<endl
					<<"pwin: "<<pwin<<"\tcntPly:"<<cntPlyrs<<endl
					<<"bluff: "<<bluff<<"\twin: "<<win<<endl
					<<"perId: "<<perIndex<<"\tstate"<<state<<endl<<endl;
				for(int i=0;i<hole.size();i++)
					rout<<hole[i].print();
				rout<<endl;
				for(int i=0;i<comm.size();i++)
					rout<<comm[i].print();
				rout<<endl;
				aout<<"last"<<endl;
			}
			if(nextPlayer) break;
		}
	}
}

int SnarlPlayer::cntPlayers(int iPlayer, int jAction)
{
	int cnt=1;
	int start=SBLIND_INDEX, nPlayers=pstate.size();
	start=start % nPlayers;
	for(int i=start;i!=iPlayer;i=(i+1)%nPlayers)
		if(action[i].size()>jAction) //size 3 at(2)
			if(action[i].at(jAction).act!=ACT_FOLD)
				cnt++;
	rout<<"start "<<start<<"\nnPlyer "<<nPlayers<<endl
		<<"iPlyr "<<iPlayer<<"\tjActn "<<jAction<<endl
		<<"cnt "<<cnt;
	for(int i=(iPlayer+1)%nPlayers;i!=start;i=(i+1)%nPlayers)
		if(jAction-1<0)
			cnt++;
		else if(action[i].size()>jAction-1)
			if(action[i].at(jAction-1).act!=ACT_FOLD)
				cnt++;
	return cnt;
}

int SnarlPlayer::findPerPl(string pid)
{
	for(int i=0;i<MAX_PLAYER;i++)
		if(indexOf[i]==pid)
			return i;
	return -1;
}
