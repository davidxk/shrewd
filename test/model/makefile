VPATH=../../model/ ../../
object1=testPlayerInfo.o plyrinfo.o common.o
object2=testAction.o action.o common.o
object3=testRound.o round.o
object4=testRdState.o rdstate.o plyrinfo.o action.o common.o
object5=testCard.o card.o

testPlayerInfo: $(object1)
	g++ -o testPlayerInfo $(object1)
testPlayerInfo.o: plyrinfo.o 
plyrinfo.o: 


testAction: $(object2)
	g++ -o testAction $(object2)
testAction.o: action.o
action.o:

testRound: $(object3)
	g++ -o testRound $(object3)
testRound.o: round.o
round.o:

testRdState: $(object4)
	g++ -o testRdState $(object4)
testRdState.o: rdstate.o plyrinfo.o action.o
rdstate.o:

testCard: $(object5)
	g++ -o testCard $(object5)
testCard.o: card.o
card.o:

all: testPlayerInfo testAction testRound testRdState testCard

.PHONY: clean
clean: 
	rm testPlayerInfo testAction testRound testRdState testCard\
		$(object1) $(object2) $(object3) $(object4) $(object5)
