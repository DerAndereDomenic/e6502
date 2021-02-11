#include <iostream>
#include <Processor/Processor.h>
#include <Memory/Memory.h>
#include <chrono>

int main()
{
    E6502::Memory memory;
    memory[0xF114] = -42;
    memory[STACK_START + 1] = E6502::LDA_A;
    memory[STACK_START + 2] = 0x14;
    memory[STACK_START + 3] = 0xF1;
    E6502::Processor processor(memory);

    auto start_time = std::chrono::high_resolution_clock::now();
    processor.start();
    auto end_time = std::chrono::high_resolution_clock::now();

    processor.printProcessorStatus();

    std::cout << "Execution time: " << (end_time-start_time)/std::chrono::milliseconds(1) << " ms" << std::endl;

    return 0;
}