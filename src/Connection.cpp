#include "Connection.h"
#include "VM.h"
//Constructor: Call parent Thread Constructor
Connection::Connection(TCPSocket * p_tcpSocket): Thread()
{
  tcpSocket = p_tcpSocket; // Set the TCP socket
  next_connection = NULL; // Set the next pointer to NULL
}
// A modifier that sets the pointer of the next connection
void Connection::setNextConnection(Connection * connection){next_connection = connection;}
// A Selectot that returned a pointer to the next connection
Connection * Connection::getNextConnection (){return next_connection;}
// Destructor: delete the TCP socket if set
Connection::~Connection(){ if ( tcpSocket != NULL ) delete (tcpSocket); }
void * Connection::threadMainBody (void * arg) { // Main thread body for serving the connection
  int read_bytes;
  char buffer[65536]; // A buffer for holding the buffer
  memset (buffer,0,65536); // Initialize the buffer

  // Getting input mis file
  read_bytes = tcpSocket->readFromSocket(buffer,65536); // read from socket the buffer to be fetched
  if (read_bytes <= 0) { // If read unsuccessfully
    fprintf(stderr, "Error With File\n"); // Print an error message
    tcpSocket->shutDown(); // Shutdown the TCP Socket
  }

  /* Handle the input mis file, run the operations */
  VM vm;
  vm.ReadBuffer(buffer);
  vm.ExecuteOperations();
  std::cout << "Operations executed, writing to buffer" << std::endl;

  /* Get the output from the mis, send it to client */
  vm.ReadOutput(buffer);
  if (strlen(buffer) == 0) {
    tcpSocket->writeToSocket("", 1);
  } else {
    tcpSocket->writeToSocket(buffer, strlen(buffer));
  }

  /* Wait until client receives it, client will send something back letting us know */
  read_bytes = tcpSocket->readFromSocket(buffer, 1);
  if (read_bytes <= 0) {
    fprintf(stderr, "Request timed out or client closed connection\n");
    tcpSocket->shutDown(); // Shutdown the TCP Socket
  }

  /* Get the error from the mis, send it to client */
  vm.ReadError(buffer);
  tcpSocket->writeToSocket(buffer, strlen(buffer));
  std::cout << "Finished serving a client" << std::endl;

  return NULL;
}
