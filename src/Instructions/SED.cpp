#include <Instructions/SED.h>

using namespace E6502_Instructions;

void 
SED::operator()(Word& PC,                            
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