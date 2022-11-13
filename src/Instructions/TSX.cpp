#include <Instructions/TSX.h>

using namespace E6502_Instructions;

void 
TSX::operator()(Word& PC,                            
                Byte& SP,                         
                Byte& A,                             
                Byte& X,                             
                Byte& Y,                             
                ProcessorStatus& processor_status,
                Memory& memory,
                AddressingModes& address_mode)
{
    X = SP;
    processor_status.checkNegative(X);
    processor_status.checkZero(X);
} 