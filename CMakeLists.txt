cmake_minimum_required(VERSION 3.10)

project(E6502 LANGUAGES CXX VERSION 1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} src/source.cpp
                               src/Core/Defines.h
                               src/Processor/Processor.h src/Processor/Processor.cpp
                               src/Processor/ProcessorStatus.h
)

target_include_directories(${PROJECT_NAME} PUBLIC src)