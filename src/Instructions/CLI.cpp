#include <Instructions/CLI.h>

using namespace E6502_Instructions;

void 
CLI::operator()(Word& PC,                            
                Byte& SP,                         
                Byte& A,                             
                Byte& X,                             
                Byte& Y,                             
                ProcessorStatus& processor_status,
                Memory& memory)
{
    processor_status.I = 0;
} 