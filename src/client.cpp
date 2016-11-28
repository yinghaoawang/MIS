#include <iostream>
#include "Network/TCPSocket.h"
#include "Util.h"
using namespace std;

/* >>>>>IMPORTANT<<<<<
 * Running the server and interrupting it causes
 * the server to sometimes throws "ERROR on accept: invalid argument",
 * just keep running the server and client and it will eventually work again
 */

int main(int argc, char** argv) {
  /* Arg checking */
  if (argc != 4) {
    cout << "USAGE: ./client_misvm ip_address port_number filename" << endl;
    // Hint: server is probably 0.0.0.0, port 9999, check server.cpp
    exit(1);
  }

  /* Opening file and assigning contents, prepping to send */
  ifstream ifs;
  string content; // Using string due to its simple implementation of file reading
  try {
    ifs.open(argv[3]);
    if (!ifs.is_open()) {
      cerr << "Unable to open file \'" << argv[3] << "\'" << endl;
      exit(1);
    }
    content.assign(istreambuf_iterator<char>(ifs), istreambuf_iterator<char>()); // Copy entire file contents to string
  } catch (exception &e) {
    perror("Error with file");
    exit(1);
  }

  /* No error checking for ip address argument */
  char* ip_address = argv[1];

  /* Parsing port number */
  int port_number;
  if (!str_is_real(std::string(argv[2]))) {
    cerr << "Port number not a number" << endl;
    exit(1);
  }
  port_number = std::stoi(std::string(argv[2])); // String to integer

  // Creates TCP socket with the ip address at the port number
  TCPSocket *tcpSocket = new TCPSocket(ip_address,port_number,65536);

  // Send the file contents to the socket
  tcpSocket->writeToSocket(content.c_str(), content.size() * sizeof(char));

  // Prepares a buffer to read future reads from socket
  char buffer[65536];
  memset(buffer, 0, 65536);

  // Gets first write from socket (which is the output contents)
  int read_bytes = tcpSocket->readFromSocket(buffer, 65536);
  if (read_bytes < 0) // Catch errors if read failed
  {
    std::cerr << "Error with server\n";
    exit(1);
  }
  std::cout << buffer << std::endl;
  print_out(buffer, "mis.out"); // Output contents to "mis.out"

  // Send a message to the socket that the previous write has been received
  tcpSocket->writeToSocket("1", 1);

  // Receive second and last write from socket (error contents)
  read_bytes = tcpSocket->readFromSocket(buffer, 65536);
  if (read_bytes < 0) // Catch errors if read failed
  {
    std::cerr << "Error with server";
    exit(1);
  }
  std::cout << buffer << std::endl;
  print_out(buffer, "mis.err"); // Error contents to "mis.err"

  cout << "Success" << endl;
  return 0;
}
