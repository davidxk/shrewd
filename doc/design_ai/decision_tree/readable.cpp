HAND_TYPE?
=MONSTERS	- RAISE
=BIG_PAIRS	- CNT_RAISE?	=0 - RAISE
							=1 - RAISE
							=d - FOLD
=MID_PAIRS	- CNT_RAISE?	=0 - WHICH_POS?	=EARLY_POS	- CALL
											=MIDDLE_POS	- CNT_LIMP? <2	- RAISE
																	=d	- CALL
											=LATE_POS 	^
											=d			*

							=1 - CNT_COPEN?	>=2			- CALL
											=d 			- EXP_NHAND?	>=5	- CALL
																		=d	- FOLD
							=d - FOLD
=SMA_PAIRS	- CNT_RAISE?	=0 - CALL
							=1 - EXP_NHAND?	>=5	- CALL
											=d	- FOLD
							=d - FOLD
=BIG_SU_BRDWY-CNT_RAISE?	=0 - IS_LOOSE?	=1	- RAISE
											=d	- FOLD
							=1 - FIG_0?		=A	- FIG_1?	=K	- RAISE
															=Q	- CALL
															=J	- EXP_NHAND?	=m	- CALL
																				=d	- FOLD
															=d	- FOLD
											=d	- FOLD
							=d - FOLD
=LTL_SU_BRDWY-CNT_RAISE?	=0 - WHICH_POS?	=EARLY_POS	- CALL
											=MIDDLE_POS	^
											=LATE_POS	- RAISE
											=d			*
							=1 - EXP_NHAND?	=m			- CALL
											=d			- FOLD
							=d - FOLD
=SUITED_ACES -CNT_RAISE?	=0 - IS_AGGR?	=f	- WHICH_POS?	=EARLY_POS	- AVR_BET?	>=3	- FOLD
																						=d	- FIG_1?=8 -CALL
																									=9 ^
																									=d -FOLD
																=MIDDLE_POS	- IS_LOOSE?	=t	- FIG_1?=8 -RAISE
																									=9 ^
																									=d CALL
																						=d	- CALL
																=LATE_POS 	^
																=d			*
											=d - CALL
							=d - FOLD
=SUITED_KINGS-CNT_RAISE?	=0 - WHICH_POS?	=EARLY_POS	- FIG_1?	=9	- CALL
																	=d	- FOLD
											=BUTTON_POS	- CALL
											=d			- FOLD
							=d - FOLD
=SUITED_CONN -CNT_RAISE?	=0 - WHICH_POS?	=EARLY_POS	- IS_AGGR?	=N	- FIG_1?	=9	-FIG_0?	=T - CALL
																								=J ^
																								=d - FOLD
																					=d	FOLD
																	=d	- FOLD
											=BUTTON_POS	- CALL
											=d			- FOLD
							=d - FOLD
=BIG_OFF_BRDWY-CNT_RAISE?	=0 - RAISE
							=1 - FIG_1?		=K			- RAISE
											=Q			- IS_RS_WLD?=t	- RAISE
																	=d	- FOLD
											=d			- FOLD
							=d - FOLD
=LTL_OFF_BRDWY-CNT_RAISE?	=0 - WHICH_POS?	=EARLY_POS	- FIG_0?	=A	- FIG_1?	=T	CALL		
																					=d	FOLD
																	=K	- FIG_1?	=J	CALL
																					=d	FOLD
																	=d	- FOLD
											=BUTTON_POS	- CALL
											=d *
							=d - FOLD
=JUNK_HAND	- FOLD
=NOT_THIS_HOLE^
=d	^


// Readable desicion tree representation 
// Require: 
// * Tabstop=4
// * Columns>108
// Or
// * Substitute all <tab> with <space>
// * Set no wrap
//
// Grammar:
// tree ~ elem
// elem ~ leaf | root
// leaf ~ RAISE | CALL | FOLD
// root ~ test? (oprt valu expr)+ (=d expr)
// test ~ HAND_TYPE | CNT_RAISE | CNT_LIMP | CNT_COPEN | WHICH_POS | FIG_0 | FIG_1 | IS_LOOSE | IS_AGGR | AVR_BET | EXP_NHAND
// oprt ~ = | < | >=
// valu ~ [2-9TJQKA] | N | [tf] | m | HandType | Position
// expr ~ -elem | * | ^
//
// Explaination:
// Every test ends with a =d default choice
// ^ copies the previous behaviour
// * node undefined copy parent default
// If test undefined, apply default behaviour

Node parserElem(const string& text)
{
	Node node;
	string elem=nextWord();
	if( tryNextChar()!='?' )
		node->setData( parseLeaf(elem) );
	else 
	{
		node->setTest( parseTest(elem) );
		nextChar();
		node->setChild( parseChoices(text) );
	}
	return node;
}

int parseLeaf(const string& elem)
{
	switch(elem[0])
	{
		case 'R': return RAISE;
		case 'C': return CALL;
		case 'F': return FOLD;
		default: cout<<"Unrecoginzed action: "<<elem<<endl;
	}
	return FOLD;
}

