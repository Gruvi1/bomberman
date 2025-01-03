cmake_minimum_required(VERSION 3.15)

project (bomberman CXX)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

include_directories(./include ./src)

file(GLOB HEADERS "src/*.h")
file(GLOB SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} main.cpp ${HEADERS} ${SOURCES})

add_subdirectory(libs)
target_link_libraries(${PROJECT_NAME} PDCurses)