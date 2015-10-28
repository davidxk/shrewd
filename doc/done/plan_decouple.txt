###Player data members
> Use unordered_map to define standard data object
* unordered_map<int, RdState> plyrStates
* unordered_map<int, ShowdownInfo> pshow

###Player method members
> rcv methods should be viewed as set methods
* 	void rcvSeat(const vector<PlayerInfo>& players); 
* 	void rcvBlind(int bet);
* 	void rcvHole(const vector<Card>& hole);
* 	virtual Action sendBet()=0; //the way player bets differ 
* 
* 	void rcvFlop(const vector<Card>& flop);
* 	void rcvTurn(const Card& card);
* 	void rcvRiver(const Card& card);
* 	void rcvLstRound(const TableInfo& tableInfo);
* 	void rcvShowdown(const unordered_map<int, ShowdownInfo>& shwdMap);
*	void rcvPotwin(const unordered_map<int, int>& potShare);

###Parser methond members
> done
* vector<PlayerInfo> readSeat(string& message)
* int Parser::readBlind(string& message)
* vector<Card> Parser::readHold(string& message)
* TableInfo Parser::readInquire(string& msg, int&)
* vector<Card> Parser::readFlop(string& msg)
* Card Parser::readTurn(string& msg)
* Card Parser::readRiver(string& msg)
* unordered_map<int, ShowdownInfo> Parser::readShowdown(string& msg)
* unordered_map<int, int> Parser::readPotwin(string& message)

###New PODs
> Part of the model
* ShowdownInfo: vector<Card>, int phand, int potsh
* TableInfo: map<int, RdState>, int pot

All done. Pending change in makefile to test. 
