cmake_minimum_required(VERSION 3.17)
project(LAB1)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB1 main.cpp message/Message.cpp durationLogger/DurationLogger.cpp messageStore/MessageStore.cpp)