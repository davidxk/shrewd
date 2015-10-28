VPATH=../../source/model/ ../../source
CXX=g++
CXXFLAGS=-I ../../source
object1=testPlayerInfo.o PlayerInfo.o common.o
object2=testAction.o Action.o common.o
object3=testRoundUtil.o RoundUtil.o
object4=testRdState.o RdState.o PlayerInfo.o Action.o common.o
object5=testCard.o Card.o

testPlayerInfo: $(object1)
	g++ -o testPlayerInfo $(object1)
testPlayerInfo.o: PlayerInfo.o 

testAction: $(object2)
	g++ -o testAction $(object2)
testAction.o: Action.o

testRoundUtil: $(object3)
	g++ -o testRoundUtil $(object3)
testRoundUtil.o: RoundUtil.o

testRdState: $(object4)
	g++ -o testRdState $(object4)
testRdState.o: RdState.o PlayerInfo.o Action.o

testCard: $(object5)
	g++ -o testCard $(object5)
testCard.o: Card.o


each: testPlayerInfo testAction testRoundUtil testRdState testCard

.PHONY: clean
clean: 
	rm -f testPlayerInfo testAction testRoundUtil testRdState testCard\
		$(object1) $(object2) $(object3) $(object4) $(object5)
