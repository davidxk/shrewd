#include "ai/AISuite.h"

#include "ai/HoleAnalyzerTest.cpp"

AISuite::AISuite()
{
	addTestCase(new HoleAnalyzerTest);
}
