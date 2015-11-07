#include "model/Card.h"

int main()
{
	Card cd=Card::getCard('S', Card::ACE);
	cout<<cd.print()<<endl;
	return 0;
}
