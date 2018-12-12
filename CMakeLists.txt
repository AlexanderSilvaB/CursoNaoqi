cmake_minimum_required(VERSION 2.8)
project(CursoNaoqi)

find_package(qibuild)

include_directories(".")

qi_create_bin(say say.cpp)
qi_use_lib(say ALCOMMON ALPROXIES )

qi_create_bin(head head.cpp)
qi_use_lib(head ALCOMMON ALPROXIES )

qi_create_bin(move move.cpp)
qi_use_lib(move ALCOMMON ALPROXIES )