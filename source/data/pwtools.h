
//PlyrWithTools includes a set of tools for the AI system for easy use of data
class PlyrWithTools: public Player
{
public:
	bool isAfterSB(string thePid);
	bool isThisRd(string pid);
	int getLeastBuyin();
	int getStartJetton();
	int getInPlayers();
	float getPotOdds();
	//void rcvGameover();
	int findIndex(string pid);
	virtual void reflect();
};
