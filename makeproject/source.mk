## Const Path Variable
src_path=$(proj_path)/source 
model_path=$(addsuffix /model,$(src_path))
comm_path=$(addsuffix /comm,$(src_path))
data_path=$(addsuffix /data,$(src_path))
ai_path=$(addsuffix /ai,$(src_path))

## Implicit Variable
VPATH+=$(src_path) $(model_path) $(comm_path) $(data_path) $(ai_path) 
CXXFLAGS+=-I $(src_path) 

## Source List
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
#TestablePlayer.cpp \
#PsudoMailman.cpp \
