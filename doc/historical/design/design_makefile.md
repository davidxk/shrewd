## Three Types of Targets
There are three kinds of possible targets in a project. If the project aims at building executable, then the target is a project target and a test target. If the project aims at building a framework, then the target is a test target and a bunch of sample project targets. 

## Inclusion Design
### ./Makefile
* make target
* make test

### ./build/source.mk
* define $proj_path
* list of subsystem names
* adding VPATH -I
* list of source file names

### ./build/makefile
* locate and include source.mk
* Add source containing main()
* Declare name of target
* Define implicit variables for compiling
* The rest stays the same across projects

### ./test/build/test.mk
* list of subsystem names
* adding VPATH -I
* list of source file names
* alter source list
