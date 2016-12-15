## List of Source files
sources+=ModelSuite.cpp \
CommSuite.cpp \
AISuite.cpp \
TestCase.cpp \
TestSuite.cpp \
TestRoot.cpp \
ActionTest.cpp \
CardTest.cpp \
HandTest.cpp \
PlayerInfoTest.cpp \
RdStateTest.cpp \
ScannerTest.cpp \
ParserTest.cpp \
HoleAnalyzerTest.cpp \

## The part below does not change across test projects!
## ------------------~~ Dividing Line ~~--------------------
## Const Path Variable
test_src_path=$(this_path)/source
test_sub_path=$(addprefix $(test_src_path)/, $(subsystem))

## Implicit Variable
VPATH+=$(test_src_path) $(test_sub_path) 
CXXFLAGS+=-I $(test_src_path)
