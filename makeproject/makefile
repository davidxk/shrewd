VPATH=../source
objects=main.o plyrshel.o simuplayer.o player.o rdstate.o plyrinfo.o card.o mailman.o simu.o hand.o checkplus.o shrewdpl.o snorepl.o

game: $(objects)
	g++ -ggdb3 -o ../target/game $(objects)

main.o:main.cpp plyrshel.o
plyrshel.o:plyrshel.cpp plyrshel.h player.o mailman.o shrewdpl.o snorepl.o
shrewdpl.o:shrewdpl.cpp shrewdpl.h player.o simuplayer.o card.o
snorepl.o:snorepl.cpp snorepl.h player.o simuplayer.o card.o
simuplayer.o:simuplayer.cpp simuplayer.h card.o hand.o simu.o
simu.o: simu.cpp simu.h card.o
player.o:player.cpp player.h card.o plyrinfo.o rdstate.o
mailman.o:mailman.cpp mailman.h 
plyrinfo.o:plyrinfo.cpp plyrinfo.h 
rdstate.o:rdstate.cpp rdstate.h
checkplus.o:checkplus.cpp checkplus.h card.o hand.o
card.o:card.cpp card.h
hand.o:hand.cpp hand.h

.PHONY: clean
clean:
	rm ../target/game $(objects)
