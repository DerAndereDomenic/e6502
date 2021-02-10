#include <Instructions/LDA.h>
#include <iostream>

using namespace E6502_Instructions;

void 
LDA::operator()(Word& PC,                            
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
            std::cout << "LDA: Zero Page X Indirect" << std::endl;
        }
        break;
        case ZERO_PAGE_01:
        {
            Byte address = memory[PC];
            Byte data = memory[address];
            A = data;
            ++PC;
        }
        break;
        case IMMEDIATE_01:
        {
            Byte data = memory[PC];
            A = data;
            ++PC;
        }
        break;
        case ABSOLUTE_01:
        {
            std::cout << "LDA: Absolute" << std::endl;
        }
        break;
        case ZERO_PAGE_Y_INDIRECT_01:
        {
            std::cout << "LDA: Zero Page Y Indirect" << std::endl;
        }
        break;
        case ZERO_PAGE_X_01:
        {
            std::cout << "LDA: Zero Page X" << std::endl;
        }
        break;
        case ABSOLUTE_Y_01:
        {
            std::cout << "LDA: Absolute Y" << std::endl;
        }
        break;
        case ABSOLUTE_X_01:
        {
            std::cout << "LDA: Absolute X" << std::endl;
        }
        break;
    }
    processor_status.checkZero(A);
    processor_status.checkNegative(A);
}