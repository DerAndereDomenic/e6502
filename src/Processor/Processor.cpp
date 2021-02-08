#include <Processor/Processor.h>

using namespace E6502;

Processor::Processor(Memory& memory)
    :memory(memory)
{
    reset();
}

void
Processor::reset()
{
    //TODO: Reset memory?
    SP = 0;
    PC = STACK_START + 1;
}