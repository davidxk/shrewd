#ifndef _MODEL_TABLE_INFO_H_
#define _MODEL_TABLE_INFO_H_

#include "model/RdState.h"

class TableInfo
{
public:
	map<int, RdState> lastrd; 
	int pot;

	TableInfo(map<int, RdState> aLastrd, int aPot);
};
#endif
