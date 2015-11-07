#include "model/HandChecker.h"

#include "model/Hand.h"

void HandChecker::sort(vector<Card>& cards)
{
	//from BIG to small
	for(int i=0;i<cards.size();i++)
		for(int j=i+1;j<cards.size();j++)
			if(cards[i].figure<cards[j].figure)
				swap(cards[i],cards[j]);
}

Hand HandChecker::checkHand(vector<Card> cards)
{
	sort(cards);
	Hand ret(Hand::NOT_THIS_RANK);
	if(checkStraightFlush(cards, ret))return ret;
	else if(checkFour(cards, ret))return ret;
	else if(checkFullHouse(cards, ret))return ret;
	else if(checkFlush(cards, ret))return ret;
	else if(checkStraight(cards, ret))return ret;
	else if(checkFlush(cards, ret))return ret;
	else if(checkTrip(cards, ret))return ret;
	else if(checkTwoPairs(cards, ret))return ret;
	else if(checkPair(cards, ret))return ret;
	else checkHighCard(cards, ret);
	return ret;
}





bool HandChecker::checkHighCard(vector<Card> cards, Hand& ret)
{
	ret.rank=Hand::HIGHCARD;
	for(int i=0; i<HAND_SIZE; i++)
		ret.first.push_back(cards[i].figure);
	return true;
}

bool HandChecker::checkPair(vector<Card> cards, Hand& ret) 
{
	for(int i=0; i<cards.size()-1; i++)
		if(cards[i].figure==cards[i+1].figure)
		{
			//found pair, is PAIR
			ret.rank=Hand::PAIR;
			ret.first.push_back(cards[i].figure);

			pushRest(cards, ret, i, HAND_SIZE-PAIR_SIZE);
			return true;
		}
	return false;
}

bool HandChecker::checkTwoPairs(vector<Card> cards, Hand& ret)
{
	int cntPair=0, same[4];
	//record all the pairs
	for(int i=0;i<cards.size()-1;i++)
		if(cards[i].figure==cards[i+1].figure)
			same[cntPair++]=cards[i].figure, i++;
	//if cntPair>=2, it is TWOPAIRS
	if(cntPair>=2)
	{
		ret.rank=Hand::TWOPAIRS;
		ret.first.push_back(same[0]);
		ret.first.push_back(same[1]);
		//push one card figure
		for(int k=0;k<handcard.size();k++)
			if(handcard[k].figure!=same[0]&&
					handcard[k].figure!=same[1])
				ret.first.push_back(handcard[k].figure), break; 
		return true;
	}
	return false;
}

bool HandChecker::checkTrip(vector<Card> cards, Hand& ret)
{
	//has trip
	for(int i=0;i<cards.size()-2;i++)
		if(cards[i].figure==cards[i+1].figure&&
				cards[i+1].figure==cards[i+2].figure)
		{
			ret.rank=Hand::TRIP;
			ret.first.push_back(cards[i].figure);

			pushRest(cards, ret, i, HAND_SIZE-TRIP_SIZE);
			return true;
		}
	return false;
}

bool HandChecker::checkFlush(vector<Card> cards, Hand& ret)
{
	int mostColor=0, theColor;
	findMostColor(cards, mostColor, theColor); 
	if(mostColor<HAND_SIZE) return false;
	
	//push five in-order card figures 
	ret.rank=Hand::FLUSH;
	int cntGot=0;
	for(int i=0; i<cards.size(); i++)
		if(cards[i].color==theColor)
		{
			cntGot++;
			ret.first.push_back(cards[i].figure);
			if(cntGot==HAND_SIZE) break;
		}
	return true;
}

bool HandChecker::checkStraight(vector<Card> cards, Hand& ret)
{
	int cntCsq=0; int i;
	for(i=0;i<cards.size()-1;i++)
		if(cards[i].figure==cards[i+1].figure+1)
		{
			cntCsq++;
			if(cntCsq==4) break;
		}
		else if(cards[i].figure==cards[i+1].figure);
		else cntCsq=0;

	if(cntCsq==4)
	{
		ret.rank=Hand::STRAIGHT;
		ret.first.push_back(cards[i+1].figure);
		return true;
	}

	else 
	if(cards[0].figure==Card::ACE)
	{
		int fig[HAND_SIZE]={ 5,4,3,2,14 };
		bool has[HAND_SIZE]={ false, false, false, false, false };
		bool smallSt=true;
		for(int i=0;i<cards.size();i++)
			for(int j=0;j<HAND_SIZE;j++)
				if(cards[i].figure==fig[j])
					has[j]=true;

		for(int i=0;i<HAND_SIZE;i++)
			smallSt=smallSt&&has[i];
		if(smallSt)
		{
			ret.rank=Hand::STRAIGHT;
			ret.first.push_back(1);
			return true;
		}
	}
	return false;
}

