#include "model/TableInfo.h"
#include "common.h"

TableInfo::TableInfo(std::unordered_map<int, RdState> aLastrd, int aPot):
	lastrd(aLastrd), pot(aPot) { }

string TableInfo::print()
{
	string str;
	for ( auto it = lastrd.begin(); it != lastrd.end(); ++it )
		str+=it->second.print(), str+=intToStr(pot)+"\n";
	return str;
}
