//
// Created by CIJhn on 11/17/2016.
//

#include <thread>
#include <future>
#include "AsyncSessionHandler.h"

void AsyncSessionHandler::handle(TCPConnection *session) {
    std::async([session]() {
        delegate->operator()(session);
    });
}

AsyncSessionHandler::AsyncSessionHandler(TCPServerChannel::SessionHandler *delegate) : delegate(delegate) {}
