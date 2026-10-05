#ifndef __E6502_INSTRUCTIONS_BVS_H
#define __E6502_INSTRUCTIONS_BVS_H

#include <e6502/Core/Defines.h>
#include <e6502/Processor/ProcessorStatus.h>
#include <e6502/Memory/Memory.h>
#include <e6502/Processor/OpCodes.h>

namespace E6502_Instructions
{
using namespace E6502;
/**
 *  @brief BVS operation
 */
class BVS
{
public:
    /**
     *  @brief The Instruction operator.
     *  The derived class has to implement this operator based on the operators definition
     *  and update registers/pointers/Processor status as defined by the operator
     *  @param PC The program counter
     *  @param SP The stack pointer
     *  @param A The A register
     *  @param X The X register
     *  @param Y The Y register
     *  @param processor_status The processor status
     *  @param memory The memory
     *  @param address_mode The addressing mode
     */
    static void apply(Word& PC,
                      Byte& SP,
                      Byte& A,
                      Byte& X,
                      Byte& Y,
                      ProcessorStatus& processor_status,
                      Memory& memory,
                      AddressingModes& address_mode);
};
}    // namespace E6502_Instructions

#endif