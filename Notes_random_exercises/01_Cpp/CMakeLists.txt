cmake_minimum_required(VERSION 3.17)
project(01_Cpp)

set(CMAKE_CXX_STANDARD 20)
set(CREATE_CLASS_SRC create_class/main.cpp create_class/classeprova.cpp)
set(DYN_CLASS_SRC classeDynamic/main.cpp classeDynamic/dynamicMemClass.cpp)

#add_executable(01_Cpp main.cpp)

add_executable(dyClass ${DYN_CLASS_SRC})
add_executable(create_class ${CREATE_CLASS_SRC})