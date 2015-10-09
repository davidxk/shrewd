#include "globals.h"
#include "simu.h"

void Simu::initDeck()
{
	deck.clear();
	for(int i=0;i<N_COLOR;i++)
		for(int j=FIGURE_START;j<FIGURE_START+N_FIGURE;j++)
		{
			Card card(i,j);
			deck.push_back(card);
		}
}

void Simu::printDeck()
{
	for(int i=0;i<deck.size();i++)
	{
		if(i%10==0)cout<<endl;
		deck[i].print();
	}
}

void Simu::shuffle()
{
	for(int i=0;i<deck.size();i++)
		swap(deck[i],deck[rand()%deck.size()]);
}

void Simu::setPlayers(int nPlayers)
{
	this->nPlayers=nPlayers;
}
