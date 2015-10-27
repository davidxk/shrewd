#include "snowpl.h"

static ifstream sin;
SnowPlayer::SnowPlayer(string pid)
{
	string file="wins.txt";
	sin.open(file.c_str());

	for(int i=2;i<=MAX_PLAYER;i++)
	{
		int round;
		sin>>round; 
		for(int j=0;j<N_START_HAND;j++)
		{
			char fig[2], tt; float pp;
			sin>>fig[0]>>fig[1]>>tt>>pp;

			StartHand sh;
			if(tt==' ') sh.isSuited=false;
			else sh.isSuited=true;
			for(int i=0;i<HOLE_SIZE;i++)
			{
				int& pt=sh.figure[i];
				switch(fig[i])
				{
					case '2': case '3': case '4': case '5': case '6': 
					case '7': case '8': case '9': pt=fig[i]-'0'; break;

					case 'T': pt=10; break;
					case 'J': pt=11; break;
					case 'Q': pt=12; break;
					case 'K': pt=13; break;
					case 'A': pt=14; break;
					default: cout<<"Error: Unknown fig '"<<fig[i]
							 <<"' in wins. "<<endl;
				}
			}
			sh.pwin=pp;
			PWins[round].push_back(sh);
		}
	}
}

Action SnowPlayer::sendBet()
{
	Action act;
	switch(state)
	{
		//case D_BET: act=dealBet(); break;
		//case F_BET: act=flopBet(); break;
		//case T_BET: act=flopBet(); break;
		//case R_BET: act=flopBet(); break;
		default: break;
	}
	return act;
}

float SnowPlayer::findWins()
{
	bool isSuited=hole[0].color==hole[1].color;
	int cntPlyrs=getInPlayers();
	if(hole[0].figure>hole[1].figure) swap(hole[0],hole[1]);
	for(int i=0;i<N_START_HAND;i++)
		if(PWins[cntPlyrs].at(i).figure[0]==hole[0].figure
				&&PWins[cntPlyrs].at(i).figure[1]==hole[1].figure
				&&PWins[cntPlyrs].at(i).isSuited==isSuited)
			return PWins[cntPlyrs].at(i).pwin;
	cout<<"Error: Starting hand not found. "<<endl;
	return 0.0;
}
