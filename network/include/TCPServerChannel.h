//
// Created by CIJhn on 11/17/2016.
//

#ifndef MISVM_TCPSERVERCHANNEL_H
#define MISVM_TCPSERVERCHANNEL_H

#include "TCPConnection.h"
#include "TCPServerSocket.h"
#include <functional>

class TCPServerChannel {
private:
    TCPServerSocket *socket;
    bool term;
    int queueSize, t_sec, t_mil, rsize, wsize;
    TCPConnection::Address address;
    SessionHandler handler;

    TCPServerChannel(TCPServerSocket *socket, int queueSize, const TCPConnection::Address &address,
                     const SessionHandler &handler);

public:
    using SessionHandler =  std::function<void(TCPConnection *)>;

    static TCPServerChannel *createServer(TCPConnection::Address &address, SessionHandler handler, int queueSize);

    TCPServerChannel &setTimeout(int second, int mill);

    TCPServerChannel &setReadBufferSize(int size);

    TCPServerChannel &setWriteBufferSize(int size);

    int getTimoutSecond() const;

    int getTimeoutMillSecond() const;

    int getReadBufferSize() const;

    int getWriteBufferSize() const;

    bool start();

    bool isTerminated();

    void terminate();
};


#endif //MISVM_TCPSERVERCHANNEL_H
