#include "globals.h"
#include "model/Action.h"

int main()
{
	Action act(Action::ACT_RAISE, 100);
	cout<<act.print();
	return 0;
}
