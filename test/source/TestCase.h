#ifndef _TESTS_BASE_TEST_
#define _TESTS_BASE_TEST_

#include <cassert>

class TestCase
{
public:
	virtual int runTest()=0;
	virtual ~TestCase() { };
};

#endif
