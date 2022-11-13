#include <Instructions/AND.h>
#include <iostream>

using namespace E6502_Instructions;

void
AND::operator()(Word& PC,
                Byte& SP,
                Byte& A,
                Byte& X,
                Byte& Y,
                ProcessorStatus& processor_status,
                Memory& memory,
                AddressingModes& address_mode)
{
    Byte op1 = A;
    Byte op2 = 0;
    switch (address_mode)
    {
        case ZERO_PAGE_X_INDIRECT_01:
        {
            Byte address = memory[PC] + X;
            op2 = memory[memory(address)];
            ++PC;
        }
        break;
        case ZERO_PAGE_01:
        {
            Byte address = memory[PC];
            op2 = memory[address];
            ++PC;
        }
        break;
        case IMMEDIATE_01:
        {
            op2 = memory[PC];
            ++PC;
        }
        break;
        case ABSOLUTE_01:
        {
            Word address = memory(PC);
            op2 = memory[address];
            PC += 2;
        }
        break;
        case ZERO_PAGE_Y_INDIRECT_01:
        {
            Byte address = memory[PC];
            op2 = memory[memory(address) + Y];
            ++PC;
        }
        break;
        case ZERO_PAGE_X_01:
        {
            Byte address = memory(PC);
            address += X;
            op2 = memory[address];
            ++PC;
        }
        break;
        case ABSOLUTE_Y_01:
        {
            Word address = memory(PC);
            address += Y;
            op2 = memory[address];
            PC += 2;
        }
        break;
        case ABSOLUTE_X_01:
        {
            Word address = memory(PC);
            address += X;
            op2 = memory[address];
            PC += 2;
        }
        break;
    }

    Word result = op1 & op2;
    A = result;

    processor_status.checkZero(A);
    processor_status.checkNegative(A);
}