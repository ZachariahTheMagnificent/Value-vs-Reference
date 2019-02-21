cmake_minimum_required(VERSION 3.11)
project(value-vs-reference VERSION 1.0.0 DESCRIPTION "Benchmarks on passing by value vs by reference" LANGUAGES CXX)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/value-vs-reference-app")
