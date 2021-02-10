#include <Processor/Processor.h>
#include <assert.h>
#include <iostream>
#include <Instructions/Instructions.h>

using namespace E6502;

Processor::Processor(Memory& memory)
    :memory(memory)
{
    reset();

    instructions[CLC] = new E6502_Instructions::CLC();
    instructions[SEC] = new E6502_Instructions::SEC();
    instructions[CLI] = new E6502_Instructions::CLI();
    instructions[SEI] = new E6502_Instructions::SEI();
    instructions[CLV] = new E6502_Instructions::CLV();
    instructions[CLD] = new E6502_Instructions::CLD();
    instructions[SED] = new E6502_Instructions::SED();
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

void
Processor::printProcessorStatus()
{
    std::cout << "Program Counter: 0x" << std::hex <<  PC << std::endl;
    std::cout << "Stack Pointer: 0x" << std::hex << SP + (STACK_START) << std::endl;
    std::cout << "Register A: " << static_cast<int32_t>(A) << std::endl;
    std::cout << "Register X: " << static_cast<int32_t>(X) << std::endl;
    std::cout << "Register Y: " << static_cast<int32_t>(Y) << std::endl;

    std::cout << "|" << "C"
        << "|" << "Z"
        << "|" << "I"
        << "|" << "D"
        << "|" << "B"
        << "|" << "V"
        << "|" << "N" << "|" << std::endl;
    std::cout << "|" << static_cast<int32_t>(processor_status.C)
        << "|" << static_cast<int32_t>(processor_status.Z)
        << "|" << static_cast<int32_t>(processor_status.I)
        << "|" << static_cast<int32_t>(processor_status.D)
        << "|" << static_cast<int32_t>(processor_status.B)
        << "|" << static_cast<int32_t>(processor_status.V)
        << "|" << static_cast<int32_t>(processor_status.N) << "|" << std::dec << std::endl;
}