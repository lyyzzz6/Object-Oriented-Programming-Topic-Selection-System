cmake_minimum_required(VERSION 3.23)
project(C__classDesign)

set(CMAKE_CXX_STANDARD 17)

add_executable(C__classDesign main.cpp model/student.cpp include/student.h model/Teacher.cpp include/Teacher.h model/Topic.cpp include/Topic.h src/menu.cpp include/menu.h include/tlist.h include/listnode.h include/file.h)
