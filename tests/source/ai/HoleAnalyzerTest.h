#ifndef _HOLE_ANALYZER_TEST_
#define _HOLE_ANALYZER_TEST_

#include "ai/HoleAnalyzer.h"

#include <cassert>
#include "TestCase.h"
#include "model/Card.h"

class HoleAnalyzerTest: public TestCase
{
public:
	virtual int runTest() override;
private:
	void testWinrate();
	void testHandType();
	void testHandCtgr();
};
#endif
