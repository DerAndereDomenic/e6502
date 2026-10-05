#include <e6502/Instructions/BPL.h>
#include <iostream>

using namespace E6502_Instructions;

void BPL::apply(Word& PC,
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

    if(processor_status.N == 0)
    {
        PC += static_cast<int8_t>(offset);
    }
}