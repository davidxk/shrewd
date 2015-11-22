include source.mk

## Add main Entrance
main=main.cpp 
sources+=$(main)

## Implicit Variable
CXX=g++
CXXFLAGS+=-Wall -Wno-c++11-extensions

## .o & .d List
objects=$(subst .cpp,.o,$(sources))
mkfiles=$(subst .cpp,.d,$(sources))

## Target
game: $(objects)
	$(CXX) -o game $(objects)

## Includes
include makefile.include 
include $(sources:.cpp=.d)	# include the dot d files

##Clean
.PHONY: clean
clean: 
	rm -f $(objects) $(mkfiles) game *.d.*