int parseTest(const string& elem)
{
	switch(elem[4])
	{
		case '_': return HAND_TYPE;
		case 'R': return CNT_RAISE;
		case 'L': return CNT_LIMP;
		case 'C': return CNT_COPEN;
		case 'H': return WHICH_POS;
		case '0': return FIG_0;
		case '1': return FIG_1;
		case 'O': return IS_LOOSE;
		case 'G': return IS_AGGR;
		case 'B': return AVR_BET;
		case 'N': return EXP_NHAND;
		default: cout<<"Unrecoginzed test: "<<elem<<endl;
	}
}

vector<Node> parseChoices(const string& text)
{
	bool end=false; char oprt;
	vector<Node> list;
	while(!end)
	{
		Choice choice;
		choice->setOprt( getOprt(nextChar()) );
		if(tryNextChar()=='d') 
			choice->setOprt(DFLT), end=true;
		choice->setValue( getValue(nextWord()) );

		Node node=getExpr(text);
		node->setChoice(choice);
		list.push_back(node);
	}
	return list;
}

int getOprt(char oprt& choice)
{
	int iOprt=EQ;
	switch(oprt)
	{
		case '<': iOprt=LT; break;
		case '=': iOprt=EQ; break;
		case '>': iOprt=GE; 
				  match('='); break;
		default: cour<<"Unknown test operator: '"<<oprt<<"'\n";
	}
}

int getValue(string sValue)
{
	int iValue;
	if(sValue.size()==1)
	{
		switch(sValue[0])
		{
			case '2': case '3': case '4': case '5': 
			case '6': case '7': case '8': case '9': 
				sscanf(sValue.c_str(), "%d", &iValue);
				break;
			case 'T': iValue=10; break;
			case 'J': iValue=11; break;
			case 'Q': iValue=12; break;
			case 'K': iValue=13; break;
			case 'A': iValue=14; break;
			case 'm': iValue=MULTI_HAND; break;
			case 'N': iValue=VERY_LOOSE; break;
			case 't': iValue=1; break;
			case 'f': case 'd': iValue=0; break;
			default: cout<<"Unknown iValue: '"<<sValue[0]<<"'\n";
		}
	}
	else
	{
		unordered_map<string, int> mapping={
			{"MONSTERS", MONSTERS}, 
			{"BIG_PAIRS", BIG_PAIRS}, 
			{"MID_PAIRS", MID_PAIRS}, 
			{"SMA_PAIRS", SMA_PAIRS}, 
			{"BIG_SU_BRDWY", BIG_SU_BRDWY}, 
			{"LTL_SU_BRDWY", LTL_SU_BRDWY}, 
			{"SUITED_ACES", SUITED_ACES}, 
			{"SUITED_KINGS", SUITED_KINGS}, 
			{"SUITED_CONN", SUITED_CONN}, 
			{"BIG_OFF_BRDWY", BIG_OFF_BRDWY}, 
			{"LTL_OFF_BRDWY", LTL_OFF_BRDWY}, 
			{"JUNK_HAND", JUNK_HAND}, 
			{"NOT_THIS_HOLE", NOT_THIS_HOLE},

			{"EARLY_POS", EARLY_POS}, 
			{"MIDDLE_POS", MIDDLE_POS}, 
			{"LATE_POS", LATE_POS}, 
			{"BUTTON_POS", BUTTON_POS}, 
			{"SBLIND_POS", SBLIND_POS}, 
			{"BBLIND_POS", BBLIND_POS}  
		};
		iValue=mapping[sValue];
	}
	return iValue;
}

Node getExpr(const string& text)
{
	char oprt=nextChar();
	switch(oprt)
	{
		case '-': return parserElem(text); 
		case '^': 
				  //don't know what to do;
				  //break;
		case '*': 
				  //don't know what to do;
				  return Node(FOLD);
		default: cout<<"Unknown operator '"<<oprt<<"'\n";
	}
}



class Node 
{
public:
	Choice choice;
	int testType;
	int result;
	vector<Node> children;

	void setData(int action) { this->result=result; }
	void setTest(int testType) { this->testType=testType; }
	void setChild(vector<Node> childen) { this->children=children; }
	void setChoice(Choice choice) { this->choice=choice; }
	int doTheTest();
}

int Node::doTheTest()
{
	switch(testType)
	{
		case HAND_TYPE: return whichType();
		case CNT_RAISE: return cntAction(RAISE);
		case CNT_LIMP: return cntAction(CALL);
		case CNT_COPEN: return cntCallLstRaise();
		case WHICH_POS: return whichPos();
		case FIG_0: return hole[0].figure; 
		case FIG_1: return hole[1].figure; 
		case IS_LOOSE: return false;	//todo
		case IS_AGGR: return true;		//todo
		case AVR_BET: return 2;			//todo
		case EXP_NHAND: return 2;		//todo 
	}
}

class Choice
{
public:
	int oprt;
	int value;
	bool isMatch();
	void setOprt(int oprt) { this->oprt=oprt };
	void setValue() { this-value=value; }
};

bool Choice::isMatch(int arg)
{
	switch(oprt)
	{
		case GE: return arg>=value;
		case EQ: return arg==value;
		case LT: return arg <value;
		case DFLT: return true;
	}
	return false;
}
