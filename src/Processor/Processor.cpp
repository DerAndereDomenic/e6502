#include <Processor/Processor.h>

using namespace E6502;

Processor::Processor(Memory& memory)
    :memory(memory)
{
    reset();
}

Processor::~Processor()
{
    for(uint32_t i = 0; i < PAGE_SIZE; ++i)
    {
        if(instructions[i] != nullptr)
        {
            delete instructions[i];
        }
    }
}

void
Processor::reset()
{
    //TODO: Reset memory?
    SP = 0;
    PC = STACK_START + 1;
}

void
Processor::start()
{
    //1) Fetch op
    //2) Increment PC
    //3) execute op
}