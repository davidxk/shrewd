VPATH = ../../source/comm/ ../../source/model/ ../../source/data/ ../../source/ ../../source/ai/
CXX=g++
CXXFLAGS=-I ../../source/

object2 = testParser.o Parser.o\
		  Scanner.o Mailman.o folder.o plyr.o\
		  Card.o RdState.o Action.o PlayerInfo.o common.o\
		  ShowdownInfo.o TableInfo.o RoundUtil.o
object1 = testScanner.o Scanner.o\
		  Card.o RdState.o Action.o PlayerInfo.o common.o

testParser: $(object2)
	g++ -o testParser $(object2)
testScanner: $(object1)
	g++ -o testScanner $(object1)

testScanner.o: Scanner.o
Scanner.o: Card.o RdState.o common.o
RdState.o: Action.o PlayerInfo.o common.o

Parser.o: common.o
folder.o: plyr.o

.PHONY: clean
clean:
	rm -f testParser testScanner $(object1) $(object2)
