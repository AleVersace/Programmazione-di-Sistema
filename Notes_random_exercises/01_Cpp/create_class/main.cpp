//
// Created by Ale on 14/03/2021.
//

#include <iostream>
#include "classeprova.h"

int main() {
    classeprova obj1, obj2(5, 4);     // Prima il primo costruttore, poi il secondo (se definiti entrambi), altrimenti usa sempre il secondo con i valori di default nel primo caso.
    obj1.stampaDati();
    obj2.stampaDati();
    // std::cout << "Hello, World! " << '\n';  // std::endl; '\n' + flush(); Se cerco il massimo delle prestazioni uso solo '\n'
    return 0;
}

