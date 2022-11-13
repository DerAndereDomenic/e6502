#include <Instructions/STA.h>
#include <iostream>

using namespace E6502_Instructions;

void 
STA::operator()(Word& PC,                            
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
        case ZERO_PAGE_X_INDIRECT_01:
        {
            Byte address = memory[PC] + X;
            memory[memory(address)] = A;
            ++PC;
        }
        break;
        case ZERO_PAGE_01:
        {
            Byte address = memory[PC];
            memory[address] = A;
            ++PC;
        }
        break;
        case ABSOLUTE_01:
        {
            Word address = memory(PC);
            memory[address] = A;
            PC+=2;
        }
        break;
        case ZERO_PAGE_Y_INDIRECT_01:
        {
            Byte address = memory[PC];
            memory[memory(address)+Y] = A;
            ++PC;
        }
        break;
        case ZERO_PAGE_X_01:
        {
            Byte address = memory(PC);
            address += X;
            memory[address] = A;
            ++PC;
        }
        break;
        case ABSOLUTE_Y_01:
        {
            Word address = memory(PC);
            address += Y;
            memory[address] = A;
            PC+=2;
        }
        break;
        case ABSOLUTE_X_01:
        {
            Word address = memory(PC);
            address += X;
            memory[address] = A;
            PC+=2;
        }
        break;
    }
}