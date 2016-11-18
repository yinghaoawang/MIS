//
// Created by CIJhn on 11/15/2016.
//

#include "TCPConnection.h"

TCPConnection *TCPConnection::connet(TCPConnection::Address &address, int readBufferSize, int writeBufferSize) {
    char *add = (char *) calloc(address.host.length(), sizeof(char));
    memcpy(add, address.host.c_str(), address.host.length());
    TCPSocket *sock = new TCPSocket(add, address.port, readBufferSize, writeBufferSize);
    Address local(sock->getMyAddress(), address.port);
    TCPConnection *pt = new TCPConnection(sock, address, local);
    return pt;
}


TCPConnection::Address::Address(const string &host, int port) : host(host), port(port) {}

TCPConnection::~TCPConnection() {
    socket->shutDown();
    delete (socket);
}

TCPConnection::TCPConnection(TCPSocket *socket, const TCPConnection::Address &remoteAddress,
                       const TCPConnection::Address &localAddress) : socket(socket), remoteAddress(remoteAddress),
                                                                  localAddress(localAddress) {
}

int TCPConnection::write(ByteBuffer &buffer) {
    return socket->writeToSocket((const char *) buffer.data(), buffer.size());
}

int TCPConnection::read(ByteBuffer &buffer) {
    Byte *v = (Byte *) calloc(buffer.capacity(), sizeof(Byte));
    int size = socket->readFromSocket((char *) v, buffer.capacity());
    if (size != -1)
        buffer.writeBytes(v, size);
    return size;
}

const TCPConnection::Address &TCPConnection::getRemoteAddress() const {
    return remoteAddress;
}

const TCPConnection::Address &TCPConnection::getLocalAddress() const {
    return localAddress;

}

bool TCPConnection::isConnecting() {
    return !socket->isPeerDisconnected();
}

bool TCPConnection::isReadClosed() {
    return socket->isReadShutDown();
}

bool TCPConnection::isWriteClosed() {
    return socket->isWriteShutDown();
}

bool TCPConnection::isClosed() {
    return socket->isReadShutDown() && socket->isWriteShutDown();
}

void TCPConnection::closeRead() {
    socket->shutDownRead();
}

void TCPConnection::closeWrite() {
    socket->shutDownWrite();
}

void TCPConnection::close() {
    socket->shutDown();
}
