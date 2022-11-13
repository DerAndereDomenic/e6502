#include <Instructions/ASL.h>
#include <iostream>

using namespace E6502_Instructions;

void
ASL::operator()(Word& PC,
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
            Word val = memory[address];
            val = val << 1;
            memory[address] = val;

            ++PC;
            processor_status.checkCarry(val);
            processor_status.checkNegative(memory[address]);
            processor_status.checkZero(memory[address]);
        }
        break;
        case ABSOLUTE_10:
        {
            Word address = memory(PC);
            Word val = memory[address];
            val = val << 1;
            memory[address] = val;
            PC += 2;
            processor_status.checkCarry(val);
            processor_status.checkNegative(memory[address]);
            processor_status.checkZero(memory[address]);
        }
        break;
        case ZERO_PAGE_X_10:
        {
            Byte address = memory(PC);
            address += X;
            Word val = memory[address];
            val = val << 1;
            memory[address] = val;
            ++PC;
            processor_status.checkCarry(val);
            processor_status.checkNegative(memory[address]);
            processor_status.checkZero(memory[address]);
        }
        break;
        case ABSOLUTE_X_10:
        {
            Word address = memory(PC);
            address += X;
            Word val = memory[address];
            val = val << 1;
            memory[address] = val;
            PC += 2;
            processor_status.checkCarry(val);
            processor_status.checkNegative(memory[address]);
            processor_status.checkZero(memory[address]);
        }
        break;
        case ACCUMULATOR_10:
        {
            Word val = A;
            val = val << 1;
            A = val;
            processor_status.checkCarry(val);
            processor_status.checkNegative(A);
            processor_status.checkZero(A);
        }
        break;
    }
}