VPATH=../../model/
object1=testPlayerInfo.o plyrinfo.o
object2=testAction.o action.o

testPlayerInfo: $(object1)
	g++ -o testPlayerInfo $(object1)
testPlayerInfo.o: plyrinfo.o 
plyrinfo.o: 


testAction: $(object2)
	g++ -o testAction $(object2)
testAction.o: action.o
action.o:

.PHONY: clean
clean: 
	rm testPlayerInfo $(object1) $(object2)
