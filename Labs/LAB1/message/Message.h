//
// Created by Ale on 28/03/2021.
//

#ifndef LAB1_MESSAGE_H
#define LAB1_MESSAGE_H

#include <iostream>
#include <string>

class Message {
    long _id;
    char *_data;
    int _size;

public:
    Message(int size=0, int id=-1);
    Message(Message& src);
    Message(Message&& that);
    Message& operator = (Message that);
    friend void swap(Message& a, Message& b);
    ~Message();

    int setId(int Id);
    int getSize() const;
    const char* getData() const;
    int getId() const;

};

#endif //LAB1_MESSAGE_H
