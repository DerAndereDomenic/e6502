#include <e6502/Instructions/JMP.h>
#include <iostream>

using namespace E6502_Instructions;

void JMP_A::apply(Word& PC,
                  Byte& SP,
                  Byte& A,
                  Byte& X,
                  Byte& Y,
                  ProcessorStatus& processor_status,
                  Memory& memory,
                  AddressingModes& address_mode)
{
    Word address = memory(PC);
    PC           = address;
}
void JMP_I::apply(Word& PC,
                  Byte& SP,
                  Byte& A,
                  Byte& X,
                  Byte& Y,
                  ProcessorStatus& processor_status,
                  Memory& memory,
                  AddressingModes& address_mode)
{
    Word address = memory(PC);
    PC           = memory(address);
}