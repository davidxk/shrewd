#include "model/hand.h"
#include "common.h"

Hand::Hand(Rank aRank): rank(aRank) { }

int Hand::compare(Hand* hand)
{
	if(this->rank>hand->rank)
		return 1;
	else if(this->rank<hand->rank)
		return -1;
	//same rank
	for(int i=0;i<first.size();i++)
		if(this->first[i]>hand->first[i])
			return 1;
		else if(this->first[i]<hand->first[i])
			return -1;
	//all the same
	return 0;
}

string Hand::print()
{
	string str;
	switch(rank)
	{
		case HIGHCARD: str="HghCard"; break;
		case PAIR: str="APair"; break;
		case TWOPAIRS: str="2Pairs"; break;
		case TRIP: str="Three"; break;
		case FLUSH: str="Flush"; break;
		case STRAIGHT: str="Strght"; break;
		case FULLHOUSE: str="FulHose"; break;
		case FOUR: str="Four"; break;
		case STRAIGHTFLUSH: str="StFlush"; break;
		default: str="Error: Unknown Rank of Hand: "+intToStr(rank)+"\n";
	}
	return str;
}

void Hand::printDetails()
{
	cout<<"Hand";
	cout<<"  Rank: "<<print()<<endl;
	cout<<"  First: ";
	for(int i=0;i<first.size();i++)
		cout<<first[i]<<" ";
	cout<<endl;
}
