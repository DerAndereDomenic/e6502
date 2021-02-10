#include <iostream>
#include <Processor/Processor.h>
#include <Memory/Memory.h>
#include <chrono>

int main()
{
    E6502::Memory memory;
    memory[STACK_START + 1] = E6502::LDA_I;
    memory[STACK_START + 2] = E6502::LDA_Z;
    memory[STACK_START + 3] = E6502::LDA_ZX;
    memory[STACK_START + 4] = E6502::LDA_A;
    memory[STACK_START + 5] = E6502::LDA_AX;
    memory[STACK_START + 6] = E6502::LDA_AY;
    memory[STACK_START + 7] = E6502::LDA_IX;
    memory[STACK_START + 8] = E6502::LDA_IY;
    E6502::Processor processor(memory);

    auto start_time = std::chrono::high_resolution_clock::now();
    processor.start();
    auto end_time = std::chrono::high_resolution_clock::now();

    processor.printProcessorStatus();

    std::cout << "Execution time: " << (end_time-start_time)/std::chrono::milliseconds(1) << " ms" << std::endl;

    return 0;
}