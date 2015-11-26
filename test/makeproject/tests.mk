## Const Path Variable
test_src_path=$(proj_path)/test/source
test_model_path=$(addsuffix /model,$(test_src_path))
test_comm_path=$(addsuffix /comm,$(test_src_path))
test_data_path=$(addsuffix /data,$(test_src_path))
test_ai_path=$(addsuffix /ai,$(test_src_path))

## Implicit Variable
VPATH+=$(test_src_path) $(test_model_path) $(test_comm_path) \
       $(test_data_path) $(test_ai_path)
CXXFLAGS+=-I $(test_src_path)

## Source List
#$(subst Mailman.cpp,,$(sources))
#$(subst Controller.cpp,,$(sources))

test_suites=ModelSuite.cpp \
	    CommSuite.cpp \
	    AISuite.cpp
test_base=TestCase.cpp \
	  TestSuite.cpp \
	  TestRoot.cpp
test_cases=ActionTest.cpp \
	   CardTest.cpp \
	   HandTest.cpp \
	   PlayerInfoTest.cpp \
	   RdStateTest.cpp \
	   ScannerTest.cpp \
	   ParserTest.cpp \
	   HoleAnalyzerTest.cpp \
	   #PsudoMailman.cpp \
	   #PsudoCtrl.cpp \
	   #TestablePlayer.cpp 
sources+=$(test_base) $(test_suites) $(test_cases)
#testPlayer.cpp \
	#ControllerTest.cpp \
	#BaseTest.h \
