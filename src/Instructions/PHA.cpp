#include <Instructions/PHA.h>
#include <iostream>

using namespace E6502_Instructions;

void 
PHA::operator()(Word& PC,
                Byte& SP,                         
                Byte& A,                             
                Byte& X,                             
                Byte& Y,                             
                ProcessorStatus& processor_status,
                Memory& memory,
                AddressingModes& address_mode)
{
    Word stack = STACK_END + SP;
    memory[stack] = A;
    --SP;
} 