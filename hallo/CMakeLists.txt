cmake_minimum_required(VERSION 3.24)
project(hallo)

set(CMAKE_CXX_STANDARD 17)

add_executable(hallo main.cpp dummy/ausgabe.h Schwein.h)
