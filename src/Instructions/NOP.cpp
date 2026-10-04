#include <e6502/Instructions/NOP.h>
#include <iostream>

using namespace E6502_Instructions;

void NOP::apply(Word& PC,
                Byte& SP,
                Byte& A,
                Byte& X,
                Byte& Y,
                ProcessorStatus& processor_status,
                Memory& memory,
                AddressingModes& address_mode)
{
}