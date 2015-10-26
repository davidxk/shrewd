#include "../../globals.h"
#include "../../model/card.h"

int main()
{
	Card cd=Card::getCard('S', ACE);
	cout<<cd.print()<<endl;
	return 0;
}
