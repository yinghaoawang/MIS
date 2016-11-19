//
// Created by CIJhn on 11/15/2016.
//

#ifndef MIS_SOCKET_BYTEBUFFER_H
#define MIS_SOCKET_BYTEBUFFER_H

#include <cstdlib>
#include <string>

typedef unsigned char Byte;

class ByteBuffer {
    Byte *payload;
    size_t cap;
    int pt, _size;

    template<size_t>
    void ensure_capacity(int size);

public:
    ByteBuffer(int initSize);

    virtual ~ByteBuffer();

    ByteBuffer &writeBytes(const Byte *v, int size);

    ByteBuffer &writeByte(Byte v);

    ByteBuffer &writeInt(int v);

    void flip();

    size_t capacity();

    int size();

    int remain();

    ByteBuffer &readInt(int *i);

    ByteBuffer &readByte(Byte *byte);

    template<int sz>
    ByteBuffer &readBytes(Byte *bytes[sz]);

    const Byte *data();
};


#endif //MIS_SOCKET_BYTEBUFFER_H
