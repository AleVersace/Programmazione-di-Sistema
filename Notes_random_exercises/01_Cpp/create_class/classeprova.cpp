//
// Created by Ale on 14/03/2021.
//

#include "classeprova.h"

/*
classeprova::classeprova() {
    cout << "Creazione Obj Classe prova (" << this << ")\n";
    dato1 = dato2 = 0;
}
*/

classeprova::classeprova(int d1, int d2) {
    cout << "Creazione Obj Classe prova da costruttore 2 (" << this << ")\n";
    dato1 = d1;
    dato2 = d2;
}

void classeprova::stampaDati() {
    cout << "indirizzo dati: " << &dato1 << "(" << dato1 << "), " << &dato2 << "(" << dato2 << ")\n";
}