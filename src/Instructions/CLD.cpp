#include <Instructions/CLD.h>

using namespace E6502_Instructions;

void 
CLD::operator()(Word& PC,                            
                Byte& SP,                         
                Byte& A,                             
                Byte& X,                             
                Byte& Y,                             
                ProcessorStatus& processor_status,
                Memory& memory)
{
    processor_status.D = 0;
} 