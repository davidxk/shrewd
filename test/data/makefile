VPATH = ../../source/comm/ ../../source/model/ ../../source/plyr/ ../../source/ 
CXX=g++
CXXFLAGS=-I ../../source/

object2 = testPlyr.o Parser.o\
		  Scanner.o mailman.o folder.o player.o\
		  Card.o RdState.o Action.o PlayerInfo.o common.o

testPlyr: $(object2)
	c++ -o testPlyr $(object2)


Scanner.o: Card.o RdState.o common.o
RdState.o: Action.o PlayerInfo.o common.o

Parser.o: common.o
folder.o: player.o


.PHONY: clean
clean:
	rm -f testPlyr $(object2)
