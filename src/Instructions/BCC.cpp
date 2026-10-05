#include <e6502/Instructions/BCC.h>
#include <iostream>

using namespace E6502_Instructions;

void BCC::apply(Word& PC,
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

    if(processor_status.C == 0)
    {
        PC += static_cast<int8_t>(offset);
    }
}