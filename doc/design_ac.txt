##Requirements
1. Output to specified directory
	√ * obj file to build 
	  * config.* and makefile.* to 
2. Include from different directory
	√ * include from model/ comm/ data/ ai/
	  * include from both source/ and tests/
3. Automate the process
	  * generate template for two Makefile.am file
	  * autoscan at the proper directory
	  * edit the configure.scan file and mv it to .ac
	  * execute autoconf, aclocal, autoheader, automake --foreign --add-missing; interchangeably use autoreconf

But autotools makes the project unbelievably messy and generates incredibly large makefiles that are absolutely unreadable. For this reason, autotools will not be considered for this project, or any other project of mine. 

It does, however, deepened my understanding of make. Make is a automatic build tool that is significant enough as it is. Recall the process of building Blue My Lake. The time it took to build the project, I would say, was more than ineligible. I often go watch my roommates play computer games after hitting the build button. 
But when only a part of the project was changed, only the part that was influence should get recompiled. And you know who decides which part should be recompiled? Make does. So you see, make is doing great work that makes a significant difference in the building process. 
I knew this is make does conceptually, but I never really understood it. Never linked these knowledge together with my practical experiences. 

This understanding makes make seem a lot less terrifying: it's only a file that defines dependence. And the action to be taken in the second line has nothing to do with prerequisites, so it can be left with implicit rules without any more care. So there is only one line that matters for each object file.   

As it appears, both Linux and freeBSD uses make in its original form and no sign of autotools. So I gathered that make may well be the good-enough solution for the problem. 
And also, when I had a better look at make's manual, it appears nowadays, compiler can do the work for us. I have always believed such is their responsibility. So the final answer to this problem may just be the -M option. 
