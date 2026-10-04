#include <e6502/Instructions/INY.h>

using namespace E6502_Instructions;

void INY::apply(Word& PC,
                Byte& SP,
                Byte& A,
                Byte& X,
                Byte& Y,
                ProcessorStatus& processor_status,
                Memory& memory,
                AddressingModes& address_mode)
{
    ++Y;
    processor_status.checkZero(Y);
    processor_status.checkNegative(Y);
}