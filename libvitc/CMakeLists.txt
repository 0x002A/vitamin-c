cmake_minimum_required(VERSION 3.12.0)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)                                                   
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)                                                   
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)                                           
                                                                                                              
set(TARGET "vitc")                                                                                            

file(GLOB_RECURSE SOURCES RELATIVE "${CMAKE_SOURCE_DIR}/lib${TARGET}" "src/*.c" "src/*.h")

add_library(${TARGET}  STATIC  ${SOURCES})
target_include_directories(${TARGET} PUBLIC "include/${TARGET}")

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif() 

PROJECT("${TARGET}_test" CXX)

file(GLOB_RECURSE TEST_SOURCES RELATIVE "${CMAKE_SOURCE_DIR}/lib${TARGET}" "tests/*.cpp" "tests/*.h")
                                                                
add_executable("${TARGET}_test" ${TEST_SOURCES})
add_test(NAME "${TARGET}_test" COMMAND "${TARGET}_test")          

target_include_directories("${TARGET}_test" PUBLIC "include/${TARGET}")
target_link_libraries("${TARGET}_test" ${TARGET} gtest)
