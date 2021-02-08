#include <iostream>
#include <Processor/Processor.h>
#include <Memory/Memory.h>

int main()
{
    E6502::Processor procesor;
    E6502::Memory memory;

    memory[INIT_STACK] = 5;

    std::cout << static_cast<int>(memory[INIT_STACK]) << std::endl;

    return 0;
}