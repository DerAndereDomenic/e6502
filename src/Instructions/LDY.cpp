#include <Instructions/LDY.h>
#include <iostream>

using namespace E6502_Instructions;

void 
LDY::operator()(Word& PC,                            
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
            Byte address = memory[PC];
            Byte data = memory[address];
            Y = data;
            ++PC;
        }
        break;
        case IMMEDIATE_10:
        {
            Byte data = memory[PC];
            Y = data;
            ++PC;
        }
        break;
        case ABSOLUTE_10:
        {
            Word address = memory(PC);
            Byte data = memory[address];
            Y = data;
            PC+=2;
        }
        break;
        case ZERO_PAGE_X_10:
        {
            Byte address = memory(PC);
            address += X;
            Byte data = memory[address];
            Y = data;
            ++PC;
        }
        break;
        case ABSOLUTE_X_10:
        {
            Word address = memory(PC);
            address += X;
            Byte data = memory[address];
            Y = data;
            PC+=2;
        }
        break;
    }
    processor_status.checkZero(Y);
    processor_status.checkNegative(Y);
}