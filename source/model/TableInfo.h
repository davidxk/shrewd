#ifndef _MODEL_TABLE_INFO_H_
#define _MODEL_TABLE_INFO_H_

#include <unordered_map>
#include "model/RdState.h"

class TableInfo
{
public:
	unordered_map<int, RdState> lastrd; 
	int pot;
public:
	TableInfo(std::unordered_map<int, RdState> aLastrd, int aPot);
	string print() const;
};
#endif
