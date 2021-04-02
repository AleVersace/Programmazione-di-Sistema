//
// Created by Ale on 28/03/2021.
//

#ifndef LAB1_DURATIONLOGGER_H
#define LAB1_DURATIONLOGGER_H

#include <iostream>
#include <string>
#include <ctime>

class DurationLogger {
    char * _name;
    long _size;
    clock_t _time;
    clock_t _duration;
public:
    DurationLogger(const std::string& name) {
        std::cout << ">>>>>>>>>>>>>> starting [ " + name + " ]\n";
        _size = name.length();
        _name = new (std::nothrow) char[_size];
        _time = clock();
        _duration = 0;
        if(_name != nullptr)
            memcpy(_name, name.c_str(), _size * sizeof(char));
        else
            std::cerr << "Error while creating the dynamic mem in DurationLogger\n";
    };

    ~DurationLogger() {
        _duration = clock() - _time;
        std::cout << "<<<<<<<<<<<<<< ending [ " << _name << " ]: [ " << _duration << " ] sec\n";
        delete[] _name;
        _name = nullptr;
        _time = 0;
        _duration = 0;
    };

};


#endif //LAB1_DURATIONLOGGER_H
