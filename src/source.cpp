#include <iostream>
#include <Processor/Processor.h>
#include <Memory/Memory.h>

int main()
{
    E6502::Memory memory;
    E6502::Processor processor(memory);

    memory[STACK_START] = 5;

    std::cout << static_cast<int>(memory[STACK_START]) << std::endl;

    return 0;
}