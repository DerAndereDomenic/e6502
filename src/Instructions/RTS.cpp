#include <e6502/Instructions/RTS.h>
#include <iostream>

using namespace E6502_Instructions;

void RTS::apply(Word& PC,
                Byte& SP,
                Byte& A,
                Byte& X,
                Byte& Y,
                ProcessorStatus& processor_status,
                Memory& memory,
                AddressingModes& address_mode)
{
    Word old_pc = memory(0x0100 + (SP + 1));
    SP += 2;
    PC = old_pc + 1;
}