CC = g++
INC_PATH = include/
CFLAGS = -std=c++14 -Wfatal-errors -g
SRC_PATH = src/
SRC = $(shell find $(SRC_PATH) -type f -name '*.cpp')
SRC_BASENAME = $(shell find -type f -name '*.cpp' -printf '%f\n')
OBJ_PATH = bin/
OBJ = $(patsubst %.cpp, %.o, $(SRC_BASENAME))
EXEC_PATH = bin/
EXEC = misvm

.PHONY: all wipe clean

all:
	${MAKE} $(EXEC) || ${MAKE} wipe

$(EXEC): $(OBJ)
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(EXEC_PATH)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -I $(INC_PATH)
	@mv $(OBJ) $(OBJ_PATH)
	@cp $(EXEC) $(EXEC_PATH)

$(OBJ):
	$(CC) $(CFLAGS) -c $(addprefix $(SRC_PATH), $(patsubst %.o, %.cpp, $@)) -I $(INC_PATH)

wipe:
	rm -f $(OBJ) $(EXEC) $(EXEC_PATH)*

clean:
	rm -f $(OBJ) $(EXEC)
