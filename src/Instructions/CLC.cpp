#include <Instructions/CLC.h>

using namespace E6502_Instructions;

void 
CLC::operator()(Word& PC,                            
                Byte& SP,                         
                Byte& A,                             
                Byte& X,                             
                Byte& Y,                             
                ProcessorStatus& processor_status,
                Memory& memory)
{
    processor_status.C = 0;
} 