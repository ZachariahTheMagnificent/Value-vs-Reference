cmake_minimum_required(VERSION 3.11)
project(value-vs-reference-app VERSION 1.0.0 DESCRIPTION "The application to benchmark value-vs-reference" LANGUAGES CXX)

add_executable(value-vs-reference-app)
target_compile_features(value-vs-reference-app PRIVATE cxx_std_17)
target_include_directories(value-vs-reference-app PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_sources(value-vs-reference-app
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/value-vs-reference/profiler.hpp"
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp")
