#include "player.h"
#include "../common.h"

//static ofstream pout;
void Player::init()
{
	//pout.open("ply.log");
	for(int i=0;i<MAX_PLAYER;i++)
	{
		action[i].clear();
		opHole[i].clear();
		phand[i]=NOT_THIS_RANK;
		potsh[i]=0;
	}
	comm.clear();
	hole.clear();
	shareOfPot.clear();
	state=DEAL;
	cntRd=0;
	lastNotify=-1;
}

void Player::setReg(char* pid, char* name)
{
	sscanf(pid, "%d", &(this->pid));
	this->name.assign(name);
}

vector<string> Player::sendReg()
{
	vector<string> reg;
	reg.push_back(intToStr(pid));
	reg.push_back(name);
	return reg;
}

void Player::rcvSeat(vector<PlayerInfo> players)
{
	//for(int i=0;i<players.size();i++)
		//for(int j=0;j<pstate.size();j++)
			//if(players[i].pid==pstate.pid)
				//if(!players[i].match(pstate[j]))
					//cout<<"Error: Bad maintanence of player info."<<endl;
	pstate=players;
	//set my state here: jetton and money
	for(int i=0;i<pstate.size();i++)
		if(pstate[i].pid==this->pid)
		{
			jetton=pstate[i].jetton;
			money=pstate[i].money;
			inBet=0;
		}
	//for(int i=0;i<pstate.size();i++)
		//pout<<pstate[i].pid<<"\tjetton "<<pstate[i].jetton<<endl;
}

void Player::rcvHole(vector<Card> hole)
{
	this->hole=hole;
	state=DEAL_BET;
	lstRdJet=jetton;
	tmp=false;
}

void Player::rcvPot(int pot)
{
	this->pot=pot;
}

void Player::rcvFlop(vector<Card> flop)
{
	this->comm=flop;
	state=FLOP_BET;
	lstRdJet=jetton;
	tmp=false;
}

void Player::rcvTurn(Card card)
{
	comm.push_back(card);
	state=TURN_BET;
	lstRdJet=jetton;
	tmp=false;
}

void Player::rcvRiver(Card card)
{
	rcvTurn(card);
	state=RIVER_BET;
	lstRdJet=jetton;
	tmp=false;
}

void Player::rcvLstRound(vector<RdState> lastrd)
{
	this->lastrd=lastrd;
	//reinit my state for round
	for(int i=0;i<lastrd.size();i++)
		if(lastrd[i].pi.pid==pid)
		{
			jetton=lastrd[i].pi.jetton;
			money=lastrd[i].pi.money;
			inBet=lastrd[i].inBet;
		}
	if(!tmp) lstRdBet=inBet;
	tmp=true;
	//for(int i=0;i<lastrd.size();i++)
		//pout<<lastrd[i].pi.pid<<"\tjetton "<<lastrd[i].jetton<<endl
			//<<"inBet "<<lastrd[i].inBet<<"\tisThRd "<<isThisRd(lastrd[i].pi.pid)
			//<<"state "<<lastrd[i].state<<"cntRd "<<cntRd<<endl;
}

void Player::rcvOppoAct(int pid, Action act)
{
	for(int i=0;i<pstate.size();i++)
		if(pstate[i].pid==pid)
		{
			action[i].push_back(act);
			//pout<<pid<<"\t"<<act.act<<"\t"<<act.bet<<endl
				//<<"state "<<act.state<<endl;
			return;
		}
	cout<<"Error: Player "<<pid<<" not found. "<<endl;
}

void Player::rcvPHole(int pid, Card card)
{
	for(int i=0;i<pstate.size();i++)
		if(pstate[i].pid==pid)
		{
			opHole[i].push_back(card);
			return;
		}
	cout<<"Error: Player "<<pid<<" not found. "<<endl;
}

void Player::rcvPHand(int pid, int hand)
{
	for(int i=0;i<pstate.size();i++)
		if(pstate[i].pid==pid)
		{
			phand[i]=hand;
			return;
		}
}

void Player::rcvPotwin(int pid, int share)
{
	for(int i=0;i<pstate.size();i++)
		if(pstate[i].pid==pid)
		{
			potsh[i]=share;
			return;
		}
}

int Player::findIndex(int pid)
{
	for(int i=0;i<pstate.size();i++)
		if(pid==pstate[i].pid)
			return i;
	cout<<"pid in action[] not found in pstate(seat info)"<<endl;
	return -1;
}

void Player::reflect()
{

}

bool Player::isAfterSB(int thePid)
{
	return findIndex(thePid)>=SBLIND_INDEX;
}

bool Player::isThisRd(int pid)
{
	if(cntRd==0)
		return isAfterSB(pid);
	return true;
}

int Player::getLeastBuyin()
{
	int leastBuyin=0;
	if(lastrd[0].state!=state);
	else
		for(int i=0;i<lastrd.size();i++)
			if(isThisRd(lastrd[i].pi.pid))
			{
				if(lastrd[i].lstAct.act==ACT_RAISE||lastrd[i].lstAct.act==ACT_BLIND)
				{
					if(lastrd[i].inBet>leastBuyin)
					leastBuyin=lastrd[i].inBet;
				}
				else if(lastrd[i].lstAct.act==ACT_ALLIN)
				{
					int index=findIndex(lastrd[i].pi.pid);
					if(index==-1) 
						cout<<"Error: SnarePl getLeastBuyin: "
							<<"Player: "<<lastrd[i].pi.pid
							<<" not found in pstate. "<<endl;
					else 
					if(lastrd[index].inBet>leastBuyin)
						leastBuyin=pstate[index].jetton;
				}
			}
	int myInBet=getStartJetton()-jetton;
	return leastBuyin-myInBet;
}

int Player::getStartJetton()
{
	int myIndex=findIndex(this->pid);
	return pstate[myIndex].jetton;
}

int Player::getInPlayers()
{
	int cntFold=0, cntPlyrs;
	for(int i=0;i<lastrd.size();i++)
		if(lastrd[i].lstAct.act==ACT_FOLD)
			cntFold++;
	if(state<=DEAL_BET&&cntRd==0)
		return cntPlyrs=pstate.size()-cntFold;
	else return cntPlyrs=lastrd.size()-cntFold;
}

float Player::getPotOdds()
{
	int leastBuyin=getLeastBuyin();
	float ee=(float)leastBuyin/jetton;
	return ee;
}

Player::~Player()
{

}
