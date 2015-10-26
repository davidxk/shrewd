#include "../../globals.h"
#include "../../model/rdstate.h"

int main()
{
	RdState rs(PlayerInfo(7777, 30, 250), Action(ACT_RAISE, 100), 0);
	cout<<rs.print()<<endl;
	return 0;
}
