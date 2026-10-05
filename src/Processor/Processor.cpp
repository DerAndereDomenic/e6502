#include <assert.h>
#include <iostream>
#include <e6502/Instructions/Instructions.h>
#include <e6502/Processor/Processor.h>

using namespace E6502;

Processor::Processor(Memory& memory) : memory(memory)
{
    reset();
}

Processor::~Processor() {}

void Processor::reset()
{
    // TODO: Reset memory?
    // The stack is defined from 0x01ff to 0x0100 starting from 0x01ff. Therefore, the 8-Bit Stackpointer is 0xff at the
    // start.
    SP = 0xFF;
    PC = STACK_START + 1;
}

void Processor::start()
{
    while(true)
    {
        // 1) Fetch op
        Byte opcode = memory[PC];
        // Check if BRK
        if(opcode == 0)
        {
            std::cout << "BRK encountered! Stop execution..." << std::endl;
            return;
        }
        // 2) Increment PC
        ++PC;
        // 3) execute op
        AddressingModes addressing = static_cast<AddressingModes>((ADDRESS_MASK & opcode) >> 2);

        _applyInstruction(static_cast<OpCodesAdressed>(opcode), addressing);
    }
}

void Processor::printProcessorStatus()
{
    std::cout << "Program Counter: 0x" << std::hex << PC << std::endl;
    std::cout << "Stack Pointer: 0x" << std::hex << SP + (STACK_END) << std::endl;
    std::cout << "Register A: " << static_cast<int32_t>(A) << std::endl;
    std::cout << "Register X: " << static_cast<int32_t>(X) << std::endl;
    std::cout << "Register Y: " << static_cast<int32_t>(Y) << std::endl;

    std::cout << "|"
              << "C"
              << "|"
              << "Z"
              << "|"
              << "I"
              << "|"
              << "D"
              << "|"
              << "B"
              << "|"
              << "V"
              << "|"
              << "N"
              << "|" << std::endl;
    std::cout << "|" << static_cast<int32_t>(processor_status.C) << "|" << static_cast<int32_t>(processor_status.Z)
              << "|" << static_cast<int32_t>(processor_status.I) << "|" << static_cast<int32_t>(processor_status.D)
              << "|" << static_cast<int32_t>(processor_status.B) << "|" << static_cast<int32_t>(processor_status.V)
              << "|" << static_cast<int32_t>(processor_status.N) << "|" << std::dec << std::endl;

    memory.print();
}

