//
// Created by Ale on 28/03/2021.
//

#ifndef LAB1_MESSAGESTORE_H
#define LAB1_MESSAGESTORE_H


#include <optional>
#include <tuple>
#include "../message/Message.h"

class MessageStore {
    Message * _messages;
    int _dim;    // dimensione corrente array
    int _n;      // incremento memoria

public:
    MessageStore(int n);
    ~MessageStore();

    void add(Message &m);

    std::optional<Message> get(long id);

    bool remove(long id);

    std::tuple<int, int> stats();

    void compact();
};


#endif //LAB1_MESSAGESTORE_H
