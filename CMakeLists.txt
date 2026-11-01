cmake_minimum_required(VERSION 3.21)
project(InputBufferMobilePlus VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "GEODE_SDK is not set. Use the Geode build action.")
endif()

add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)
setup_geode_mod()

target_sources(${PROJECT_NAME} PRIVATE src/InputBuffer.cpp)
