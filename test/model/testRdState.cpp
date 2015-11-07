#include "model/RdState.h"

int main()
{
	RdState rs(PlayerInfo(7777, 30, 250), Action(Action::ACT_RAISE, 100), 0);
	cout<<rs.print()<<endl;
	return 0;
}
