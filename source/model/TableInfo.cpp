#include "model/TableInfo.h"
#include "common.h"

TableInfo::TableInfo(std::unordered_map<int, RdState> aLastrd, int aPot):
	lastrd(aLastrd), pot(aPot) { }

string TableInfo::print() const
{
	string str;
	for(auto it=lastrd.begin(); it!=lastrd.end(); ++it )
	//for ( const auto& it: lastrd )
		str+=it->second.print();
	str+="Pot: @"+intToStr(pot)+"\n";
	return str;
}
