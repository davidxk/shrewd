#include "HoleAnalyzerTest.h"
#include <iostream>

int HoleAnalyzerTest::runTest()
{
	testWinrate();
	testHandType();
	testHandCtgr();
	return 0;
}



void HoleAnalyzerTest::testWinrate()
{
	HoleAnalyzer ha;
	vector<vector<Card> > testcase;
	testcase.resize(3);

	testcase[0].push_back( Card::getCard('h', Card::KING) );
	testcase[0].push_back( Card::getCard('s', Card::KING) );
	assert(ha.printSHand(testcase[0])=="KK ");
	assert(ha.getWinRate(testcase[0], 10)==26.49f);

	testcase[1].push_back( Card::getCard('c', Card::TEN) );
	testcase[1].push_back( Card::getCard('c', Card::ACE) );
	assert(ha.printSHand(testcase[1])=="ATs");
	assert(ha.getWinRate(testcase[1], 2)==65.84f);

	testcase[2].push_back( Card::getCard('d', 4) );
	testcase[2].push_back( Card::getCard('s', 8) );
	assert(ha.printSHand(testcase[2])=="84o");
	assert(ha.getWinRate(testcase[2], 6)==12.65f);
}

void HoleAnalyzerTest::testHandType()
{
	HoleAnalyzer ha;
	vector<vector<Card> > testcase;
	testcase.resize(6);

	//POWERHOUSE
	testcase[0].push_back( Card::getCard('h', Card::KING) );
	testcase[0].push_back( Card::getCard('s', Card::KING) );
	assert(ha.getHandCtgr(testcase[0]) == HoleAnalyzer::MONSTERS);
	assert(ha.getHandType(testcase[0]) == HoleAnalyzer::POWERHOUSE);

	testcase[1].push_back( Card::getCard('d', Card::ACE) );
	testcase[1].push_back( Card::getCard('d', Card::QUEEN) );
	assert(ha.getHandCtgr(testcase[1]) == HoleAnalyzer::BIG_SU_BRDWY);
	assert(ha.getHandType(testcase[1]) == HoleAnalyzer::POWERHOUSE);
	//SPECULATIVE
	testcase[2].push_back( Card::getCard('h', 4) );
	testcase[2].push_back( Card::getCard('d', 4) );
	assert(ha.getHandCtgr(testcase[2]) == HoleAnalyzer::SMA_PAIRS);
	assert(ha.getHandType(testcase[2]) == HoleAnalyzer::SPECULATIVE);

	testcase[3].push_back( Card::getCard('h', 7) );
	testcase[3].push_back( Card::getCard('h', 8) );
	assert(ha.getHandCtgr(testcase[3]) == HoleAnalyzer::SUITED_CONN);
	assert(ha.getHandType(testcase[3]) == HoleAnalyzer::SPECULATIVE);



	//TOP_PAIR
	testcase[4].push_back( Card::getCard('d', Card::ACE) );
	testcase[4].push_back( Card::getCard('c', Card::JACK) );
	assert(ha.getHandCtgr(testcase[4]) == HoleAnalyzer::BIG_OFF_BRDWY);
	assert(ha.getHandType(testcase[4]) == HoleAnalyzer::TOP_PAIR);

	testcase[5].push_back( Card::getCard('h', Card::ACE) );
	testcase[5].push_back( Card::getCard('d', Card::KING) );
	assert(ha.getHandCtgr(testcase[5]) == HoleAnalyzer::BIG_OFF_BRDWY);
	assert(ha.getHandType(testcase[5]) == HoleAnalyzer::TOP_PAIR);
}

void HoleAnalyzerTest::testHandCtgr()
{
	HoleAnalyzer ha;
	vector<vector<Card> > testcase;
	testcase.resize(11);

	//PAIRS
	testcase[0].push_back( Card::getCard('d', Card::QUEEN) );
	testcase[0].push_back( Card::getCard('h', Card::QUEEN) );
	assert(ha.getHandCtgr(testcase[0]) == HoleAnalyzer::BIG_PAIRS);
	assert(ha.getHandType(testcase[0]) == HoleAnalyzer::NOT_TYPICAL);

	testcase[1].push_back( Card::getCard('d', 9) );
	testcase[1].push_back( Card::getCard('c', 9) );
	assert(ha.getHandCtgr(testcase[1]) == HoleAnalyzer::MID_PAIRS);
	assert(ha.getHandType(testcase[1]) == HoleAnalyzer::NOT_TYPICAL);

	testcase[2].push_back( Card::getCard('c', 4) );
	testcase[2].push_back( Card::getCard('s', 4) );
	assert(ha.getHandCtgr(testcase[2]) == HoleAnalyzer::SMA_PAIRS);
	assert(ha.getHandType(testcase[2]) == HoleAnalyzer::SPECULATIVE);



	//SUITED
	testcase[3].push_back( Card::getCard('h', Card::KING) );
	testcase[3].push_back( Card::getCard('h', Card::TEN) );
	assert(ha.getHandCtgr(testcase[3]) == HoleAnalyzer::LTL_SU_BRDWY);
	assert(ha.getHandType(testcase[3]) == HoleAnalyzer::NOT_TYPICAL);

	testcase[4].push_back( Card::getCard('s', Card::ACE) );
	testcase[4].push_back( Card::getCard('s', 9) );
	assert(ha.getHandCtgr(testcase[4]) == HoleAnalyzer::SUITED_ACES);
	assert(ha.getHandType(testcase[4]) == HoleAnalyzer::NOT_TYPICAL);

	testcase[5].push_back( Card::getCard('d', Card::KING) );
	testcase[5].push_back( Card::getCard('d', 8) );
	assert(ha.getHandCtgr(testcase[5]) == HoleAnalyzer::SUITED_KINGS);
	assert(ha.getHandType(testcase[5]) == HoleAnalyzer::NOT_TYPICAL);

	testcase[6].push_back( Card::getCard('c', 5) );
	testcase[6].push_back( Card::getCard('c', 8) );
	assert(ha.getHandCtgr(testcase[6]) == HoleAnalyzer::JUNK_HAND);
	assert(ha.getHandType(testcase[6]) == HoleAnalyzer::NOT_TYPICAL);

	testcase[7].push_back( Card::getCard('d', Card::QUEEN) );
	testcase[7].push_back( Card::getCard('d', 9) );
	assert(ha.getHandCtgr(testcase[7]) == HoleAnalyzer::SUITED_CONN);
	assert(ha.getHandType(testcase[7]) == HoleAnalyzer::SPECULATIVE);



	//OFF_SUITED
	testcase[8].push_back( Card::getCard('s', Card::QUEEN) );
	testcase[8].push_back( Card::getCard('d', Card::JACK) );
	assert(ha.getHandCtgr(testcase[8]) == HoleAnalyzer::LTL_OFF_BRDWY);
	assert(ha.getHandType(testcase[8]) == HoleAnalyzer::NOT_TYPICAL);

	testcase[9].push_back( Card::getCard('d', Card::ACE) );
	testcase[9].push_back( Card::getCard('c', Card::TEN) );
	assert(ha.getHandCtgr(testcase[9]) == HoleAnalyzer::LTL_OFF_BRDWY);
	assert(ha.getHandType(testcase[9]) == HoleAnalyzer::NOT_TYPICAL);

	testcase[10].push_back( Card::getCard('s', Card::JACK) );
	testcase[10].push_back( Card::getCard('c', 9) );
	assert(ha.getHandCtgr(testcase[10]) == HoleAnalyzer::JUNK_HAND);
	assert(ha.getHandType(testcase[10]) == HoleAnalyzer::NOT_TYPICAL);
}
