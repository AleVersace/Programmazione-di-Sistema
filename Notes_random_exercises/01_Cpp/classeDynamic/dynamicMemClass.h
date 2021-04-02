//
// Created by Ale on 18/03/2021.
//

#ifndef INC_01_CPP_DYNAMICMEMCLASS_H
#define INC_01_CPP_DYNAMICMEMCLASS_H

#include <cstddef>
#include <memory>
#include <iostream>

class dynamicMemClass {
public:
    dynamicMemClass(std::size_t size = 0);
    dynamicMemClass(const dynamicMemClass& src);
    dynamicMemClass(dynamicMemClass&& src);
    ~dynamicMemClass();

    // Il const verifica che internamente nulla sia modificato!
    std::size_t getActualSize() const;

    // Non bellissimo, ma con const accettabile
    /*
    const int * getPtr() {
        return _ptr;
    }*/
    // In realtà di questi metodi non ne ho bisogno, non voglio far uscire gli elementi dell'oggetto dall'oggetto stesso
    // Usiamo degli operatori

private:
    int * _ptr;
    std::size_t _size;
};


#endif //INC_01_CPP_DYNAMICMEMCLASS_H
