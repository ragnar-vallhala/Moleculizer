cmake_minimum_required(VERSION 3.10)

set(project Moleculizer)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(${project})

add_subdirectory(${CMAKE_SOURCE_DIR}/glfw)
add_subdirectory(${CMAKE_SOURCE_DIR}/glm)


include_directories(${CMAKE_SOURCE_DIR}/
                    ${CMAKE_SOURCE_DIR}/include
                    ${CMAKE_SOURCE_DIR}/imgui
)

# Source files
file(GLOB_RECURSE SOURCES
    ${CMAKE_SOURCE_DIR}/test/main.cpp
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/glad/*.c
    ${CMAKE_SOURCE_DIR}/imgui/*.cpp
)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    add_compile_definitions(DEBUG)
endif()

# Add the executable
add_executable(mol ${SOURCES})

#target_include_directories(${project})

target_link_libraries(mol PRIVATE glfw opengl32.lib glm::glm)
#target_link_directories(${project} PRIVATE libs/lib-vc2010-64)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_PARALLEL_LEVEL 16)

