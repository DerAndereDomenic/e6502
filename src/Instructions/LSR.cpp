#include <Instructions/LSR.h>
#include <iostream>

using namespace E6502_Instructions;

void
LSR::operator()(Word& PC,
                Byte& SP,
                Byte& A,
                Byte& X,
                Byte& Y,
                ProcessorStatus& processor_status,
                Memory& memory,
                AddressingModes& address_mode)
{
    switch (address_mode)
    {
        case ZERO_PAGE_10:
        {
            Byte address = memory[PC];
            Byte val = memory[address];
            val = val >> 1;
            memory[address] = val;

            ++PC;
            processor_status.N = 0;
            processor_status.checkZero(memory[address]);
        }
        break;
        case ABSOLUTE_10:
        {
            Word address = memory(PC);
            Byte val = memory[address];
            processor_status.C = val & 1;
            val = val >> 1;
            memory[address] = val;
            PC += 2;
            processor_status.N = 0;
            processor_status.checkZero(memory[address]);
        }
        break;
        case ZERO_PAGE_X_10:
        {
            Byte address = memory(PC);
            address += X;
            Byte val = memory[address];
            processor_status.C = val & 1;
            val = val >> 1;
            memory[address] = val;
            ++PC;
            processor_status.N = 0;
            processor_status.checkZero(memory[address]);
        }
        break;
        case ABSOLUTE_X_10:
        {
            Word address = memory(PC);
            address += X;
            Byte val = memory[address];
            processor_status.C = val & 1;
            val = val >> 1;
            memory[address] = val;
            PC += 2;
            processor_status.N = 0;
            processor_status.checkZero(memory[address]);
        }
        break;
        case ACCUMULATOR_10:
        {
            Byte val = A;
            processor_status.C = val & 1;
            val = val >> 1;
            A = val;
            processor_status.N = 0;
            processor_status.checkZero(A);
        }
        break;
    }
}