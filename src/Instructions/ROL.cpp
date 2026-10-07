#include <e6502/Instructions/ROL.h>
#include <iostream>

using namespace E6502_Instructions;

void ROL::apply(Word& PC,
                Byte& SP,
                Byte& A,
                Byte& X,
                Byte& Y,
                ProcessorStatus& processor_status,
                Memory& memory,
                AddressingModes& address_mode)
{
    switch(address_mode)
    {
        case ZERO_PAGE_10:
        {
            Byte address       = memory[PC];
            Byte val           = memory[address];
            Byte old_carry     = processor_status.C;
            processor_status.C = (val & 0x80) >> 7;
            val                = val << 1;
            memory[address]    = val | old_carry;

            ++PC;
            processor_status.checkNegative(memory[address]);
            processor_status.checkZero(memory[address]);
        }
        break;
        case ABSOLUTE_10:
        {
            Word address       = memory(PC);
            Byte val           = memory[address];
            Byte old_carry     = processor_status.C;
            processor_status.C = (val & 0x80) >> 7;
            val                = val << 1;
            memory[address]    = val | old_carry;
            PC += 2;
            processor_status.checkNegative(memory[address]);
            processor_status.checkZero(memory[address]);
        }
        break;
        case ZERO_PAGE_X_10:
        {
            Byte address = memory[PC];
            address += X;
            Byte val           = memory[address];
            Byte old_carry     = processor_status.C;
            processor_status.C = (val & 0x80) >> 7;
            val                = val << 1;
            memory[address]    = val | old_carry;
            ++PC;
            processor_status.checkNegative(memory[address]);
            processor_status.checkZero(memory[address]);
        }
        break;
        case ABSOLUTE_X_10:
        {
            Word address = memory(PC);
            address += X;
            Byte val           = memory[address];
            Byte old_carry     = processor_status.C;
            processor_status.C = (val & 0x80) >> 7;
            val                = val << 1;
            memory[address]    = val | old_carry;
            PC += 2;
            processor_status.checkNegative(memory[address]);
            processor_status.checkZero(memory[address]);
        }
        break;
        case ACCUMULATOR_10:
        {
            Byte val           = A;
            Byte old_carry     = processor_status.C;
            processor_status.C = (val & 0x80) >> 7;
            val                = val << 1;
            A                  = val | old_carry;
            processor_status.checkNegative(A);
            processor_status.checkZero(A);
        }
        break;
    }
}