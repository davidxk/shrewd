## Const Path Variable
src_path=../../source 
model_path=$(addsuffix /model,$(src_path))
comm_path=$(addsuffix /comm,$(src_path))
data_path=$(addsuffix /data,$(src_path))
ai_path=$(addsuffix /ai,$(src_path))

## Implicit Variable
VPATH+=$(src_path) $(model_path) $(comm_path) $(data_path) $(ai_path)
CXX=g++
CXXFLAGS=-I ../../source -g

## Source List
sources=common.cpp \
Action.cpp \
Card.cpp \
Hand.cpp \
PlayerInfo.cpp \
RdState.cpp \
RoundUtil.cpp \
ShowdownInfo.cpp \
TableInfo.cpp 

## .o & .d List
objects=$(subst .cpp,.o,$(sources))
mkfiles=$(subst .cpp,.d,$(sources))



object1=testPlayerInfo.o PlayerInfo.o common.o
testPlayerInfo: $(object1)
	g++ -o $@ $^

object2=testAction.o Action.o common.o
testAction: $(object2)
	g++ -o $@ $^

object3=testRoundUtil.o RoundUtil.o
testRoundUtil: $(object3)
	g++ -o $@ $^

object4=testRdState.o RdState.o PlayerInfo.o Action.o common.o
testRdState: $(object4)
	g++ -o $@ $^

object5=testCard.o Card.o
testCard: $(object5)
	g++ -o $@ $^

object6=testHand.o Hand.o Action.o common.o
testHand: $(object6)
	g++ -o $@ $^


each: testPlayerInfo testAction testRdState testCard testHand 
#testRoundUtil 

.PHONY: clean
clean: 
	rm -f testPlayerInfo testAction testRoundUtil testRdState testCard\
		$(objects) $(mkfiles)
