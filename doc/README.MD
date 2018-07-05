# Post Mortem
## CMPS 109 Advanced Programming in C++
This was my class assignment where we were given more than 2 months, and required 2 partners. This class was much more difficult that usual as the teacher was new to teaching and the country. The normal Advanced C++ class would not fit so many topics into a class dedicated to a language (many C++ features, advanced OOP, sockets, multithreading).

## Contribution
I had 2 partners for a total of 3. The first partner dropped out shortly after the first phase. My second partner rarely communicated with me.

I wrote the entire first phase by myself. The teacher provided server, threading, and socket code for us, albeit very buggy. I had to debug and fix much of the code that the teacher provided. My partner and I did not communicate or attend class much, so our code was incompatible with each other. We ended up writing our own copies of the project.

## UML Design Docs
Team partners stopped responding to me since before phase 1 deadline, so UML diagram is
from scratch since I wrote phase 1 from scratch- there is no phase 2 diagram. I also think the phase 1 diagram that I did is incorrect.

## What I Learned
I learned solid principles of object oriented programming in C++. I used the abstract factory pattern in order to make my code modular. I learned how to poorly utilize sockets in order to have a network/client system.

## What I should do next time
Figure out a better method of communication. I can't stress how important it was to communicate. Rather than getting an A in the class, I received a C- because my team member said that he turned in the first phase. I should have been the one to submit hte assignment.

# FAQ 
## How to run Client/Server Multithreaded MIS
Client/server multithreaded sequential MIS works fine.
Run ./server_misvm
Run ./client_misvm 0.0.0.0 9999 FILENAME
Most phase 2 code from helper code and slides code (modified to fit needs, fixed a few bugs).

## Multithreading in the MIS Interpreter
Did not do programmatic constructs for multi-threading. Note that this is different than multithreading for the client/server.

## Long Makefile Compilation?
There are many files, it should take a little while.

## Long MIS Interpretation?
If it is taking a while to interpert, it is probably due to the fact that sleep is in the .mis file,
as the server will sleep when parsing and executing the code.

## How the Code Works
NOTE: this is all explained in the documentation (.cpp files)

The project was brokend own into 2 phases. The first phase involved creating the interpreter. The second phase involved hosting the interpreter on the server while having multiple clients send queries to the hosted interpreter.

### Phase 1:
The sequential MIS VM takes in an input. For each line, it will determine which operation that line is,
and fetch a parser using a parser factory to parse the line. The parser will then use an operation factory
to fetch the respective operation.
The operation that was returned by the parser will then be pushed to a cache (a storage class for variables,
labels, and most importantly, operations.
Variable creation and label creation are handled during the parsing phase, that is why each parser takes in
a cache pointer as an argument.
After there are no more lines left in the stream, the user will invoke VM's ExecuteOperations method. This will
retrieve the operations in the cache, and execute them each sequentially jumping back to previous (or future) operations when
executing jmp operations.
The results of the output are stored in a stringstream. Same goes with the errors.
The client retrieves the output and errors with ReadOutput and ReadError.
The client then writes them to a file.

### Phase 2:
The server creates a server socket that listens for a corresponding client. It then creates a connection
which extends a thread class. In short, each time a client connects to the server, a connection is made.
The connection reads from socket first getting the input file stream. The connection then creates a MIS VM,
and handles the input with the MIS VM.
The connection then writes the output of the MIS VM to the socket, and begins reading to wait for the client
to receive the file.
The client should receive the output file, where it writes to a file named mis.out. It then writes to the socket
letting the server know that it has received the output file "mis.out".
The server then receives it, and finishes off by writing the error file to the socket.
The client receives it and writes the content to the error file "mis.err".
All of this is happening in the thread, so there can be multiple clients sending files to server, and the server
will handle them concurrently.
