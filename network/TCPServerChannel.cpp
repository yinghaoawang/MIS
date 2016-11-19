//
// Created by CIJhn on 11/17/2016.
//

#include "TCPServerChannel.h"


TCPServerChannel *
TCPServerChannel::createServer(TCPConnection::Address &address, SessionHandler handler, int queueSize) {
    TCPServerSocket *sock = new TCPServerSocket(address.host.c_str(), address.port, queueSize);
    TCPServerChannel *channel = nullptr;
    channel = new TCPServerChannel(sock, queueSize, address, handler);
    return channel;
}

bool TCPServerChannel::start() {
    if (!socket->initializeSocket()) {
        return false;
    }
    while (!term) {
        TCPSocket *sock = socket->getConnection(t_sec, t_mil, rsize, wsize);
        TCPConnection *connection = new TCPConnection(sock,
                                                      TCPConnection::Address(sock->getRemoteAddress(), address.port),
                                                      address);
        handler(connection);
    }
    return true;
}

bool TCPServerChannel::isTerminated() {
    return term;
}

void TCPServerChannel::terminate() {
    //add lock
    term = true;
}

TCPServerChannel &TCPServerChannel::setTimeout(int second, int mill) {
    t_sec = second;
    t_mil = mill;
    return *this;
}

TCPServerChannel &TCPServerChannel::setReadBufferSize(int size) {
    rsize = size;
    return *this;
}

TCPServerChannel &TCPServerChannel::setWriteBufferSize(int size) {
    wsize = size;
    return *this;
}

TCPServerChannel::TCPServerChannel(TCPServerSocket *socket, int queueSize,
                                   const TCPConnection::Address &address,
                                   const SessionHandler &handler) : socket(socket), term(false),
                                                                   queueSize(queueSize),
                                                                   address(address),
                                                                   handler(handler),
                                                                   rsize(10 * 1024 * 1024),
                                                                   wsize(10 * 1024 * 1024) {}

int TCPServerChannel::getTimoutSecond() const {
    return t_sec;
}

int TCPServerChannel::getTimeoutMillSecond() const {
    return t_mil;
}

int TCPServerChannel::getReadBufferSize() const {
    return rsize;
}

int TCPServerChannel::getWriteBufferSize() const {
    return wsize;
}
