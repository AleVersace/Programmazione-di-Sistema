//
// Created by Ale on 14/03/2021.
//

#ifndef INC_01_CPP_CLASSEPROVA_H
#define INC_01_CPP_CLASSEPROVA_H

#include <iostream>

using namespace std;    // La definizione di un namespace permette di usare le sue funzioni senza specificarlo prima di esse (std::cout)

class classeprova {
public:
    // classeprova(); Problematico perchè a questo punto ho due candidati a costruttore di default. Questo e quelli di default settati nel costruttore sotto!
    classeprova(int d1 = 0, int d2 = 0);

    void stampaDati();
private:
    int dato1, dato2;
};

#endif //INC_01_CPP_CLASSEPROVA_H
