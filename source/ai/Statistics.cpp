#include "Statistics.h"

int Statistics::getPotWay(const vector<vector<RdState> >& rdRecords)
{
	vector<RdState>& flopRd = rdRecords[texas_holdem::FLOP_BET];
	//find openner
	int cntWay = 1;
	int openRid, openner;
	for(int i=0; i<flopRd.size(); i++)
		if(flopRd[i].lstAct.act == Action::ACT_RAISE ||
				flopRd[i].lstAct.act == Action::ACT_ALLIN)
		{
			openRid = i;
			openner = flopRd[i].pi.pid;
			break;
		}
	//find how many followed
	//infinite loop if openner all in, fuck
	for(int i=openRid+1; flopRd[i].pi.pid!=openner; i++)
		if(flopRd[i].lstAct.act != Action::ACT_FOLD)
			cntWay++;
	return cntWay;
}

int Statistics::getNBetsPreflop(const vector<vector<RdState> >& rdRecords)
{
	vector<RdState>& preflop = rdRecords[texas_holdem::PRE_FLOP_BET];

	for(auto it=preflop.end(); it!=preflop.begin; it++)
		if(it.lstAct.act == Action::ACT_CALL)	//caution: is allin call a call?
			return it.inBet;
}

int Statistics::getNRaisePreflop(const vector<vector<RdState> >& rdRecords)
{
	vector<RdState>& preflop = rdRecords[texas_holdem::PRE_FLOP_BET];

	//caution: or is allin call allin?
	int cntRaise=0;
	for(const auto& it: preflop)
		if( it.lstAct.act == Action::ACT_RAISE ||
				it.lstAct.act == Action::ACT_ALLIN )	
			cntRaise++;
	return cntRaise;
}
