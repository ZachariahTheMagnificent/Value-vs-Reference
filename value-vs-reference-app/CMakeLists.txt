cmake_minimum_required(VERSION 3.11)
project(value-vs-reference-app VERSION 1.0.0 DESCRIPTION "The application to benchmark value-vs-reference" LANGUAGES CXX)

add_executable(value-vs-reference)
target_compile_features(value-vs-reference PRIVATE cxx_std_17)
target_include_directories(value-vs-reference PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_sources(value-vs-reference
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/value-vs-reference/profiler.hpp"
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp"
)

add_executable(value-vs-reference-use-doubles)
target_compile_features(value-vs-reference-use-doubles PRIVATE cxx_std_17)
target_include_directories(value-vs-reference-use-doubles PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_compile_definitions (value-vs-reference-use-doubles PRIVATE USE_DOUBLES)
target_sources(value-vs-reference-use-doubles
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/value-vs-reference/profiler.hpp"
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp"
)

add_executable(value-vs-reference-reference-basic)
target_compile_features(value-vs-reference-reference-basic PRIVATE cxx_std_17)
target_include_directories(value-vs-reference-reference-basic PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_compile_definitions (value-vs-reference-reference-basic PRIVATE REFERENCE_SEMANTICS_FOR_BASIC_TYPES)
target_sources(value-vs-reference-reference-basic
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/value-vs-reference/profiler.hpp"
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp"
)

add_executable(value-vs-reference-value-struct)
target_compile_features(value-vs-reference-value-struct PRIVATE cxx_std_17)
target_include_directories(value-vs-reference-value-struct PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_compile_definitions (value-vs-reference-value-struct PRIVATE VALUE_SEMANTICS_FOR_STRUCTS)
target_sources(value-vs-reference-value-struct
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/value-vs-reference/profiler.hpp"
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp"
)

add_executable(value-vs-reference-use-doubles-reference-basic)
target_compile_features(value-vs-reference-use-doubles-reference-basic PRIVATE cxx_std_17)
target_include_directories(value-vs-reference-use-doubles-reference-basic PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_compile_definitions (value-vs-reference-use-doubles-reference-basic PRIVATE USE_DOUBLES)
target_compile_definitions (value-vs-reference-use-doubles-reference-basic PRIVATE REFERENCE_SEMANTICS_FOR_BASIC_TYPES)
target_sources(value-vs-reference-use-doubles-reference-basic
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/value-vs-reference/profiler.hpp"
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp"
)

add_executable(value-vs-reference-use-doubles-value-struct)
target_compile_features(value-vs-reference-use-doubles-value-struct PRIVATE cxx_std_17)
target_include_directories(value-vs-reference-use-doubles-value-struct PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_compile_definitions (value-vs-reference-use-doubles-value-struct PRIVATE USE_DOUBLES)
target_compile_definitions (value-vs-reference-use-doubles-value-struct PRIVATE VALUE_SEMANTICS_FOR_STRUCTS)
target_sources(value-vs-reference-use-doubles-value-struct
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/value-vs-reference/profiler.hpp"
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp"
)

add_executable(value-vs-reference-reference-basic-value-struct)
target_compile_features(value-vs-reference-reference-basic-value-struct PRIVATE cxx_std_17)
target_include_directories(value-vs-reference-reference-basic-value-struct PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_compile_definitions (value-vs-reference-reference-basic-value-struct PRIVATE REFERENCE_SEMANTICS_FOR_BASIC_TYPES)
target_compile_definitions (value-vs-reference-reference-basic-value-struct PRIVATE VALUE_SEMANTICS_FOR_STRUCTS)
target_sources(value-vs-reference-reference-basic-value-struct
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/value-vs-reference/profiler.hpp"
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp"
)

add_executable(value-vs-reference-all)
target_compile_features(value-vs-reference-all PRIVATE cxx_std_17)
target_include_directories(value-vs-reference-all PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_compile_definitions (value-vs-reference-all PRIVATE USE_DOUBLES)
target_compile_definitions (value-vs-reference-all PRIVATE REFERENCE_SEMANTICS_FOR_BASIC_TYPES)
target_compile_definitions (value-vs-reference-all PRIVATE VALUE_SEMANTICS_FOR_STRUCTS)
target_sources(value-vs-reference-all
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/value-vs-reference/profiler.hpp"
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp"
)
