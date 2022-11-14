cmake_minimum_required(VERSION 3.10)

project(E6502 LANGUAGES CXX VERSION 1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /W3 /MTd")

add_executable(${PROJECT_NAME} src/source.cpp
                               src/Core/Defines.h
                               src/Processor/Processor.h src/Processor/Processor.cpp
                               src/Processor/ProcessorStatus.h src/Processor/ProcessorStatus.cpp
                               src/Processor/OpCodes.h
                               src/Memory/Memory.h src/Memory/Memory.cpp
                               src/Instructions/Instruction.h
                               src/Instructions/Instructions.h
							   src/Instructions/ADC.h src/Instructions/ADC.cpp
							   src/Instructions/AND.h src/Instructions/AND.cpp
							   src/Instructions/EOR.h src/Instructions/EOR.cpp
							   src/Instructions/ORA.h src/Instructions/ORA.cpp
							   src/Instructions/ASL.h src/Instructions/ASL.cpp
							   src/Instructions/LSR.h src/Instructions/LSR.cpp
							   src/Instructions/ROL.h src/Instructions/ROL.cpp
							   src/Instructions/ROR.h src/Instructions/ROR.cpp
                               src/Instructions/CLC.h src/Instructions/CLC.cpp
                               src/Instructions/SEC.h src/Instructions/SEC.cpp
                               src/Instructions/CLI.h src/Instructions/CLI.cpp
                               src/Instructions/SEI.h src/Instructions/SEI.cpp
                               src/Instructions/CLV.h src/Instructions/CLV.cpp
                               src/Instructions/CLD.h src/Instructions/CLD.cpp
                               src/Instructions/SED.h src/Instructions/SED.cpp
                               src/Instructions/LDA.h src/Instructions/LDA.cpp
							   src/Instructions/LDX.h src/Instructions/LDX.cpp
							   src/Instructions/LDY.h src/Instructions/LDY.cpp
							   src/Instructions/STA.h src/Instructions/STA.cpp
							   src/Instructions/STX.h src/Instructions/STX.cpp
							   src/Instructions/STY.h src/Instructions/STY.cpp
                               src/Instructions/TAX.h src/Instructions/TAX.cpp
                               src/Instructions/TXA.h src/Instructions/TXA.cpp
                               src/Instructions/DEX.h src/Instructions/DEX.cpp
                               src/Instructions/INX.h src/Instructions/INX.cpp
                               src/Instructions/TAY.h src/Instructions/TAY.cpp
                               src/Instructions/TYA.h src/Instructions/TYA.cpp
							   src/Instructions/TSX.h src/Instructions/TSX.cpp
							   src/Instructions/TXS.h src/Instructions/TXS.cpp
                               src/Instructions/DEY.h src/Instructions/DEY.cpp
							   src/Instructions/DEC.h src/Instructions/DEC.cpp
							   src/Instructions/INC.h src/Instructions/INC.cpp
                               src/Instructions/INY.h src/Instructions/INY.cpp
							   src/Instructions/PHA.h src/Instructions/PHA.cpp
							   src/Instructions/PLA.h src/Instructions/PLA.cpp
							   src/Instructions/PHP.h src/Instructions/PHP.cpp
							   src/Instructions/PLP.h src/Instructions/PLP.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC src)

option(E6502_BUILD_TESTS "Build the E6502 Tests" ON)

if(E6502_BUILD_TESTS)
    add_subdirectory(external/googletest)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif()