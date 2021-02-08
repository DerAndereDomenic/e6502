#include <Processor/Processor.h>

using namespace E6502;

Processor::Processor()
{
    reset();
}

void
Processor::reset()
{
    SP = 0;
    PC = STACK_START + 1;
}