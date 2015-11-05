#include "ai/TestablePlayer.h"
#include "common.h"

string TestablePlayer::reportGameInfo()
{
	string str="----- Report Game Info -----\n";
	str+="Big Blind:\t"+intToStr(BB)+"\n";
	str+="My Seat:\t"+intToStr(mySeat)+"\nSeat order: ";
	for(int i=0; i<seat.size(); i++)
		str+=intToStr(seat[i])+"\t";
	str+="\n( #Pid, seat ): \n";
	for(auto it = pidToSeat.begin(); it != pidToSeat.end(); ++it)
		str += "( #" + intToStr(it->first) + ", h" +
			intToStr(it->second) + " )\t";
	str+="\nMy Hold: ";
	for(int i=0; i<hole.size(); i++)
		str+=hole[i].print();
	str+="\n";
	return str;
}

string TestablePlayer::reportUpdate()
{
	string str="----- Report Update -----\n";
	str+="State:\t"+intToStr(state)+"\t";
	str+="Pot:\t"+intToStr(pot)+"\t";
	for(int i=0; i<comm.size(); i++)
		str+=comm[i].print();
	str+="\nPlayer States: \n";
	for(auto it = plyrStates.begin(); it != plyrStates.end(); ++it)
		str+=it->second.print();
	str+="\nMy State: \n"+myState.print()+"\nRd Record:\n";

	for(int j=0; j<4; j++)
		for(int i=0; i<rdRecords[j].size(); i++)
			str+=rdRecords[j][i].print();
	return str;
}

string TestablePlayer::reportResult()
{
	string str="----- Report Result -----\n";
	// For the first use, let's write in exemplary form
	for(auto it = shwdMap.begin(); it != shwdMap.end(); it++)
		str+=it->second.print();
	str+="Pot Share:\n";
	// Now it's time to use it in the right way
	for(auto it=potShare.begin(); it!=potShare.end(); ++it)
	//for(const auto& it: potShare )
		str += "( #" +intToStr(it->first)+ ", @" +intToStr(it->second)+ " )\t";
	str+="\n";
	return str;
}

Action TestablePlayer::sendBet()
{
	Action act(ACT_FOLD, 0);
	return act;
}
