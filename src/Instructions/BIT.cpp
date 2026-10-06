#include <e6502/Instructions/BIT.h>
#include <iostream>

using namespace E6502_Instructions;

void BIT::apply(Word& PC,
                Byte& SP,
                Byte& A,
                Byte& X,
                Byte& Y,
                ProcessorStatus& processor_status,
                Memory& memory,
                AddressingModes& address_mode)
{
    Byte val;
    switch(address_mode)
    {
        case ZERO_PAGE_00:
        {
            Byte address = memory[PC];
            val          = memory[address];
            ++PC;
        }
        break;
        case ABSOLUTE_00:
        {
            Word address = memory(PC);
            val          = memory[address];
            PC += 2;
        }
        break;
    }

    Byte res = A & val;
    processor_status.checkZero(res);
    processor_status.checkNegative(res);
    processor_status.V = (val & 0b01000000) >> 6;
}