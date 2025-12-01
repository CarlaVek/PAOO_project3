cmake_minimum_required(VERSION 3.0)

project(PAOO_proiect3)

include_directories(inc)
include(src/CMakeLists.txt)  

if(CMAKE_VERSION GREATER "3.1.2") 
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
else()
    if(CMAKE_COMPILER_IS_GNUCXX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
    endif()    
endif()       

set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/build")

add_executable(unsafe_writer src/unsafe_writer.cpp inc/Student.hpp)
add_executable(safe_writer src/safe_writer.cpp inc/Student.hpp)

set_target_properties(unsafe_writer PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set_target_properties(safe_writer PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})

