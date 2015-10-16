VPATH = ../../comm/ ../../model/ ../../
object = testParser.o parser.o\
		 card.o rdstate.o action.o plyrinfo.o common.o

testParser: $(object)
	c++ -o testParser $(object)
testParser.o: parser.o
parser.o: card.o rdstate.o common.o
card.o:
rdstate.o: action.o plyrinfo.o common.o
action.o:
plyrinfo.o:
common.o:

.PHONY: clean
clean:
	rm testParser $(object)
