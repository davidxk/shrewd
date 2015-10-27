VPATH = ../../comm/ ../../model/ ../../plyr/ ../../ 

object2 = testPlyr.o parser.o\
		  scanner.o mailman.o folder.o player.o\
		  card.o rdstate.o action.o plyrinfo.o common.o

testPlyr: $(object2)
	c++ -o testPlyr $(object2)


scanner.o: card.o rdstate.o common.o
rdstate.o: action.o plyrinfo.o common.o

parser.o: common.o
folder.o: player.o


.PHONY: clean
clean:
	rm testPlyr $(object2)
