cmake_minimum_required(VERSION 3.10)

# Project name
project(cplusplus-profile-test)

# Specify the compiler explicitly
set(CMAKE_CXX_COMPILER /usr/bin/g++)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directory for headers
include_directories(include)

# Add executable with source files in src folder
file(GLOB SOURCES "src/*.cpp")

add_executable(cplusplus-profile-test ${SOURCES})

# Optionally specify additional libraries or flags if necessary
