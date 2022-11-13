#include <Instructions/TXS.h>

using namespace E6502_Instructions;

void 
TXS::operator()(Word& PC,
                Byte& SP,                         
                Byte& A,                             
                Byte& X,                             
                Byte& Y,                             
                ProcessorStatus& processor_status,
                Memory& memory,
                AddressingModes& address_mode)
{
    SP = X;
} 