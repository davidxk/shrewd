VPATH=../../model/
object1=testPlayerInfo.o plyrinfo.o
object2=testAction.o action.o
object3=testRound.o round.o

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

.PHONY: clean
clean: 
	rm testPlayerInfo testAction testRound $(object1) $(object2) $(object3)
