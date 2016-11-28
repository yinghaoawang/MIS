#include <iostream>
#include "Network/TCPSocket.h"
#include "Util.h"
using namespace std;
int main(int argc, char** argv) {
  if (argc != 2) {
    cout << "USAGE: ./client filename" << endl;
    exit(1);
  }

  ifstream ifs;
  string content;
  try {
    ifs.open(argv[1]);
    if (!ifs.is_open()) {
      cerr << "Unable to open file \'" << argv[1] << "\'" << endl;
      exit(1);
    }
    content.assign(istreambuf_iterator<char>(ifs), istreambuf_iterator<char>());
  } catch (exception &e) {
    perror("Error with file");
    exit(1);
  }


  TCPSocket *tcpSocket = new TCPSocket("0.0.0.0",9999,65536);

  // output from mis
  tcpSocket->writeToSocket(content.c_str(), content.size() * sizeof(char));

  char buffer[65536];
  memset(buffer, 0, 65536);
  int read_bytes = tcpSocket->readFromSocket(buffer, 65536);

  if (read_bytes < 0) {
    std::cerr << "Error with server\n";
    exit(1);
  }
  print_out(buffer, "mis.out");
  cout << "Output mis.out generated" << endl;

  tcpSocket->writeToSocket("1", 1);

  // error from mis
  read_bytes = tcpSocket->readFromSocket(buffer, 65536);
  if (read_bytes < 0) {
    std::cerr << "Error with server";
    exit(1);
  }
  print_out(buffer, "mis.err");
  cout << "Error mis.err generated" << endl;

  return 0;
}
