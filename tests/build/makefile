## Provide project path
proj_path=$(shell pwd)/../..
include test.mk

## Add main Entrance
exec=test.out
main=test.cpp 

## Implicit Variable
CXX=g++
CXXFLAGS+=-Wall -Wno-c++11-extensions -g3 -fno-inline


## The part below does not change across projects!
## ------------------~~ Dividing Line ~~--------------------
# Include project source
buil_path=$(proj_path)/build
include $(buil_path)/source.mk

## List of obj Filese
sources+=$(main)
objects=$(subst .cpp,.o,$(sources))
dir_obj=$(addprefix $(OBJECT_DIR)/,$(objects))

## Target Directories
this_path=$(shell pwd)/..
TARGET_DIR=$(this_path)
OBJECT_DIR=$(this_path)/build/.obj
DEPEND_DIR=$(this_path)/build/.d

## Recipe
$(exec): $(objects)
	$(CXX) -o $(TARGET_DIR)/$(exec) $(dir_obj)

## Includes
$(shell mkdir -p $(DEPEND_DIR) >/dev/null)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPEND_DIR)/$*.Td

COMPILE.cc = $(CXX) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
POSTCOMPILE = mv -f $(DEPEND_DIR)/$*.Td $(DEPEND_DIR)/$*.d
OUTPUT_OPTION = -o $(OBJECT_DIR)/$@
%.o : %.cpp
%.o : %.cpp $(DEPEND_DIR)/%.d
	@if ! [[ -d $(OBJECT_DIR) ]]; then mkdir $(OBJECT_DIR); fi
	$(COMPILE.cc) $(OUTPUT_OPTION) $<
	@$(POSTCOMPILE)

$(DEPEND_DIR)/%.d: ;
.PRECIOUS: $(DEPEND_DIR)/%.d

-include $(patsubst %,$(DEPEND_DIR)/%.d,$(basename $(sources)))

##Clean
.PHONY: clean
clean: 
	rm -r -f $(OBJECT_DIR)
	rm -r -f $(DEPEND_DIR)
	rm -f $(TARGET_DIR)/$(exec)
