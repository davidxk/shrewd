#include "comm/CommSuite.h"

#include "comm/ScannerTest.cpp"
#include "comm/ParserTest.cpp"
#include "comm/ControllerTest.h"

CommSuite::CommSuite()
{
	addTestCase(new ScannerTest);
	addTestCase(new ParserTest);
	addTestCase(new ControllerTest);
}
