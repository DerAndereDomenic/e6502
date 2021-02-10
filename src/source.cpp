#include <iostream>
#include <Processor/Processor.h>
#include <Memory/Memory.h>

int main()
{
    E6502::Memory memory;
    E6502::Processor processor(memory);

    processor.start();

    processor.printProcessorStatus();

    E6502::ProcessorStatus status;

    uint8_t _byte = 255;
    int8_t byte = static_cast<int8_t>(_byte);
    int16_t word = static_cast<int16_t>(byte);

    std::cout << static_cast<int>(word) << std::endl;

    return 0;
}