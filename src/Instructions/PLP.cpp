#include <Instructions/PLP.h>
#include <iostream>

using namespace E6502_Instructions;

void 
PLP::operator()(Word& PC,
                Byte& SP,                         
                Byte& A,                             
                Byte& X,                             
                Byte& Y,                             
                ProcessorStatus& processor_status,
                Memory& memory,
                AddressingModes& address_mode)
{
    ++SP;
    Word stack = STACK_END + SP;
    Byte status = memory[stack];
    status &= ~0b00110000;
    processor_status.fromByte(status);
} 