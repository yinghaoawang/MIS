//
// Created by CIJhn on 11/17/2016.
//

#ifndef MISVM_ASYNCSESSIONHANDLER_H
#define MISVM_ASYNCSESSIONHANDLER_H

#include "TCPConnection.h"
#include "TCPServerChannel.h"

class AsyncSessionHandler {
    TCPServerChannel::SessionHandler *delegate;
public:
    AsyncSessionHandler(TCPServerChannel::SessionHandler *delegate);

    void handle(TCPConnection *session);
};


#endif //MISVM_ASYNCSESSIONHANDLER_H
