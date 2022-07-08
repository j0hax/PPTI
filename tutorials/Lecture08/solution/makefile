#########################################
# Makefile
#########################################

CXX = g++

SANITIZE := -fsanitize=address \
	-fsanitize=undefined \
	-fsanitize=leak \
	-fsanitize=float-cast-overflow \
	-fno-omit-frame-pointer

CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic -g -O0 \
	-Winit-self -Wold-style-cast -Wcast-qual -Wundef \
	-Woverloaded-virtual \
	-Wconversion \
	-Wlogical-op \
	-Wzero-as-null-pointer-constant \
	$(SANITIZE)

LINK_FLAGS := $(SANITIZE)

EXEC	:= main
SRCS	:= $(wildcard *.cpp)
SRCS    := main.cpp
HDRS	:= $(wildcard *.h)
OBJS	:= $(patsubst %.cpp, obj/%.o, $(SRCS))
DEPS	:= $(patsubst %.o, %.d, $(OBJS))

# Default target
$(EXEC)	:

# Create all
all	: $(EXEC)

# Include existing dependancies
-include $(DEPS)

# Create dependancy files
.SUFFIXES += .d
obj/%.d: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MM -MT '$(patsubst %.cpp,obj/%.o,$<)' $< -MF $@

# Compilation
obj/%.o: %.cpp obj/%.d
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link  executable
$(EXEC)	: $(OBJS)
	$(CXX) $(OBJS) $(LINK_FLAGS) -o $@

# Clean up directory
clean	: 
	rm -f $(EXEC) 
	rm -f lib$(LIB_NAME).a
	rm -f lib/*.o
	rm -rf obj
	rm -rf doc


