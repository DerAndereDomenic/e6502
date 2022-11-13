#include <iostream>
#include <Processor/Processor.h>
#include <Memory/Memory.h>
#include <chrono>

int main()
{
    E6502::Memory memory;
    memory[0xF114] = 255;
    memory[STACK_START + 1] = E6502::LDA_A;
    memory[STACK_START + 2] = 0x14;
    memory[STACK_START + 3] = 0xF1;
    memory[STACK_START + 4] = E6502::ADC_I;
    memory[STACK_START + 5] = 1;
    memory[STACK_START + 6] = E6502::ADC_I;
    memory[STACK_START + 7] = 5;
    memory[STACK_START + 8] = E6502::PHA;
    memory[STACK_START + 9] = E6502::PLA;
    memory[STACK_START + 10] = E6502::PHP;
    memory[STACK_START + 11] = E6502::PLP;
    E6502::Processor processor(memory);

    auto start_time = std::chrono::high_resolution_clock::now();
    processor.start();
    auto end_time = std::chrono::high_resolution_clock::now();

    processor.printProcessorStatus();

    std::cout << "Execution time: " << (end_time-start_time)/std::chrono::milliseconds(1) << " ms" << std::endl;

    return 0;
}