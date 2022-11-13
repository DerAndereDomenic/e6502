#include <iostream>
#include <Processor/Processor.h>
#include <Memory/Memory.h>
#include <chrono>

int main()
{
    E6502::Memory memory;
    memory[0xF114] = 255;
    memory[0xF115] = 1;
    memory[0xF116] = 3;
    memory[0x0016] = 0xFE;
    memory[STACK_START + 1] = E6502::LDA_A;
    memory[STACK_START + 2] = 0x14;
    memory[STACK_START + 3] = 0xF1;
    memory[STACK_START + 4] = E6502::ADC_I;
    memory[STACK_START + 5] = 1;
    memory[STACK_START + 6] = E6502::ADC_I;
    memory[STACK_START + 7] = 6;
    memory[STACK_START + 8] = E6502::PHA;
    memory[STACK_START + 9] = E6502::PLA;
    memory[STACK_START + 10] = E6502::PHP;
    memory[STACK_START + 11] = E6502::PLP;
    memory[STACK_START + 12] = E6502::AND_A;
    memory[STACK_START + 13] = 0x15;
    memory[STACK_START + 14] = 0xF1;
    memory[STACK_START + 15] = E6502::LDA_I;
    memory[STACK_START + 16] = 0x1;
    memory[STACK_START + 17] = E6502::ASL_AC;
    memory[STACK_START + 18] = E6502::LDX_I;
    memory[STACK_START + 19] = 1;
    memory[STACK_START + 20] = E6502::ASL_ZX;
    memory[STACK_START + 21] = 0x15;
    memory[STACK_START + 22] = E6502::LDA_I;
    memory[STACK_START + 23] = 0x1;
    memory[STACK_START + 24] = E6502::EOR_A;
    memory[STACK_START + 25] = 0x16;
    memory[STACK_START + 26] = 0xF1;
    memory[STACK_START + 27] = E6502::LDA_I;
    memory[STACK_START + 28] = 0x1;
    memory[STACK_START + 29] = E6502::STA_A;
    memory[STACK_START + 30] = 0x17;
    memory[STACK_START + 31] = 0xF1;
    memory[STACK_START + 32] = E6502::LDX_I;
    memory[STACK_START + 33] = 0x42;
    memory[STACK_START + 34] = E6502::STX_Z;
    memory[STACK_START + 35] = 0x17;
    E6502::Processor processor(memory);

    auto start_time = std::chrono::high_resolution_clock::now();
    processor.start();
    auto end_time = std::chrono::high_resolution_clock::now();

    processor.printProcessorStatus();

    std::cout << "Execution time: " << (end_time-start_time)/std::chrono::milliseconds(1) << " ms" << std::endl;

    return 0;
}