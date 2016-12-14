##Basic Structure
There are two major targets. One is the client, the other is the test or tests. 

####Elaboration
Prerequisite can be obtained with -MD option of the compiler. Actions to be taken can be generated with the implicit rules. Generic rules can be defined for the targets. 
The basic idea is to start from the basis of what we have and try to make the makefiles shorter in length and rules more general. 
Before we begin, however, it is good practice to first experiment it on learn_make. 


##Structure of four
* makefile: the project path, the executable file with main method and includes
* source.mk: maintains the list of sources, VPATH and -I option
* last.mk: stores the general options for the build 
* makefile.include: stores the commands to build makefile for each source

###makefile
This file contains the executable file information. It is separated from source.mk so that when multiple executable file are needed, one can alway add another makefile without changing the whole makefile structure. 

###source.mk
This file maintains all the information related to the sources. It maintains a variable that contains the list of source code names, it contains the path of sources and it adds the path to VPATH and -I option. Automatic generation of source.mk is possible. 

###last.mk
This file contains all the other information needed for a build. Apart from the build options, which I suppose can be overwritten in makefile, there is nothing to change across projects. 

###makefile.include
This file contains the dot d file generation methods. It should not be changed across projects. 
