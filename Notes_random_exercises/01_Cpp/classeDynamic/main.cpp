//
// Created by Ale on 18/03/2021.
//

#include <iostream>
#include "dynamicMemClass.h"

int main() {
    dynamicMemClass obj(10);
    dynamicMemClass obj2 {obj};
    dynamicMemClass obj3 { std::move(obj)};


    /*
    int * ptrInt = new (std::nothrow) int[10];
    if (ptrInt == nullptr) {
        std::cerr << "Error in mem allocation\n";
        return -1;
    }

    for (int i = 0; i < 10; i++)
        std::cout << ptrInt[i] << " ";
    std::cout << "\n";

    if (ptrInt != nullptr) {
        delete[] ptrInt;
        ptrInt = nullptr;       // Facendo così ho già ptrInt == nullptr quindi se rieseguo l'if non entrerà più.
    } */



    return 0;
}

