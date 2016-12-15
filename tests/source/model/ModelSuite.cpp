#include "model/ModelSuite.h"

#include "model/ActionTest.cpp"
#include "model/CardTest.cpp"
#include "model/HandTest.cpp"
#include "model/PlayerInfoTest.cpp"
#include "model/RdStateTest.cpp"

ModelSuite::ModelSuite()
{
	addTestCase(new ActionTest);
	addTestCase(new CardTest);
	addTestCase(new HandTest);
	addTestCase(new PlayerInfoTest);
	addTestCase(new RdStateTest);
}
