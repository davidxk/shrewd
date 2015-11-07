#Ai System
+Understand the situation
+Analyze the situation
+Choose action accordingly

##Card Analyser
> This analyser only provides discrete quantitative analytics of the cards

##Factors to Consider
###Pre-Flop Bet
- How good is my hole card with nPlyr in consideration
+ Where do I seat
+ What's their action 
- What does it indicate

###Flop Bet
* What is my hand
* Is it a nut hand for now
* Is it a nut hand for the game
- Is it a big hand with nPlyr in consideration
* What are my draws
* What are the psb hands they have
* What are the psb bigger hands than mine
- How likely do they have that hand
* What are the draws they might be waiting for
* What are the draws bigger than my hand they might be waiting for
- How likely do they have that draw
- How likely can they make that hand
- Is he playing by that hold in pre-flop
+ What did they do in this round
+ Where do I seat

##Designed Methods
Hand getHand(comm, hole); //HandChecker
//bool isNutHandNow(comm, hole, myHand);
//bool isNutHandGame(comm, hole, myHand);
private: int allDrawPsbs(comm, hole, nPlyr);
vector<ShowdownInfo> getDraw(comm, hole, myHand);
vector<ShowdownInfo> psbHand(comm, hole);
vector<ShowdownInfo> psbHghrHand(comm, hole, myHand);
vector<ShowdownInfo> psbDraw(comm, hole);
vector<ShowdownInfo> psbHghrDraw(comm, hole, myHand);
private: int allDrawPsbs(comm, hole, nPlyr);

##Implementation
bool isNutHandNow(comm, hole, myHand)
{
	return psbHghrHand(comm, hole, myHand).size()==0;
}

bool isNutHandGame(comm, hole)
{
	return isNutHandNow(comm, hole, myHand) &&
		psbHghrDraw(comm, hold).size()==0;
}

int allDrawPsbs(comm, hole, nPlyr)
{
	int nToDraw=HAND_SIZE-comm.size();
	int nPsb=0;
	int nOnDeck=DECK_SIZE-comm.size()-hole.size();
	for(int i=0; i<nPlyr; i++)
		nPsb+=combination(nOnDeck, HOLE_SIZE), nOnDeck-=2;
	nPsb+=combination(nOnDeck, nToDraw);
	return nPsb;
}

vector<ShowdownInfo> getDraw(comm, hole, myHand);
{
	switch(myHand.rank)
	{
		case HIGHCARD: 
		case PAIR: 
		case TWOPAIRS: 
		case TRIP: 
		case FLUSH: 
		case STRAIGHT: 
		case FULLHOUSE: 
		case FOUR: 
		case STRAIGHTFLUSH: 
	}
}

Draw cards: 3~6
Please, please, PLEASE study the 4 Draw method SEPARATELY
Draw For PAIR:
//Not worth thinking: too many. 

Draw For TWOPAIRS:
<pre-cond: no cntGtTwo>
if no cntEqTwo; then c(cntEqOne(cards), 2) c(3, 1) RestGetOne;
else if cntEqTwo==1; c(cntEqOne(cards), 1) c(3, 1) RestGetOne;
else ???

Draw For TRIP:
<pre-cond: no cntGtTri>
<pre-cond: no TWOPAIRS>
if all cntEqOne; then c(cntEqOne(cards), 1) c(3, 2) RestGetTwo;//full hous
else if cntEqTwo==1; c(cntEqTwo(cards), 1)=1 c(2, 1) RestGetTwo;//full hous
else ???

Draw For STRAIGHT:
???

Draw For FLUSH:
if mostColor<3 return 0;
else 
