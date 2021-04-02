//
// Created by Ale on 28/03/2021.
//

#include "Message.h"

char* mkMessage(int n) {
    std::string  vowels = "aeiou";
    std::string  consonants = "bcdfghlmnpqrstvz";
    char* m = new (std:: nothrow) char[n+1];
    if (m !=  nullptr) {
        for (int i = 0; i < n; i++) {
            m[i] = i%2 ? vowels[rand ()% vowels.size ()] :consonants[rand ()% consonants.size ()];
        }
    }
    return m;
}

// Constructor
Message::Message(int size, int id): _size(size), _id(id) {
    if(_size > 0) {
        _data = new (std::nothrow) char[_size];
        memcpy(_data, mkMessage(_size), _size * sizeof(char));
    }
    else
        _data = nullptr;
}

// Copy Constructor
Message::Message(Message& src): _size(src._size) {
    if(_size > 0) {
        std::cout << "Copy activated\n";
        _data = new (std::nothrow) char[_size];
        if(_data != nullptr)
            memcpy(_data, src._data, _size * sizeof(char));
        else
            std::cerr << "Error while creating the dynamic mem in Message\n";
    } else
        _data = nullptr;
    _id = src._id;
}

/*
// Move Constructor
Message::Message(Message&& src) {
    _size = src._size;
    _data = src._data;
    _id = src._id;
    src._size = 0;
    src._data = nullptr;
    src._id = -1;
}
 */

void swap(Message& a, Message& b) {
    std::swap(a._size, b._size);
    std::swap(a._data, b._data);
    std::swap(a._id, b._id);
}

/* = Operator with copy and swap mechanism */
Message& Message::operator=(Message that) {
    swap(*this, that);
    return *this;
}

// Move Constructor with copy and swap
Message::Message(Message&& that): _id(-1), _size(0), _data(nullptr){
    swap(*this, that);
}

// Destructor
Message::~Message() {
    if(_data != nullptr) {
        std::cout << "Deleting Memory " << " (" << &_data << ")\n";
        delete[] _data;
        _data = nullptr;
    }
}

int Message::getSize() const {
    return _size;
}

const char* Message::getData() const{
    return _data;
}

int Message::getId() const {
    return _id;
}


