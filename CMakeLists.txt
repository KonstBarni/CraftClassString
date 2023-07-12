cmake_minimum_required(VERSION 3.16)

project(ClassString)

file(GLOB CPPS main.cpp ClassString.cpp Stack.cpp Functions.cpp)

add_executable(${PROJECT_NAME} ${CPPS})
