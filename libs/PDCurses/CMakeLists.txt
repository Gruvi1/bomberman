project(PDCurses C)

file(GLOB HEADERS "pdcurses/*.h" "wincon/*.h")
file(GLOB SOURCES "pdcurses/*.c" "wincon/*.c")

add_library(PDCurses STATIC ${HEADERS} ${SOURCES})

target_include_directories(PDCurses PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})