#include <e6502/Instructions/CLC.h>

using namespace E6502_Instructions;

void CLC::apply(Word& PC,
                Byte& SP,
                Byte& A,
                Byte& X,
                Byte& Y,
                ProcessorStatus& processor_status,
                Memory& memory,
                AddressingModes& address_mode)
{
    processor_status.C = 0;
}