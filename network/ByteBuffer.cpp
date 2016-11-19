//
// Created by CIJhn on 11/15/2016.
//

#include <cstring>
#include "ByteBuffer.h"

static const size_t int_size(sizeof(int)), float_size(sizeof(float)), double_size(sizeof(double))
, long_size(sizeof(long)), char_size(sizeof(char)), short_size(sizeof(short)), byte_size(sizeof(unsigned char));

template<size_t size>
void ByteBuffer::ensure_capacity(int sz) {
    size_t dff = byte_size / size;
    if (this->cap <= (sz * dff)) {
        Byte *nArr = (Byte *) calloc(this->cap * 2, byte_size);
        memcpy(nArr, this->payload, this->cap);
        payload = nArr;
        cap = sz * dff;
    }
}


ByteBuffer &ByteBuffer::writeBytes(const Byte *v, int size) {
    ensure_capacity<char_size>(pt + size);
    Byte *start = payload + pt;
    memcpy(start, v, size);
    pt += size;
    if (pt > _size)
        _size = pt;
    return *this;
}

ByteBuffer &ByteBuffer::writeByte(Byte v) {
    ensure_capacity<char_size>(pt + 1);
    payload[pt++] = v;
    if (pt > _size)
        _size = pt;
    return *this;
}

void ByteBuffer::flip() {
    pt = 0;
}

size_t ByteBuffer::capacity() {
    return cap;
}

int ByteBuffer::size() {
    return _size;
}

ByteBuffer::ByteBuffer(int sz) : cap((size_t) sz), pt(0), _size(0) {
    payload = (Byte *) calloc(cap, char_size);
}

ByteBuffer &ByteBuffer::writeInt(int v) {
    payload[pt + 3] = (Byte) ((v >> 24) & 0xff);
    payload[pt + 2] = (Byte) ((v >> 16) & 0xff);
    payload[pt + 1] = (Byte) ((v >> 8) & 0xff);
    payload[pt] = (Byte) (v & 0xff);
    pt += 3;
    if (pt > _size)
        _size = pt;
    return *this;
}

ByteBuffer &ByteBuffer::readInt(int *i) {
    (*i) = payload[pt + 3] << 24 | payload[pt + 2] << 16 | payload[pt + 1] << 8 | payload[pt];
    pt += 3;
    return *this;
}

ByteBuffer &ByteBuffer::readByte(Byte *byte) {
    *byte = payload[pt++];
    return *this;
}

template<int sz>
ByteBuffer &ByteBuffer::readBytes(Byte *bytes[sz]) {
    Byte *container = (*bytes);
    memcpy(bytes, payload + pt, sz);
    pt += sz;
    return *this;
}

const Byte *ByteBuffer::data() {
    Byte *bytes = (Byte *) calloc(_size, byte_size);
    memcpy(bytes, payload, _size);
    return bytes;
}

int ByteBuffer::remain() {
    return _size - pt;
}

ByteBuffer::~ByteBuffer() {
    free(payload);
}


