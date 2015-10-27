#include "globals.h"
#include "checkplus.h"


void CheckerPlus::sort(vector<Card>& handcard)
{
	for(int i=0;i<handcard.size();i++)
		for(int j=i+1;j<handcard.size();j++)
			if(handcard[i].figure<handcard[j].figure)
				swap(handcard[i],handcard[j]);
}

Hand CheckerPlus::checkHand(vector<Card> handcard)
{
	sort(handcard);
	Hand ret(NOT_THIS_RANK);
	if(checkStraightFlush(handcard,ret))return ret;
	else if(checkFour(handcard,ret))return ret;
	else if(checkFullHouse(handcard,ret))return ret;
	else if(checkFlush(handcard,ret))return ret;
	else if(checkStraight(handcard,ret))return ret;
	else if(checkFlush(handcard,ret))return ret;
	else if(checkTrip(handcard,ret))return ret;
	else if(checkTwoPairs(handcard,ret))return ret;
	else if(checkPair(handcard,ret))return ret;
	else checkHighCard(handcard,ret);
	return ret;
}
//this function does not belong to CheckPlus 
/*void prepare(vector<Card> handcard)
{
	sort(handcard);
	//now find the most frequent color in the five
	int cntColor[N_COLOR]; 
	CheckerPlus::mostColor=FLUSH_IMPOSS;
	for(int i=0;i<N_COLOR;i++)
		cntColor[i]=0;

	for(int i=0;i<COMM_SIZE;i++)
		cntColor[handcard[i].color]++;
	for(int i=0;i<N_COLOR;i++)
		if(cntColor[i]>FLUSH_THRESH)
			CheckerPlus::mostColor=cntColor[i];
	//now cnt figures
	int cntFig[14];
	for(int i=FIGURE_START;i<ACE+1;i++)
		cntFig[i]=0;
	for(int i=0;i<COMM_SIZE;i++)
		cntFig[handcard[i].figure]++;
	for(int i=0;i<COMM_SIZE;i++)
}*/


bool CheckerPlus::checkHighCard(vector<Card> handcard, Hand& ret)
{
	ret.rank=HIGHCARD;
	ret.first.push_back(handcard[HAND_SIZE+HOLE_SIZE-1].figure);
	return true;
}

bool CheckerPlus::checkPair(vector<Card> handcard, Hand& ret) 
{
	//has pair
	for(int i=0;i<handcard.size()-1;i++)
		if(handcard[i].figure==handcard[i+1].figure)
		{
			ret.rank=PAIR;
			ret.first.push_back(handcard[i].figure);
			int cnt=0;
			for(int k=0;k<handcard.size();k++)
				if(handcard[k].figure!=handcard[i].figure)
				{
					ret.first.push_back(handcard[k].figure);
					cnt++;
					if(cnt==3) break; //3+pair=5
				}
			return true;
		}
	return false;
}

bool CheckerPlus::checkTwoPairs(vector<Card> handcard, Hand& ret)
{
	int cntPair=0;
	int same[4];
	for(int i=0;i<handcard.size()-1;i++)
		if(handcard[i].figure==handcard[i+1].figure)
		{
			same[cntPair++]=handcard[i].figure;
			i++;
		}
	if(cntPair>=2)
	{
		ret.rank=TWOPAIRS;
		int max=same[0]>same[1] ? same[0]:same[1];
		ret.first.push_back(max);
		ret.first.push_back(same[0]+same[1]-max);

		int cnt=0;
		for(int k=0;k<handcard.size();k++)
			if(handcard[k].figure!=same[0]&&
					handcard[k].figure!=same[1])
			{
				ret.first.push_back(handcard[k].figure);
				cnt++;
				if(cnt==1) break; //twoPairs+1=5
			}
		return true;
	}
	return false;
}

bool CheckerPlus::checkTrip(vector<Card> handcard, Hand& ret)
{
	//has trip
	for(int i=0;i<handcard.size()-2;i++)
		if(handcard[i].figure==handcard[i+1].figure&&
				handcard[i+1].figure==handcard[i+2].figure)
		{
			ret.rank=TRIP;
			ret.first.push_back(handcard[i].figure);
			int cnt=0;
			for(int k=0;k<handcard.size();k++)
				if(handcard[k].figure!=handcard[i].figure)
				{
					ret.first.push_back(handcard[k].figure);
					cnt++;
					if(cnt==2) break; //trip+2=5
				}
			return true;
		}
	return false;
}

bool CheckerPlus::checkFlush(vector<Card> handcard, Hand& ret)
{
	int mostColor=FLUSH_IMPOSS, theColor;
	findMostColor(handcard,mostColor,theColor);

	int cntGot=0;
	if(mostColor<HAND_SIZE) return false;
	ret.rank=FLUSH;
	for(int i=0;i<handcard.size()&&cntGot<HAND_SIZE;i++)
		if(handcard[i].color==theColor)
		{
			cntGot++;
			ret.first.push_back(handcard[i].figure);
		}
	return true;
}

