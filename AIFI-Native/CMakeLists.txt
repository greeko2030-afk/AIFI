cmake_minimum_required(VERSION 3.10)
project(AIFI_Engine VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(JNI REQUIRED)

# Fix: Added CMAKE_CURRENT_SOURCE_DIR to ensure the compiler finds the absolute path
include_directories(${JNI_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/include)

add_library(aifi_engine SHARED src/AIFINativeEngine.cpp)

target_link_libraries(aifi_engine ${JNI_LIBRARIES})
