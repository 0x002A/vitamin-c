set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)                                                   
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)                                                   
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)                                                   
                                                                                                              
set(TARGET "vitc")                                                                                            

file(GLOB_RECURSE SOURCES RELATIVE "${CMAKE_SOURCE_DIR}/lib${TARGET}" "src/*.c" "src/*.h")
                                                                          
add_library(${TARGET}  STATIC  ${SOURCES})
target_include_directories(${TARGET} PUBLIC "include")