void Processor::_applyInstruction(const OpCodesAdressed& op_code, AddressingModes& addressing_mode)
{
    switch(op_code)
    {
        case CLC:
        {
            E6502_Instructions::CLC::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case SEC:
        {
            E6502_Instructions::SEC::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case CLI:
        {
            E6502_Instructions::CLI::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case SEI:
        {
            E6502_Instructions::SEI::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case CLV:
        {
            E6502_Instructions::CLV::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case CLD:
        {
            E6502_Instructions::CLD::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case SED:
        {
            E6502_Instructions::SED::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case ADC_I:
        case ADC_Z:
        case ADC_ZX:
        case ADC_A:
        case ADC_AX:
        case ADC_AY:
        case ADC_IX:
        case ADC_IY:
        {
            E6502_Instructions::ADC::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case AND_I:
        case AND_Z:
        case AND_ZX:
        case AND_A:
        case AND_AX:
        case AND_AY:
        case AND_IX:
        case AND_IY:
        {
            E6502_Instructions::AND::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case EOR_I:
        case EOR_Z:
        case EOR_ZX:
        case EOR_A:
        case EOR_AX:
        case EOR_AY:
        case EOR_IX:
        case EOR_IY:
        {
            E6502_Instructions::EOR::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case ORA_I:
        case ORA_Z:
        case ORA_ZX:
        case ORA_A:
        case ORA_AX:
        case ORA_AY:
        case ORA_IX:
        case ORA_IY:
        {
            E6502_Instructions::ORA::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case ASL_AC:
        case ASL_Z:
        case ASL_ZX:
        case ASL_A:
        case ASL_AX:
        {
            E6502_Instructions::ASL::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case LSR_AC:
        case LSR_Z:
        case LSR_ZX:
        case LSR_A:
        case LSR_AX:
        {
            E6502_Instructions::LSR::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case ROL_AC:
        case ROL_Z:
        case ROL_ZX:
        case ROL_A:
        case ROL_AX:
        {
            E6502_Instructions::ROL::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case ROR_AC:
        case ROR_Z:
        case ROR_ZX:
        case ROR_A:
        case ROR_AX:
        {
            E6502_Instructions::ROR::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case LDA_I:
        case LDA_Z:
        case LDA_ZX:
        case LDA_A:
        case LDA_AX:
        case LDA_AY:
        case LDA_IX:
        case LDA_IY:
        {
            E6502_Instructions::LDA::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case STA_Z:
        case STA_ZX:
        case STA_A:
        case STA_AX:
        case STA_AY:
        case STA_IX:
        case STA_IY:
        {
            E6502_Instructions::STA::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case LDX_I:
        case LDX_Z:
        case LDX_ZY:
        case LDX_A:
        case LDX_AY:
        {
            E6502_Instructions::LDX::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case STX_Z:
        case STX_ZY:
        case STX_A:
        {
            E6502_Instructions::STX::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case LDY_I:
        case LDY_Z:
        case LDY_ZX:
        case LDY_A:
        case LDY_AX:
        {
            E6502_Instructions::LDY::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case STY_Z:
        case STY_ZX:
        case STY_A:
        {
            E6502_Instructions::STY::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case DEC_Z:
        case DEC_ZX:
        case DEC_A:
        case DEC_AX:
        {
            E6502_Instructions::DEC::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case INC_Z:
        case INC_ZX:
        case INC_A:
        case INC_AX:
        {
            E6502_Instructions::INC::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case TAX:
        {
            E6502_Instructions::TAX::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case TXA:
        {
            E6502_Instructions::TXA::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case DEX:
        {
            E6502_Instructions::DEX::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case INX:
        {
            E6502_Instructions::INX::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case TAY:
        {
            E6502_Instructions::TAY::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case TSX:
        {
            E6502_Instructions::TSX::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case TXS:
        {
            E6502_Instructions::TXS::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case DEY:
        {
            E6502_Instructions::DEY::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case INY:
        {
            E6502_Instructions::INY::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case TYA:
        {
            E6502_Instructions::TYA::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case PHA:
        {
            E6502_Instructions::PHA::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case PHP:
        {
            E6502_Instructions::PHP::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case PLA:
        {
            E6502_Instructions::PLA::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case PLP:
        {
            E6502_Instructions::PLP::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case JMP_A:
        {
            E6502_Instructions::JMP_A::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case JMP_I:
        {
            E6502_Instructions::JMP_I::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case NOP:
        {
            E6502_Instructions::NOP::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case JSR_A:
        {
            E6502_Instructions::JSR::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case RTS:
        {
            E6502_Instructions::RTS::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case BCC:
        {
            E6502_Instructions::BCC::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case BCS:
        {
            E6502_Instructions::BCS::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case BEQ:
        {
            E6502_Instructions::BEQ::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case BMI:
        {
            E6502_Instructions::BMI::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case BNE:
        {
            E6502_Instructions::BNE::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        case SBC_I:
        case SBC_Z:
        case SBC_ZX:
        case SBC_A:
        case SBC_AX:
        case SBC_AY:
        case SBC_IX:
        case SBC_IY:
        {
            E6502_Instructions::SBC::apply(PC, SP, A, X, Y, processor_status, memory, addressing_mode);
        }
        break;

        default:
        {
            std::cout << "Unknown opcode: 0x" << std::hex << static_cast<int32_t>(op_code) << std::endl;
            assert(false);
        }
        break;
    }
}