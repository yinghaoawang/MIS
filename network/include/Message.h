//
// Created by CIJhn on 11/17/2016.
//

#ifndef MISVM_MESSAGE_H
#define MISVM_MESSAGE_H

#include <functional>
#include "ByteBuffer.h"
#include "TCPConnection.h"

//class Message {
//    virtual void writeTo(ByteBuffer &buffer)=0;
//
//    virtual void readFrom(ByteBuffer &buffer)=0;
//};

//These are totatlly not finish
enum class Side {
    CLIENT, SERVER
};

template<typename T>
class MessageHandler {
    virtual void handle(T *msg, Side side)=0;
};

class MessageDispatcher {
private:
    std::map<std::string, MessageHandler<void>> map;
    std::map<std::string, std::function<ByteBuffer *(void *)>> serialMap;
public:
    template<typename T>
    void send(T *message) {
        const char *name = typeid(T).name();
        std::function<ByteBuffer *(void *)> func = serialMap[name];
        func(message);
    }

    void recived(ByteBuffer &buffer);

    template<typename T>
    void registerPacket(unsigned char id, std::function<T(ByteBuffer &)> serial,
                        std::function<ByteBuffer *(T)> deserial, MessageHandler<T> handler) {
        serialMap[typeid(T).name()] = deserial;
    }

protected:
    void dispatch(ByteBuffer &buffer);


};

#endif //MISVM_MESSAGE_H
