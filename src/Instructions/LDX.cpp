#include <Instructions/LDX.h>
#include <iostream>

using namespace E6502_Instructions;

void 
LDX::operator()(Word& PC,                            
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
            X = data;
            ++PC;
        }
        break;
        case IMMEDIATE_10:
        {
            Byte data = memory[PC];
            X = data;
            ++PC;
        }
        break;
        case ABSOLUTE_10:
        {
            Word address = memory(PC);
            Byte data = memory[address];
            X = data;
            PC+=2;
        }
        break;
        //Here is an exception because we are loading X but using Y to address (?)
        case ZERO_PAGE_X_10:
        {
            Byte address = memory(PC);
            address += Y;
            Byte data = memory[address];
            X = data;
            ++PC;
        }
        break;
        case ABSOLUTE_X_10:
        {
            Word address = memory(PC);
            address += Y;
            Byte data = memory[address];
            X = data;
            PC+=2;
        }
        break;
    }
    processor_status.checkZero(X);
    processor_status.checkNegative(X);
}