VPATH = ../../comm/ ../../model/ ../../plyr/ ../../ 
ODIR = obj/

object2 = testParser.o parser.o\
		  scanner.o mailman.o folder.o player.o\
		  card.o rdstate.o action.o plyrinfo.o common.o
object1 = testScanner.o scanner.o\
		  card.o rdstate.o action.o plyrinfo.o common.o

testParser: $(object2)
	c++ -o testParser $(object2)
testScanner: $(object1)
	c++ -o testScanner $(object1)
testScanner.o: scanner.o
scanner.o: card.o rdstate.o common.o
rdstate.o: action.o plyrinfo.o common.o

parser.o: common.o
folder.o: player.o

.PHONY: clean
clean:
	rm testScanner $(object1) $(object2)
