#include <e6502/Instructions/PLA.h>
#include <iostream>

using namespace E6502_Instructions;

void PLA::operator()(Word& PC,
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
    A          = memory[stack];
    processor_status.checkNegative(A);
    processor_status.checkZero(A);
}