bool HandChecker::checkFullHouse(vector<Card> cards, Hand& ret)
{
	bool seeTwo=false, getTwo=false, getThree=false;
	int twoIndex, threeIndex;
	for(int i=0;i<cards.size()-1;i++)
	{
		if(cards[i].figure==cards[i+1].figure)
		{
			if(!seeTwo)
				seeTwo=true;
			else
			{
				getThree=true;
				threeIndex=i;
				seeTwo=false;
			}
		}
		else if(seeTwo) //AAQ
		{
			getTwo=true;
			twoIndex=i;
			seeTwo=false;
		}
	}
	if(seeTwo)
	{
		getTwo=true;
		twoIndex=cards.size()-1;
	}

	if(!getTwo||!getThree) return false;
	ret.rank=Hand::FULLHOUSE;
	ret.first.push_back(cards[threeIndex].figure);
	ret.first.push_back(cards[twoIndex].figure);
	return true;
}

bool HandChecker::checkFour(vector<Card> cards, Hand& ret)
{
	for(int i=0;i<cards.size()-3;i++)
		if(cards[i].figure==cards[i+1].figure&&
				cards[i+1].figure==cards[i+2].figure&&
				cards[i+2].figure==cards[i+3].figure)
		{
			ret.rank=Hand::FOUR;
			ret.first.push_back(cards[i].figure);

			pushRest(cards, ret, i, HAND_SIZE-FOUR_SIZE);
			return true;
		}
	return false;
}

bool HandChecker::checkStraightFlush(vector<Card> cards, Hand& ret)
{
	int mostColor=0, theColor;
	findMostColor(cards,mostColor,theColor);
	
	if(mostColor<5)return false;

	int cntCsq=0, last; bool first=true; int i;
	for(i=0;i<cards.size();i++)
		if(cards[i].color==theColor && first)
		{
			last=cards[i].figure;
			first=false;
		}
		else if(cards[i].color==theColor) //but not first
		{
			if(cards[i].figure==last-1)
			{
				cntCsq++;
				last=cards[i].figure;
				if(cntCsq==4) break;
			}
			else
			{
				last=cards[i].figure;
				cntCsq=0;
			}	
		}
	if(cntCsq==4)
	{
		ret.rank=Hand::STRAIGHTFLUSH;
		ret.first.push_back(cards[i].figure);
		return true;
	}
	else 
	if(cards[0].figure==Card::ACE)
	{
		int fig[HAND_SIZE]={ 5,4,3,2,14 };
		bool has[HAND_SIZE]={ false, false, false, false, false };
		bool smallSt=true;
		for(int i=0;i<cards.size();i++)
			for(int j=0;j<HAND_SIZE;j++)
				if(cards[i].figure==fig[j]&&
						cards[i].color==theColor)
					has[j]=true;

		for(int i=0;i<HAND_SIZE;i++)
			smallSt=smallSt&&has[i];
		if(smallSt)
		{
			ret.rank=Hand::STRAIGHTFLUSH;
			ret.first.push_back(1);
			return true;
		}
	}
	return false;
}





void HandChecker::findMostColor(vector<Card> cards, int& mostColor, Card::Color& theColor)
{
	//Count color. If cntColor[ some color ] >= 4, it is most color
	vector<int> cntColor(Card::N_COLOR, 0);
	for(int i=0; i<cards.size(); i++)
		cntColor[cards[i].color]++;
	for(int i=0; i<Card::N_COLOR; i++)
		if(cntColor[i]>FLUSH_THRESH)
		{
			mostColor=cntColor[i];
			theColor=i;
		}
}

void HandChecker::pushRest(const vector<Card>& cards, Hand& ret, int i, int nPush)
{
	//push nPush in-order card figures
	int cnt=0;
	for(int k=0; k<cards.size(); k++)
		if(cards[k].figure!=cards[i].figure)
		{
			cnt++;
			ret.first.push_back(cards[k].figure);
			if(cnt==nPush) break; 
		}
}
