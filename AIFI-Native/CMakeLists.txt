cmake_minimum_required(VERSION 3.10)
project(AIFI_Engine VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(JNI REQUIRED)

include_directories(${JNI_INCLUDE_DIRS})
include_directories(src/include)

add_library(aifi_engine SHARED src/AIFINativeEngine.cpp)

target_link_libraries(aifi_engine ${JNI_LIBRARIES})
