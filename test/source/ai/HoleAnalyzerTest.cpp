#include "ai/HoleAnalyzer.h"

#include <cassert>
#include "TestCase.h"
#include "model/Card.h"

class HoleAnalyzerTest: public TestCase
{
public:
	int runTest()
	{
		HoleAnalyzer ha;
		vector<vector<Card> > testcase;
		testcase.resize(3);

		testcase[0].push_back( Card::getCard('h', Card::KING) );
		testcase[0].push_back( Card::getCard('s', Card::KING) );
		testcase[1].push_back( Card::getCard('c', Card::TEN) );
		testcase[1].push_back( Card::getCard('c', Card::ACE) );
		testcase[2].push_back( Card::getCard('d', 4) );
		testcase[2].push_back( Card::getCard('s', 8) );

		assert(ha.printSHand(testcase[0])=="KK ");
		assert(ha.printSHand(testcase[1])=="ATs");
		assert(ha.printSHand(testcase[2])=="84o");
		assert(ha.getWinRate(testcase[0], 10)==26.49);
		assert(ha.getWinRate(testcase[1], 2 )==65.84);
		assert(ha.getWinRate(testcase[2], 6 )==12.65);
		return 0;
	}
};
