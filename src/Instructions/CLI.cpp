#include <e6502/Instructions/CLI.h>

using namespace E6502_Instructions;

void CLI::apply(Word& PC,
                Byte& SP,
                Byte& A,
                Byte& X,
                Byte& Y,
                ProcessorStatus& processor_status,
                Memory& memory,
                AddressingModes& address_mode)
{
    processor_status.I = 0;
}