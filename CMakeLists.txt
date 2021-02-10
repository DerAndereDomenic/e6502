cmake_minimum_required(VERSION 3.10)

project(E6502 LANGUAGES CXX VERSION 1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} src/source.cpp
                               src/Core/Defines.h
                               src/Processor/Processor.h src/Processor/Processor.cpp
                               src/Processor/ProcessorStatus.h src/Processor/ProcessorStatus.cpp
                               src/Processor/OpCodes.h
                               src/Memory/Memory.h src/Memory/Memory.cpp
                               src/Instructions/Instruction.h
)

target_include_directories(${PROJECT_NAME} PUBLIC src)

option(E6502_BUILD_TESTS "Build the E6502 Tests" ON)

if(E6502_BUILD_TESTS)
    add_subdirectory(external/googletest)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif()