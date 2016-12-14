#Comment
* doc: Documentation and all related text files of note, design and plan. 
* libs: external libs 
* makeproject: makefile and object files of the project
* source: the source code in C++
* target: the final executable file of the project
* test: all the test source, makefile, docs and objects
* tools: tools in Perl and Shell script that automates processes


***


##Before 1st Re-org
The project is previously divided into 4 directories. Source contains all source code. Libs is not used. Makeproject contains the object files and makefile. Target contains the single executable file. 

Now there is little doubt that further dividing the source into different directories is a good idea. With model containing the protocol-dependent classes, comm containing the communication subsystem, data containing the data maintenance subsystem and ai comprising the AI subsystem. 

The question now is where to put the test projects. A key point to this problem is the way of writing makefiles. It is desirable that objects should be gathered in the same directory. 

There is little doubt, that the 4 directories will not be enough. At least a doc and a tools directory are needed. 

##Before rejecting autotools
Now that the re-ogr has been done, it seems to be the time to sort out the messy makefiles. It seems 'autotools' can be used to address to this problem. A few tools that keeps popping up are: GNU automake & autoconf, cmake and scons. Cmake seems the best solution, while scons is also commercially used and GNU series is something that's always worth mentioning. 

Makefile is most troublesome to maintain. Autotools may well be the ending solution to this problem, which has been there for ever too long. 

##Re-organizing Tests
After learning about the tests in cocos2d-x, I was for a long time struggling between implementing the tree structure or not in this project. On the one hand, I can see the flexibility it provides to the architecture. On the other, I feel it over-complicates things as there aren't so many test to run, and I don't have any idea how the test-run is related to the tree structure. It made me delay for a long time before re-organizing the tests into one project. 

Yet I just decided one day, that tree or not, I always have to start somewhere. And little by little, I made it into a root-suite-case structure, which require no recursive traversal but is quit enough for the project. 

Up until this day, I still haven't figure out the relationship of test-runs and test case structures. But it doesn't matter that much right now, for it takes no time to finish running all the tests and now I have saved a tremendous amount of time building the test project. You've always got to start somewhere, right?

##Organizing Makefile
After learning about -MM option of compilers, I have put into use the makefile.include file, which automates the makefile generation for every new source file. So adding a new project file simply means changing the sources variable. 

Yet converting from the makefile for the project to the makefile of the tests still takes efforts. Apart from makefile.include file, there is still much things that doesn't change for each project but is not separated from the changing parts. Thus, I separated the two changing parts into isolated makefiles: maintaining the sources variable and the final building of the executable file. After this move, starting writing makefile for a new project become as simple as you can ever imagine. 

And by putting makefile into a separate directory parallel to source directory, I can separate the object files with the source files, which makes the working directory clean. 

But a few optimization remains to be implemented. First, cross-directory makefile referencing, and even sharing of object files between projects. And second, making use of Jenkins for automatic continuous integration. 
