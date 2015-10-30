#include "data/TestalbePlayer.h"
#include "common.h"

string TestalbePlayer::reportGameInfo()
{
	string str="----- Report Game Info -----\n";
	str+="Big Blind:\t"+intToStr(BB)+"\n";
	str+="My Seat:\t"+intToStr(myState)+"\nSeat order: ";
	for(int i=0; i<seat.size(); i++)
		str+=intToStr(seat[i])+"\t";
	str+="\n( #Pid, seat ): \n"
	for(auto it = pidToSeat.begin(); it != pidToSeat.end(); ++it)
		str += "( #" + intToStr(it->first) + ", h" +
			intToStr(it->second) + " )\t";
	str+="\nMy Hold: ";
	for(int i=0; i<hole.size(); i++)
		str+=hole[i].print();
	str+="\n";
	return str;
}

string TestalbePlayer::reportUpdate()
{
	string str="----- Report Update -----\n";
	str+="State:\t"+state;
	str+="Pot:\t"+pot;
	for(int i=0; i<comm.size(); i++)
		str+=comm[i].print();
	str+="\nPlayer States: \n";
	for(auto it = plyrStates.begin(); it != plyrStates.end(); ++it)
		str+=it->second.print();
	str+="\nMy State: \n"+myState.print()+"\nRd Record:\n";

	for(int i=0; i<rdRecords[state].size(); i++)
		str+=rdRecords[state][i].print();
	return str;
}

string TestalbePlayer::reportResult()
{
	string str="----- Report Result -----\n";
	for(auto it = shwdMap.begin(); it != shwdMap.end(); it++)
		str+=it->second.print();
	str+="Pot Share:\n";
	for(auto it = potShare.begin(); it != potShare.end(); it++)
		str += "( #" + it->first + ", @" + it->second + " )\t";
	str+="\n";
	return str;
}
