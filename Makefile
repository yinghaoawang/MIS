CXX = g++
CXXFLAGS = -std=c++14 -Wfatal-errors -g -pthread
INC_DIR = include/
vpath = %.o bin/
vpath = %.cpp src/
vpath = %.h include/

SRC = $(shell find src/ -name '*.cpp')
OBJ = $(addprefix bin/, $(notdir $(SRC:.cpp=.o)))

SERVER_OBJ = $(filter-out bin/client.o, $(filter-out bin/main.o, $(OBJ)))
CLIENT_OBJ = bin/client.o bin/TCPSocket.o bin/Util.o

.PHONY: all wipe clean

all: client_misvm server_misvm

client_misvm: $(CLIENT_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ -I$(INC_DIR)

server_misvm: $(SERVER_OBJ)
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

bin/%.o: src/Network/%.cpp
	@mkdir -p bin/
	$(CXX) $(CXXFLAGS) -c $< -I$(INC_DIR)Network
	@mv $(notdir $@) bin/

clean:
	@rm -r bin client_misvm server_misvm mis.err mis.out
