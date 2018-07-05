# Machine Instructions Interpreter (MIS)
MIS is a virtual machine that interprets and executes a set of instructions. The keywords and other details about MIS are located [here](doc/DETAILS.MD).

## Server/Client network with multithreading
The MIS is hosted on a local server, and the multiple clients can send in ```.mis``` files to be interpreted. The MIS sends the output to the corresponding client once a task is completed.

## Picture Demo
Initialize server

![](https://i.imgur.com/0nCTBUX.png)

Send client request

![](https://i.imgur.com/npj53oZ.png)

Server finds connection, executes instructions

![](https://i.imgur.com/S9lnvfH.png)

Server finishes executions, returns output

![](https://i.imgur.com/BU3ZlOl.png)

Client receives output, and prints it

![](https://i.imgur.com/TrmYxKu.png)



## Installation
```mysql/mysql.h``` is required. Developer client of mysql will generally install this. For Ubuntu, the package ```mysqlclient``` and ```libmysqlclient-dev``` are required.

Run ```make``` to build the files.

## Usage
First a server must host the virtual machine, this is done by running

`./server_misvm`

Then have a client sends in the ```.mis``` file to be interpreted

`./client_misvm "0.0.0.0" 9999 test/0.mis`

The above code will send the ```.mis``` file to the server.

Multiple clients can send requests to the server at once.

Test files are included in the ```test``` folder

## Docs
Assignment and details on MIS [here](doc/DETAILS.MD)

Tiny FAQ and my thoughts on this project [here](doc/README.MD)

Diagrams/Mockups [here](doc/).