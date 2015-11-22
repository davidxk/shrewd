#include "comm/CommSuite.h"

#include "comm/ScannerTest.cpp"
#include "comm/ParserTest.cpp"

CommSuite::CommSuite()
{
	addTestCase(new ScannerTest);
	addTestCase(new ParserTest);
}
