#include "../../globals.h"
#include "../../model/action.h"

int main()
{
	Action act(ACT_RAISE, 100);
	cout<<act.print();
	return 0;
}
