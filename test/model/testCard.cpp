#include "globals.h"
#include "model/Card.h"

int main()
{
	Card cd=Card::getCard('S', ACE);
	cout<<cd.print()<<endl;
	return 0;
}
