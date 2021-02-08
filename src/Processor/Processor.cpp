#include <Processor/Processor.h>
#include <assert.h>
#include <iostream>

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
    Byte opcode = memory[PC];
    //Check if BRK
    if(opcode == 0)
    {
        std::cout << "BRK encountered! Stop execution..." << std::endl;
        return;
    }
    //2) Increment PC
    ++PC;
    //3) execute op
    Instruction* op = instructions[opcode];
    assert(op != nullptr);
    op->operator()(PC, SP, A, X, Y, processor_status, memory); 
}