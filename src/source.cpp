#include <iostream>
#include <Processor/Processor.h>
#include <Memory/Memory.h>

int main()
{
    E6502::Memory memory;
    E6502::Processor processor(memory);

    processor.start();

    processor.printProcessorStatus();

    return 0;
}