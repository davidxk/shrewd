## Const Path Variable
src_path=../../source 
model_path=$(addsuffix /model,$(src_path))
comm_path=$(addsuffix /comm,$(src_path))
data_path=$(addsuffix /data,$(src_path))
ai_path=$(addsuffix /ai,$(src_path))

test_src_path=../source
test_model_path=$(addsuffix /model,$(test_src_path))
test_comm_path=$(addsuffix /comm,$(test_src_path))
test_data_path=$(addsuffix /data,$(test_src_path))
test_ai_path=$(addsuffix /ai,$(test_src_path))

## Implicit Variable
VPATH+=$(src_path) $(model_path) $(comm_path) $(data_path) $(ai_path)
VPATH+=$(test_src_path) $(test_model_path) $(test_comm_path) \
       $(test_data_path) $(test_ai_path)
CXX=g++
CXXFLAGS=-I $(src_path) -I $(test_src_path) -g -Wall -Wno-c++11-extensions

## Source List
sources=common.cpp \
testPlayer.cpp \
TestablePlayer.cpp \
folder.cpp \
PsudoCtrl.cpp \
PsudoMailman.cpp \
Parser.cpp \
Scanner.cpp \
plyr.cpp \
Action.cpp \
Card.cpp \
Hand.cpp \
PlayerInfo.cpp \
RdState.cpp \
RoundUtil.cpp \
ShowdownInfo.cpp \
TableInfo.cpp \
#TestablePlayer.cpp \
#PsudoMailman.cpp \

## .o & .d List
objects=$(subst .cpp,.o,$(sources))
mkfiles=$(subst .cpp,.d,$(sources))

## Target
game: $(objects)
	$(CXX) -o game $(objects)

## Includes
include makefile.include 
include $(sources:.cpp=.d)	# include the dot d files

##Clean
.PHONY: clean
clean: 
	rm -f game $(objects) $(mkfiles)
