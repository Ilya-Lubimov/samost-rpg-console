cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME Samost)

project(${PROJECT_NAME})

file(GLOB W_DLL "lib/*.dll")
file(GLOB C_HEADERS "include/*.h")
file(GLOB CPP_HEADERS "include/*.hpp")
file(GLOB CPP_SOURCES "src/*.cpp")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} ${C_HEADERS} ${CPP_HEADERS} ${CPP_SOURCES})

target_link_libraries(${PROJECT_NAME} ${W_DLL})