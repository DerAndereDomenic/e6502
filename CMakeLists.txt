cmake_minimum_required(VERSION 3.10)

project(E6502 LANGUAGES CXX VERSION 1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /W3 /MTd")

# Glob files
file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS include/*.h)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(E6502_Example app/source.cpp)
target_link_libraries(E6502_Example E6502)

option(E6502_BUILD_TESTS "Build the E6502 Tests" ON)

if(E6502_BUILD_TESTS)
    add_subdirectory(external/googletest)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif()