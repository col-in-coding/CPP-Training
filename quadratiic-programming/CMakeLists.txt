cmake_minimum_required(VERSION 3.10)

project(Test)

LINK_DIRECTORIES(/usr/local/lib)

add_executable(mytest test.cc)
TARGET_LINK_LIBRARIES(mytest osqp)