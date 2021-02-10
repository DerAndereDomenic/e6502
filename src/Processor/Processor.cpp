#include <Processor/Processor.h>
#include <assert.h>
#include <iostream>
#include <Instructions/Instructions.h>

using namespace E6502;

Processor::Processor(Memory& memory)
    :memory(memory)
{
    reset();

    ids.insert(std::make_pair(CLC, 0));
    instructions[0] = new E6502_Instructions::CLC();

    ids.insert(std::make_pair(SEC, 1));
    instructions[1] = new E6502_Instructions::SEC();

    ids.insert(std::make_pair(CLI, 2));
    instructions[2] = new E6502_Instructions::CLI();

    ids.insert(std::make_pair(SEI, 3));
    instructions[3] = new E6502_Instructions::SEI();

    ids.insert(std::make_pair(CLV, 4));
    instructions[4] = new E6502_Instructions::CLV();

    ids.insert(std::make_pair(CLD, 5));
    instructions[5] = new E6502_Instructions::CLD();

    ids.insert(std::make_pair(SED, 6));
    instructions[6] = new E6502_Instructions::SED();
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
    ids.clear();
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
    while(true)
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
        AddressingModes addressing = static_cast<AddressingModes>((ADDRESS_MASK & opcode) >> 2);
        uint32_t id = ids.find(static_cast<OpCodesAdressed>(opcode))->second;
        Instruction* op = instructions[id];
        assert(op != nullptr);
        op->operator()(PC, SP, A, X, Y, processor_status, memory, addressing); 
    }
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