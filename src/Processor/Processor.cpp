#include <Processor/Processor.h>
#include <assert.h>
#include <iostream>
#include <Instructions/Instructions.h>

using namespace E6502;

Processor::Processor(Memory& memory)
    :memory(memory)
{
    reset();

    ids.insert(std::make_pair(CLC, current_id));
    instructions[current_id++] = new E6502_Instructions::CLC();

    ids.insert(std::make_pair(SEC, current_id));
    instructions[current_id++] = new E6502_Instructions::SEC();

    ids.insert(std::make_pair(CLI, current_id));
    instructions[current_id++] = new E6502_Instructions::CLI();

    ids.insert(std::make_pair(SEI, current_id));
    instructions[current_id++] = new E6502_Instructions::SEI();

    ids.insert(std::make_pair(CLV, current_id));
    instructions[current_id++] = new E6502_Instructions::CLV();

    ids.insert(std::make_pair(CLD, current_id));
    instructions[current_id++] = new E6502_Instructions::CLD();

    ids.insert(std::make_pair(SED, current_id));
    instructions[current_id++] = new E6502_Instructions::SED();

    ids.insert(std::make_pair(LDA_I, current_id));
    ids.insert(std::make_pair(LDA_Z, current_id));
    ids.insert(std::make_pair(LDA_ZX, current_id));
    ids.insert(std::make_pair(LDA_A, current_id));
    ids.insert(std::make_pair(LDA_AX, current_id));
    ids.insert(std::make_pair(LDA_AY, current_id));
    ids.insert(std::make_pair(LDA_IX, current_id));
    ids.insert(std::make_pair(LDA_IY, current_id));
    instructions[current_id++] = new E6502_Instructions::LDA();

    ids.insert(std::make_pair(LDX_I, current_id));
    ids.insert(std::make_pair(LDX_Z, current_id));
    ids.insert(std::make_pair(LDX_ZY, current_id));
    ids.insert(std::make_pair(LDX_A, current_id));
    ids.insert(std::make_pair(LDX_AY, current_id));
    instructions[current_id++] = new E6502_Instructions::LDX();

    ids.insert(std::make_pair(LDY_I, current_id));
    ids.insert(std::make_pair(LDY_Z, current_id));
    ids.insert(std::make_pair(LDY_ZX, current_id));
    ids.insert(std::make_pair(LDY_A, current_id));
    ids.insert(std::make_pair(LDY_AX, current_id));
    instructions[current_id++] = new E6502_Instructions::LDY();

    ids.insert(std::make_pair(TAX, current_id));
    instructions[current_id++] = new E6502_Instructions::TAX();

    ids.insert(std::make_pair(TXA, current_id));
    instructions[current_id++] = new E6502_Instructions::TXA();

    ids.insert(std::make_pair(DEX, current_id));
    instructions[current_id++] = new E6502_Instructions::DEX();

    ids.insert(std::make_pair(INX, current_id));
    instructions[current_id++] = new E6502_Instructions::INX();

    ids.insert(std::make_pair(TAY, current_id));
    instructions[current_id++] = new E6502_Instructions::TAY();

    ids.insert(std::make_pair(DEY, current_id));
    instructions[current_id++] = new E6502_Instructions::DEY();

    ids.insert(std::make_pair(INY, current_id));
    instructions[current_id++] = new E6502_Instructions::INY();

    ids.insert(std::make_pair(TYA, current_id));
    instructions[current_id++] = new E6502_Instructions::TYA();
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
    current_id = 0;
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
        auto instruction = ids.find(static_cast<OpCodesAdressed>(opcode));
        assert(instruction != ids.end());
        uint32_t id = instruction->second;
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