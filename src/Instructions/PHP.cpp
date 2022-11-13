#include <Instructions/PHP.h>
#include <iostream>

using namespace E6502_Instructions;

void 
PHP::operator()(Word& PC,
                Byte& SP,                         
                Byte& A,                             
                Byte& X,                             
                Byte& Y,                             
                ProcessorStatus& processor_status,
                Memory& memory,
                AddressingModes& address_mode)
{
    Word stack = STACK_END + SP;
    Byte status = processor_status.asByte();
    status |= 0b00110000;
    memory[stack] = status;
    --SP;
} 