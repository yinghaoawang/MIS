GCC = g++
CFLAGS = -Wall -Werror -pedantic -g -std=c++11

all: program1 program2 program3

program1 : program1.cpp
	$(GCC) $(CFLAGS) program1.cpp -o program1

program2 : program2.cpp
	$(GCC) $(CFLAGS) program2.cpp -o program2

program3 : program3.cpp
	$(GCC) $(CFLAGS) program3.cpp -o program3 Heap.cpp

clean:
	rm -rf $(OBJ) program1 program2 program3
