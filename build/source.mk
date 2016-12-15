## List of subsystems
subsystem=model comm data ai

## List of Source files
sources+=common.cpp \
folder.cpp \
HoleAnalyzer.cpp \
Controller.cpp \
Mailman.cpp \
Parser.cpp \
Scanner.cpp \
plyr.cpp \
Action.cpp \
Card.cpp \
Hand.cpp \
PlayerInfo.cpp \
RdState.cpp \
RoundUtil.cpp \
ShowdownInfo.cpp \
TableInfo.cpp \


## The part below does not change across projects!
## ------------------~~ Dividing Line ~~--------------------
## Const Path Variable
src_path=$(proj_path)/source
sub_path=$(addprefix $(src_path)/, $(subsystem))

## Implicit Variable
VPATH+=$(src_path) $(sub_path)
CXXFLAGS+=-I $(src_path) 
