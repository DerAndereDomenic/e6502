#include <e6502/Instructions/TXA.h>

using namespace E6502_Instructions;

void TXA::apply(Word& PC,
                Byte& SP,
                Byte& A,
                Byte& X,
                Byte& Y,
                ProcessorStatus& processor_status,
                Memory& memory,
                AddressingModes& address_mode)
{
    A = X;
    processor_status.checkZero(A);
    processor_status.checkNegative(A);
}