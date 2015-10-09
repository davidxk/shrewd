#ifndef _FOLDER_H_
#define _FOLDER_H_

#include "player.h"
#include "action.h"

//A FoldPlayer folds all the time to test the Shell
class FoldPlayer: public Player
{
public:
	FoldPlayer();
	Action sendBet(); 
};
#endif
