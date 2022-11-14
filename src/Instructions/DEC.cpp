#include <Instructions/DEC.h>
#include <iostream>

using namespace E6502_Instructions;

void
DEC::operator()(Word& PC,
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
            --memory[address];
            ++PC;
            processor_status.checkZero(memory[address]);
            processor_status.checkNegative(memory[address]);
        }
        break;
        case ABSOLUTE_10:
        {
            Word address = memory(PC);
            --memory[address];
            PC += 2;
            processor_status.checkZero(memory[address]);
            processor_status.checkNegative(memory[address]);
        }
        break;
        case ZERO_PAGE_X_10:
        {
            Byte address = memory[PC];
            address += X;
            --memory[address];
            ++PC;
            processor_status.checkZero(memory[address]);
            processor_status.checkNegative(memory[address]);
        }
        break;
        case ABSOLUTE_X_10:
        {
            Word address = memory(PC);
            address += X;
            --memory[address];
            PC += 2;
            processor_status.checkZero(memory[address]);
            processor_status.checkNegative(memory[address]);
        }
        break;
    }
}