#include "TestRoot.h"

#include "ai/AISuite.h"
#include "comm/CommSuite.h"
#include "model/ModelSuite.h"

TestRoot::TestRoot()
{
	testSuites.push_back(new ModelSuite);
	testSuites.push_back(new CommSuite);
	testSuites.push_back(new AISuite);
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
