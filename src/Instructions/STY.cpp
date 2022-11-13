#include <Instructions/STY.h>
#include <iostream>

using namespace E6502_Instructions;

void 
STY::operator()(Word& PC,                            
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
            memory[address] = Y;
            ++PC;
        }
        break;
        case ABSOLUTE_10:
        {
            Word address = memory(PC);
            memory[address] = Y;
            PC+=2;
        }
        break;
        case ZERO_PAGE_X_10:
        {
            Byte address = memory(PC);
            address += X;
            memory[address] = Y;
            ++PC;
        }
        break;
    }
}