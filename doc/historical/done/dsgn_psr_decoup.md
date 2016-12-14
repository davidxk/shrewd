vector<PlayerInfo> readSeat(string& message)

int Parser::readBlind(string& message)

vector<Card> Parser::readHold(string& message)

vector<RdState> Parser::readInquire(string& msg, int&)
//TableInfo

vector<Card> Parser::readFlop(string& msg)

Card Parser::readTurn(string& msg)

Card Parser::readRiver(string& msg)

//unordered_map<int, ShowdownInfo> Parser::readShowdown(string& msg)

unordered_map<int, int> Parser::readPotwin(string& message)
