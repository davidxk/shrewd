
enum HandType { MONSTERS, BIG_PAIRS, MID_PAIRS, SMA_PAIRS, BIG_SU_BRDWY, LTL_SU_BRDWY, SUITED_ACES, SUITED_CONN, BIG_OFF_BRDWY, LTL_OFF_BRDWY, JUNK_HAND, NOT_THIS_HOLE };

enum Position { EARLY_POS, MIDDLE_POS, LATE_POS, BUTTON_POS, SBLIND_POS, BBLIND_POS };

enum RaiseCnt { UNRAISED=0, RAISED=1, RE_RAISED=2, RE_RE_RAISED=3 }

enum AnalActType { BLIND, LIMP_IN=0, OPEN=1, CALL_OPEN=-1, RE_RAISE=2, CALL_RERAISE=-2, RE_RE_RAISE=3, CALL_RE_RE=-3, RE_RE_RE=4, CALL_RERERE=-4, FOLD }; 

//Use the following info to decide
//How many raise before me
int cntAction(vector<RdState>& rdRecords, Action::ACT theAct)
{
	int cnt=0;
	for(const auto& rcd: rdRecords)
		if(rcd.act==theAct) cnt++;
	return cnt;
}
//Name of Early Middle and Late of Position
Seat whichPos(int seatNo)
{
	switch(seatNo)
	{
		case SBLIND_INDEX: case BBLIND_INDEX: case UTG_INDEX:
		case UTG_1_INDEX: case UTG_2_INDEX: 
			return EARLY_POS;
		case MID_1_INDEX: case MID_2_INDEX: case HIJACL_INDEX:
			return MIDDLE_POS;
		case CUTOFF_INDEX: return LATE_POS;
		case DEALER_INDEX: return BUTTON_POS;

		default: cout<<"Unknown seatNo: "<<seatNo<<endl;
				 return EARLY_POS;
	}
}
//Type of Hole
HandType whichType(vector<Card> hole)
{
	if(hole.size()!=HOLE_SIZE) 
		cout<<"Hole size less than two."<<endl, return NOT_THIS_HOLE;

	int& fig0=hole[0].figure, &fig1=hole[1].figure;
	if( fig0 < fig1 ) swap( fig0, fig1 );
	bool suited=hole[0].color==hole[1].color;
	bool isPair=hole[0].figure==hole[1].figure;
	if(isPair)
	{
		switch(fig0)
		{
			case Card::ACE: case Card::KING:
				return MONSTERS;
			case Card::QUEEN: case Card::JACK: case Card::TEN:
				return BIG_PAIRS;
			case 9: case 8: case 7:
				return MID_PAIRS;
			case 6: case 5: case 4: case 3: case 2:
				return SMA_PAIRS;
			default: return NOT_THIS_HOLE;
		}
	}
	else if(suited)
	{
		if( fig0+fig1 >= Card::KING + Card::JACK )
			return BIG_SU_BRDWY;
		else if(fig0+fig1 >= Card::JACK+Card::TEN && fig1 >= Card::TEN)
			return LTL_SU_BRDWY;
		else if(fig0==Card::ACE) return SUITED_ACES;
		else 
		{
			switch(fig0-fig1)
			{
				case 1: if(fig0>=5) return SUITED_CONN;
				case 2: if(fig0>=6) return SUITED_CONN;
				case 3: if(fig0>=9) return SUITED_CONN;
				case 4: if(fig0>=Card::QUEEN) return SUITED_CONN;
				case 5: if(fig0>=Card::JACK) return SUITED_CONN;
			}
		}
	}
	else
	{
		if(fig0+fig1 >= Card::KING+Card::QUEEN) return BIG_OFF_BRDWY;
		else if(fig1 >= Card::TEN) return LTL_OFF_BRDWY;
	}
	return JUNK_HAND;
}

//Reverse
//Cnt name of each action
vector<AnalActType> reviewRd(vector<RdState>& lastrd)
{
	int cntRaise=0, cntCall=0;
	vector<AnalActType> actName;
	for(const auto& it: lastrd)
	{
		switch(it.act)
		{
			case Action::ACT_RAISE: case Action::ACT_ALLIN: //ALLIN
				cntRaise++; 
				actName.push_back( (AnalActType)cntRaise );
				break;
			case Action::ACT_CALL:
				actName.push_back( (AnalActType)-cntRaise );
				break;
			case Action::ACT_BLIND:
				actName.push_back( (AnalActType)BLIND );
				break;
			case Action::ACT_FOLD:
				actName.push_back( (AnalActType)FOLD )
		}
	}
	return actName;
}
//Statistics
//Record how many player enter flop
int rcdPlyrInFlop()
{
	plyrInFlop.push_back(rdu.getNInGame());
}

//main decision making with nested branching
Action::ACT SSHE()
{
	HandType type=whichType(hole);
	Action action;
	int cntRaise=cntAction(lastrd, Action::ACT_RAISE);
	switch(type)
	{
		case MONSTERS:
			action.act=Action::ACT_RAISE;
			//action.bet=??;
			break;
		case BIG_PAIRS:
			switch(cntRaise)
			{
				case 0: case 1:
					action.act=Action::ACT_RAISE;
					//action.bet=??;
					break;
				default: action.act=Action::ACT_FOLD;
			}
			break;
		case MID_PAIRS: playMidPair(cntRaise, action); break;
		case SMA_PAIRS: playSmaPair(cntRaise, action); break;
		case BIG_SU_BRDWY: playBigSuBrdwy(cntRaise, action); break;
	}
}

void playMidPair(int cntRaise, Action& action)
{
	switch(cntRaise)
	{
		case 0:
			switch(whichPos())
			{
				case EARLY_POS:
					action.act=Action::ACT_CALL;
					break;
				case MIDDLE_POS:
					action.act=Action::ACT_RAISE;
					//action.bet=??;
					break;
				case LATE_POS:
			}
			break;
		case 1:
			//if(>=2 CALL_OPEN) action.act=ACT_CALL;
			//or expect to be >=5 handed
			//else action.act=ACT_FOLD;
			break;
		default: action.act=ACT_FOLD;
	}
}

void playSmaPair(int cntRaise, Action& action)
{
	switch(cntRaise)
	{
		case 0:
			action.act=ACT_CALL;
			break;
		case 1:
			//expect to be >=5 handed
			//action.act=ACT_CALL;
			break;
		default: action.act=ACT_FOLD;
	}
}

void playBigSuBrdwy(int cntRaise, Action& action)
{
	int& fig0=hole[0].figure, &fig1=hole[1].figure;
	if( fig0 < fig1 ) swap( fig0, fig1 );

	switch(cntRaise)
	{
		case 0:
			//if(tight) action.act=ACT_CALL; else
			action.act=ACT_RAISE;
			//action.bet=??;
			break;
		case 1:
			if(fig0==Card::ACE)
			{
				//if(raise is from late pos) action.setBet(??);
				switch(fig1)
				{
					case Card::KING: 
						action.act=ACT_RAISE;
						//action.bet=??;
						break;
					case Card::QUEEN:
						action.act=ACT_CALL;
						break;
					case Card::JACK:
						//expect to be multi-handed
						//action.act=ACT_CALL; else 	
						action.act=ACT_FOLD;
						break;
					default: action.act=ACT_FOLD;
				}
			}
			else action.act=ACT_FOLD;
		default: action.act=ACT_FOLD;
	}
}

/*It appears that using a decision table/tree
 * is a better solusion. 
 * Only one iteration needs to be programed
 * All the desision mapping is stored in xml
 * At each node the method provides the info required by the node to go down
 * It is some designing work to do. 
 * */
