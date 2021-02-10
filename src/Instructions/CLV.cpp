#include <Instructions/CLV.h>

using namespace E6502_Instructions;

void 
CLV::operator()(Word& PC,                            
                Byte& SP,                         
                Byte& A,                             
                Byte& X,                             
                Byte& Y,                             
                ProcessorStatus& processor_status,
                Memory& memory)
{
    processor_status.V = 0;
} 