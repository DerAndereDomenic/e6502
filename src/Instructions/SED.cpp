#include <e6502/Instructions/SED.h>

using namespace E6502_Instructions;

void SED::apply(Word& PC,
                Byte& SP,
                Byte& A,
                Byte& X,
                Byte& Y,
                ProcessorStatus& processor_status,
                Memory& memory,
                AddressingModes& address_mode)
{
    processor_status.D = 1;
}