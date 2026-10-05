#include <e6502/Instructions/BVS.h>
#include <iostream>

using namespace E6502_Instructions;

void BVS::apply(Word& PC,
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

    if(processor_status.V == 1)
    {
        PC += static_cast<int8_t>(offset);
    }
}