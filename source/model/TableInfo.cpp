#include "model/TableInfo.h"

TableInfo::TableInfo(std::unordered_map<int, RdState> aLastrd, int aPot):
	lastrd(aLastrd), pot(aPot) { }
