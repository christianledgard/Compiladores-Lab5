cmake_minimum_required(VERSION 3.19)
project(Lab5)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab5 main.cpp Grammar.h Element.h printUtils.h AnalizadorLexico/LexAnalyzer.h AnalizadorLexico/Lex.h)