bool CheckerPlus::checkStraight(vector<Card> handcard, Hand& ret)
{
	int cntCsq=0; int i;
	for(i=0;i<handcard.size()-1;i++)
		if(handcard[i].figure==handcard[i+1].figure+1)
		{
			cntCsq++;
			if(cntCsq==4) break;
		}
		else if(handcard[i].figure==handcard[i+1].figure);
		else cntCsq=0;

	if(cntCsq==4)
	{
		ret.rank=STRAIGHT;
		ret.first.push_back(handcard[i+1].figure);
		return true;
	}

	else 
	if(handcard[0].figure==ACE)
	{
		int fig[HAND_SIZE]={ 5,4,3,2,14 };
		bool has[HAND_SIZE]={ false, false, false, false, false };
		bool smallSt=true;
		for(int i=0;i<handcard.size();i++)
			for(int j=0;j<HAND_SIZE;j++)
				if(handcard[i].figure==fig[j])
					has[j]=true;

		for(int i=0;i<HAND_SIZE;i++)
			smallSt=smallSt&&has[i];
		if(smallSt)
		{
			ret.rank=STRAIGHT;
			ret.first.push_back(1);
			return true;
		}
	}
	return false;
}

bool CheckerPlus::checkFullHouse(vector<Card> handcard, Hand& ret)
{
	bool seeTwo=false, getTwo=false, getThree=false;
	int twoIndex, threeIndex;
	for(int i=0;i<handcard.size()-1;i++)
	{
		if(handcard[i].figure==handcard[i+1].figure)
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
		twoIndex=handcard.size()-1;
	}

	if(!getTwo||!getThree) return false;
	ret.rank=FULLHOUSE;
	ret.first.push_back(handcard[threeIndex].figure);
	ret.first.push_back(handcard[twoIndex].figure);
	return true;
}

bool CheckerPlus::checkFour(vector<Card> handcard, Hand& ret)
{
	for(int i=0;i<handcard.size()-3;i++)
		if(handcard[i].figure==handcard[i+1].figure&&
				handcard[i+1].figure==handcard[i+2].figure&&
				handcard[i+2].figure==handcard[i+3].figure)
		{
			ret.rank=FOUR;
			ret.first.push_back(handcard[i].figure);
			for(int k=0;k<handcard.size();k++)
				if(handcard[k].figure!=handcard[i].figure)
				{
					ret.first.push_back(handcard[k].figure);
					break;
				}
			return true;
		}
	return false;
}

bool CheckerPlus::checkStraightFlush(vector<Card> handcard, Hand& ret)
{
	int mostColor=FLUSH_IMPOSS, theColor;
	findMostColor(handcard,mostColor,theColor);
	
	if(mostColor<5)return false;

	int cntCsq=0, last; bool first=true; int i;
	for(i=0;i<handcard.size();i++)
		if(handcard[i].color==theColor && first)
		{
			last=handcard[i].figure;
			first=false;
		}
		else if(handcard[i].color==theColor) //but not first
		{
			if(handcard[i].figure==last-1)
			{
				cntCsq++;
				last=handcard[i].figure;
				if(cntCsq==4) break;
			}
			else
			{
				last=handcard[i].figure;
				cntCsq=0;
			}	
		}
	if(cntCsq==4)
	{
		ret.rank=STRAIGHTFLUSH;
		ret.first.push_back(handcard[i].figure);
		return true;
	}
	else 
	if(handcard[0].figure==ACE)
	{
		int fig[HAND_SIZE]={ 5,4,3,2,14 };
		bool has[HAND_SIZE]={ false, false, false, false, false };
		bool smallSt=true;
		for(int i=0;i<handcard.size();i++)
			for(int j=0;j<HAND_SIZE;j++)
				if(handcard[i].figure==fig[j]&&
						handcard[i].color==theColor)
					has[j]=true;

		for(int i=0;i<HAND_SIZE;i++)
			smallSt=smallSt&&has[i];
		if(smallSt)
		{
			ret.rank=STRAIGHTFLUSH;
			ret.first.push_back(1);
			return true;
		}
	}
	return false;
}

void CheckerPlus::findMostColor(vector<Card> handcard,int& mostColor,int& theColor)
{
	int cntColor[N_COLOR]; 
	mostColor=FLUSH_IMPOSS;
	for(int i=0;i<N_COLOR;i++)
		cntColor[i]=0;

	for(int i=0;i<handcard.size();i++)
		cntColor[handcard[i].color]++;
	for(int i=0;i<N_COLOR;i++)
		if(cntColor[i]>FLUSH_THRESH)
		{
			mostColor=cntColor[i];
			theColor=i;
		}
}
