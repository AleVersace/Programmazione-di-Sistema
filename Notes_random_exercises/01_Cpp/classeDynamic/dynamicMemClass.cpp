//
// Created by Ale on 18/03/2021.
//

#include "dynamicMemClass.h"

dynamicMemClass::dynamicMemClass(std::size_t size) : _size(size) {
    if (_size != 0) {
        std::cout << "Generating Memory\n";
        _ptr = new(std::nothrow) int[size];
        if (_ptr == nullptr) {
            std::cerr << "Error while creating the dynamic mem in dynamicMemClass\n";
        }
    }
    else _ptr = nullptr;
}

// Copy constructor
dynamicMemClass::dynamicMemClass(const dynamicMemClass& src): _size(src._size) {
    if (_size > 0) {
        std::cout << "Copy activated\n";
        _ptr = new (std::nothrow) int [_size];
        if (_ptr == nullptr) {
            std::cerr << "Error while creating the dynamic mem in dynamicMemCalss\n";
        } else {
            memcpy(_ptr, src._ptr, _size * sizeof (int));
        }
    }
    else _ptr = nullptr;
}

// Move constructor
dynamicMemClass::dynamicMemClass(dynamicMemClass&& src) {
    _size = src._size;
    _ptr = src._ptr;
    src._size = 0;
    src._ptr = nullptr;
}

// Il const verifica che internamente nulla sia modificato!
std::size_t dynamicMemClass::getActualSize() const {
    return _size;
}

dynamicMemClass::~dynamicMemClass() {
    if (_ptr != nullptr) {
        delete[] _ptr;
        std::cout << "Deleting Memory " << _ptr << " (" << *_ptr << ")\n";
        _ptr = nullptr;
    }
}