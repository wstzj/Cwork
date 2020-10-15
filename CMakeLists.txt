cmake_minimum_required(VERSION 3.16)
project(packag C)

set(CMAKE_C_STANDARD 11)

add_executable(packag main.c stackOfInt.h Contacts.h LinkList.h BinaryTree.h)