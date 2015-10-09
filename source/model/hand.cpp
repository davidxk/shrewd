#include "globals.h"
#include "hand.h"

Hand::Hand()
{
}

Hand::Hand(int rank)
{
	this->rank=rank;
}

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

void Hand::print()
{
	switch(rank)
	{
		case HIGHCARD: cout<<"HghCard"; break;
		case PAIR: cout<<"APair"; break;
		case TWOPAIRS: cout<<"2Pairs"; break;
		case TRIP: cout<<"Three"; break;
		case FLUSH: cout<<"Flush"; break;
		case STRAIGHT: cout<<"Strght"; break;
		case FULLHOUSE: cout<<"FulHose"; break;
		case FOUR: cout<<"Four"; break;
		case STRAIGHTFLUSH: cout<<"StFlush"; break;
		default: cout<<"Error: Unknown Rank of Hand: "<<rank<<endl;
	}
}

void Hand::printDetails()
{
	cout<<"Hand";
	cout<<"  Rank: "<<rank<<endl;
	cout<<"  First: ";
	for(int i=0;i<first.size();i++)
		cout<<first[i]<<" ";
	cout<<endl;
}
