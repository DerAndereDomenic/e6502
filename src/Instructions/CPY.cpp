#include <e6502/Instructions/CPY.h>
#include <iostream>

using namespace E6502_Instructions;

void CPY::apply(Word& PC,
                Byte& SP,
                Byte& A,
                Byte& X,
                Byte& Y,
                ProcessorStatus& processor_status,
                Memory& memory,
                AddressingModes& address_mode)
{
    Byte op1 = Y;
    Byte op2 = 0;
    switch(address_mode)
    {
        case ZERO_PAGE_00:
        {
            Byte address = memory[PC];
            op2          = memory[address];
            ++PC;
        }
        break;
        case IMMEDIATE_00:
        {
            op2 = memory[PC];
            ++PC;
        }
        break;
        case ABSOLUTE_00:
        {
            Word address = memory(PC);
            op2          = memory[address];
            PC += 2;
        }
        break;
    }

    Byte result = op1 - op2;

    processor_status.checkCarry(result);
    processor_status.checkZero(result);
    processor_status.checkNegative(result);
}