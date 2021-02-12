macro(package_add_test TESTNAME)
    # create an exectuable in which the tests will be stored
    add_executable(${TESTNAME} ${ARGN})
    # link the Google test infrastructure, mocking library, and a default main fuction to
    # the test executable.  Remove g_test_main if writing your own main function.
    target_link_libraries(${TESTNAME} gtest gtest_main)

    target_include_directories(${TESTNAME} PUBLIC ../external/googletest/googletest/include)

    target_include_directories(${TESTNAME} PUBLIC ../src)
    # gtest_discover_tests replaces gtest_add_tests,
    # see https://cmake.org/cmake/help/v3.10/module/GoogleTest.html for more options to pass to it
    gtest_discover_tests(${TESTNAME}
        # set a working directory so your project root so that you can find test data via paths relative to the project root
        WORKING_DIRECTORY ${PROJECT_DIR}
        PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_DIR}"
    )
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

package_add_test(OpCodesTests OpCodesTests.cpp)
package_add_test(BitCheckTests BitCheckTests.cpp ../src/Processor/ProcessorStatus.cpp)
package_add_test(InstructionTests InstructionTests.cpp 
                                      ../src/Instructions/LDA.cpp
                                      ../src/Instructions/CLC.cpp
                                      ../src/Instructions/CLD.cpp
                                      ../src/Instructions/CLI.cpp
                                      ../src/Instructions/CLV.cpp
                                      ../src/Instructions/DEX.cpp
                                      ../src/Instructions/DEY.cpp
                                      ../src/Instructions/INX.cpp
                                      ../src/Instructions/INY.cpp
                                      ../src/Instructions/SEC.cpp
                                      ../src/Instructions/SED.cpp
                                      ../src/Instructions/SEI.cpp
                                      ../src/Instructions/TAX.cpp
                                      ../src/Instructions/TAY.cpp
                                      ../src/Instructions/TXA.cpp
                                      ../src/Instructions/TYA.cpp
                                      ../src/Memory/Memory.cpp
                                      ../src/Processor/Processor.cpp
                                      ../src/Processor/ProcessorStatus.cpp
)