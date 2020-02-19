cmake_minimum_required(VERSION 3.12.0)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(TARGET "vitamin-c")
set(LIBNAME "vitc")

project(${TARGET} C)

enable_testing()

add_subdirectory("lib${LIBNAME}")

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.c" "src/*.h")

add_executable(${TARGET} ${SOURCES})
target_include_directories(${TARGET} PUBLIC "lib${LIBNAME}/include")
target_link_libraries(${TARGET} ${LIBNAME})

