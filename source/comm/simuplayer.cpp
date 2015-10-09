#include "globals.h"
#include "simuplayer.h"
#include "checkplus.h"
//init the seed and the deck
SimuPlayer::SimuPlayer()
{
	//srand(time(0));
}

void SimuPlayer::setState(int state, vector<Card> hole, vector<Card> comm)
{
	this->state=state;

	this->hole=hole;
	this->reco=comm;

	for(int i=0;i<hole.size();i++)
		seen.push_back(hole[i]);
	for(int i=0;i<comm.size();i++)
		seen.push_back(comm[i]);
}

float SimuPlayer::simulate(int times)
{
	int cntWin=0; float winRate;
	for(int i=0;i<times;i++)
	{
		comm.clear();
		comm=reco;
		initDeck();
		shuffle();
		deal();
		switch(state)
		{
			case D_BET: 
			case DEAL: flop();
			case F_BET:
			case FLOP: turn();
			case T_BET:
			case TURN: river();
			case R_BET:
			case RIVER: 
			default: break;
		}
		
		mainWin=isWin();
		if(mainWin) cntWin++;
		oppoHole.clear();
	}
	winRate=(float)cntWin/times;
	if(winRate==0.0) cout<<state<<endl;
	return winRate;
}



void SimuPlayer::deal()
{
	oppoHole.clear();
	for(int i=0;i<(nPlayers-1)*2;i++)
	{
		dealNextUnseen(oppoHole);
	}
}

bool SimuPlayer::isWin()
{
	//whenever in isWin, comm==5
	vector<Card> set;
	for(int i=0;i<comm.size();i++)
		set.push_back(comm[i]);
	
	//check my Hand here
	set.push_back(hole[0]);
	set.push_back(hole[1]);
	myHand=CheckerPlus::checkHand(set);
	set.pop_back();
	set.pop_back();

	oppoHand.clear();
	bool win=true;
	for(int i=0;i<nPlayers-1;i++)
	{
		//check opponents' Hand here
		set.push_back(oppoHole[2*i]);
		set.push_back(oppoHole[2*i+1]);
		Hand anOppoHand=CheckerPlus::checkHand(set);
		oppoHand.push_back(anOppoHand);
		set.pop_back();
		set.pop_back();

		if(myHand.compare(&anOppoHand)!=1) //one lose then lose
			win=false;
	}
	return win;
}





void SimuPlayer::flop()
{
	comm.clear();
	dealNextUnseen(comm);
	dealNextUnseen(comm);
	dealNextUnseen(comm);
}

void SimuPlayer::turn()
{
	dealNextUnseen(comm);
}

void SimuPlayer::river()
{
	dealNextUnseen(comm);
}

void SimuPlayer::dealNextUnseen(vector<Card>& vec)
{
	bool isSeen;
	for(int i=deck.size()-1;i>=0;i--)
	{
		isSeen=false;
		for(int j=0;j<seen.size();j++)
			if(deck[i].is(seen[j]))
				isSeen=true;
		if(isSeen) 
		{
			deck.pop_back();
			continue;
		}

		vec.push_back(deck[i]);
		deck.pop_back();
		break;
	}
}

void SimuPlayer::print()
{
	cout<<"Comm: \t";
	for(int i=0;i<comm.size();i++)
		comm[i].print();
	cout<<endl
		<<"Main: \t";
	for(int i=0;i<hole.size();i++)
		hole[i].print();
	cout<<"\n\t"; 
	myHand.print();
	cout<<endl
		<<"Oppo: \t";
	for(int i=0;i<oppoHole.size()/2;i++)
	{
		for(int j=0;j<2;j++)
			oppoHole[2*i+j].print();
		cout<<"\t";
	}
	cout<<"\n\t";
	for(int i=0;i<oppoHand.size();i++)
	{
		oppoHand[i].print();
		cout<<'\t';
	}
	cout<<endl;
	if(mainWin) cout<<"Win"<<endl<<endl;
	else cout<<"Lose (or Tie)"<<endl<<endl;
}
