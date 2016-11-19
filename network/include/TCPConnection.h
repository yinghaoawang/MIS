//
// Created by CIJhn on 11/15/2016.
//

#ifndef MIS_SOCKET_NETWORK_H
#define MIS_SOCKET_NETWORK_H

#include "TCPSocket.h"
#include "ByteBuffer.h"

class TCPConnection {
protected:
    TCPSocket *socket;
    struct TCPConnection::Address remoteAddress;
    struct TCPConnection::Address localAddress;

    TCPConnection(TCPSocket *socket, const TCPConnection::Address &remoteAddress,
                  const TCPConnection::Address &localAddress);

public:
    friend class TCPServerChannel;

    virtual ~TCPConnection();

    struct Address {
        const std::string host;
        const int port;

        Address(const string &host, const int port);
    };

    /**
     * Open a new tcp connection with an address.
     * Return nullptr if this operation is failed.
     * @param address The address of the server.
     * @param readBufferSize The channel reading buffer size.
     * @param writeBufferSize The channel writing buffer size.
     * @return a new TCPChannel
     * */
    static TCPConnection *connet(Address &address, int readBufferSize = 65536, int writeBufferSize = 65536);

    virtual int write(ByteBuffer &buffer);

    virtual int read(ByteBuffer &buffer);

    virtual const Address &getRemoteAddress() const;

    virtual const Address &getLocalAddress() const;

    virtual bool isConnecting();

    virtual bool isReadClosed();

    virtual bool isWriteClosed();

    virtual bool isClosed();

    virtual void closeRead();

    virtual void closeWrite();

    virtual void close();

};

#endif //MIS_SOCKET_NETWORK_H
