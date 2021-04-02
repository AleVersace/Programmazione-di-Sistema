//
// Created by Ale on 28/03/2021.
//

#include "MessageStore.h"

MessageStore::MessageStore(int n): _dim(n) {
    _messages = new (std::nothrow) Message[_dim];
    if(_messages == nullptr)
        std::cout << "Error allocating dynamically MessageStore\n";
    _n = 2;
}

MessageStore::~MessageStore() {
    if(_messages != nullptr) {
        delete[] _messages;
        _messages = nullptr;
    }
    _n = 0;
    _dim = 0;
}


// Inserisce un nuovo messaggio o sovrascrive se ha stesso id
void MessageStore::add(Message &m) {
    int i;
    for (i = 0; i < _dim; ++i) {
        if(_messages[i].getId() == -1) {
            _messages[i] = m;
            return;
        }
    }

    // Se non abbastanza grande riallocazione vettore _messages
    Message *mes = new (std::nothrow) Message[_dim*_n];
    if(mes != nullptr) {
        for (i = 0; i < _dim; ++i) {
            mes[i] = std::move(_messages[i]);
        }
    }

    delete[] _messages;
    _messages = nullptr;
    _messages = new (std::nothrow) Message[_dim*_n];
    int old_dim = _dim;
    _dim = _dim * _n;
    if(_messages != nullptr && mes != nullptr) {
        for (i = 0; i < old_dim; ++i) {
            _messages[i] = std::move(mes[i]);
        }
        _messages[i] = m;
    }
}


// Restituisce il messaggio con l'id dato se presente
std::optional<Message> MessageStore::get(long id) {
    for (int i = 0; i < _dim; ++i) {
        if(_messages[i].getId() == id)
            return _messages[i];
    }
    return std::nullopt;
}

// Rimuove il messaggio dato il suo id, se esiste
bool MessageStore::remove(long id) {
    for (int i = 0; i < _dim; ++i) {
        if(_messages[i].getId() == id) {
            _messages[i] = Message();
            return true;
        }
    }
    std::cout << "No message equal to the one you want to remove." << std::endl;
    return false;
}


// Ritorna tupla (Numero messaggi validi, Numero di elementi vuoti disponibili)
std::tuple<int, int> MessageStore::stats() {
    auto t = std::make_tuple(0, 0);
    for (int i = 0; i < _dim; ++i) {
        if(_messages[i].getId() != -1)
            std::get<0>(t)++;
    }
    std::get<1>(t) = _dim - std::get<0>(t);
    return t;
}

// Compatta l'array eliminando celle vuote e riportandolo alla dimensione multiplo di n minima in grado di contenere tutti i messaggi validi
void MessageStore::compact() {
    int real_n = 0, n_multiple;
    for (int i = 0; i < _dim; ++i) {
        if(_messages[i].getId() != -1)
            real_n++;
    }
    n_multiple = (real_n + 1) / _n;

    Message *temp = new (std::nothrow) Message[n_multiple * _n];
    for (int i = 0, j = 0; i < _dim; ++i) {
        if(_messages[i].getId() != -1)
            temp[j++] = std::move(_messages[i]);
    }


    _dim = n_multiple * _n;
    delete[] _messages;
    _messages = nullptr;
    _messages = new (std::nothrow) Message[_dim];

    if(_messages != nullptr) {
        for (int i = 0; i < _dim; ++i) {
            _messages[i] = std::move(temp[i]);
        }
    }

    delete[] temp;
}