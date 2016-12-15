#include "ai/AISuite.h"

#include "ai/HoleAnalyzerTest.h"

AISuite::AISuite()
{
	addTestCase(new HoleAnalyzerTest);
}
