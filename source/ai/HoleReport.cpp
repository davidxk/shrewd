
string HoleReport::printWinRate()
{
	string str="Your starting hand is" + sHand + ". \n";
	str+="Your hole has a " + floatToStr(winRate);
	str+="%% chance of being the best hand on the table. That is ";
	if(winRate >= (float)1/nPlyrs) str+="above ";
	else str+="below ";
	str+="the average " + floatToStr((float)1/nPlyrs) + ". \n";
}

string HoleReport::printHandType(HandType handType)
{
	string str;
	switch(handType)
	{
		case TOP_PAIR: 
			str+="Top Pair";
			break;
		case SPECULATIVE: 
			str+="Speculative Hand";
			break;
		case POWERHOUSE:
			str+="Powerhouse";
			break;
		default:
			str+="Non-profitable Hand";	
	}
	return str;
}

string HoleReport::printHTypeReport()
{
	string str="Your starting hand falls into the type of ";
	str+= printHandType() + ". \n";
	switch(handType)
	{
		case TOP_PAIR: 
			str+="Your pre-flop strategy should be ";
			if(winRate>=winMap["KJo"] || winRate>=winMap["ATo"])
				str+="to leave fewer(2~3) players into flop round. \n";
			else 
				str+="to allow multi-way action while making bigger pot.\n";
			break;
		case SPECULATIVE: 
			if(winRate>=winMap["T9o"] || winRate>=winMap["77"])
				str+="You can afford up to 2 bets to see the flop. \n";
			else
				str+="Your pre-flop strategy should be \
					  to limp in if you are sure the pot will be multi-way. \n";
			break;
		case POWERHOUSE:
			str+="Your pre-flop strategy should be \
				  to create a pot as large as possible. \n"
			break;
		default:
			str+="Your pre-flop strategy should be to fold. \n";	
	}
}
