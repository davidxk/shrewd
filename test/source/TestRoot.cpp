#include "TestRoot.h"

#include "model/ModelSuite.h"
#include "comm/CommSuite.h"

TestRoot::TestRoot()
{
	testSuites.push_back(new ModelSuite);
	testSuites.push_back(new CommSuite);
}

void TestRoot::runAll()
{
	for(const auto& it: testSuites)
		it->runThisSuite();
}

TestRoot::~TestRoot()
{
	for(auto it: testSuites)
		delete it;
}
