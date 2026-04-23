cmake_minimum_required(VERSION 3.10)
project(MSVCRenamer VERSION 1.0.0 LANGUAGES CXX)

add_library(pugixml STATIC external/pugixml/pugixml.cpp)
target_include_directories(pugixml PUBLIC external/pugixml)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(msvcrenamer ${SOURCES})

target_include_directories(msvcrenamer PRIVATE src)

target_link_libraries(msvcrenamer pugixml)

set_target_properties(msvcrenamer PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)