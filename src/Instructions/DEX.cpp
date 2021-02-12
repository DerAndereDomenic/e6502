#include <Instructions/DEX.h>

using namespace E6502_Instructions;

void 
DEX::operator()(Word& PC,                            
                Byte& SP,                         
                Byte& A,                             
                Byte& X,                             
                Byte& Y,                             
                ProcessorStatus& processor_status,
                Memory& memory,
                AddressingModes& address_mode)
{
    --X;
    processor_status.checkZero(X);
    processor_status.checkNegative(X);
} 