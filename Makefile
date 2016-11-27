CXX = g++
CXXFLAGS = -std=c++14 -Wfatal-errors -g
INC_DIR = include/
vpath = %.o bin/
vpath = %.cpp src/
vpath = %.h include/

SRC = $(shell find src/ -name '*.cpp')
OBJ = $(patsubst %.cpp, %.o, $(addprefix bin/, $(patsubst src/Parser/%, %, $(wildcard src/Parser/*.cpp))))

OBJ = $(addprefix bin/, $(notdir $(SRC:.cpp=.o)))
EXE = misvm

.PHONY: all wipe clean

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ -I$(INC_DIR)

bin/%.o: src/%.cpp
	@mkdir -p bin/
	$(CXX) $(CXXFLAGS) -c $< -I$(INC_DIR)
	@mv $(notdir $@) bin/

bin/%.o: src/Parser/%.cpp
	@mkdir -p bin/
	$(CXX) $(CXXFLAGS) -c $< -I$(INC_DIR)
	@mv $(notdir $@) bin/

bin/%.o: src/Operation/%.cpp
	@mkdir -p bin/
	$(CXX) $(CXXFLAGS) -c $< -I$(INC_DIR)
	@mv $(notdir $@) bin/

clean:
	@rm -r bin $(EXE)
