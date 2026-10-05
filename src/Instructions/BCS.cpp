#include <e6502/Instructions/BCS.h>
#include <iostream>

using namespace E6502_Instructions;

void BCS::apply(Word& PC,
                Byte& SP,
                Byte& A,
                Byte& X,
                Byte& Y,
                ProcessorStatus& processor_status,
                Memory& memory,
                AddressingModes& address_mode)
{
    Byte offset = memory[PC];
    ++PC;

    if(processor_status.C == 1)
    {
        PC += static_cast<int8_t>(offset);
    }
}