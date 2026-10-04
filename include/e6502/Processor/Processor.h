#ifndef __E6502_PROCESSOR_PROCESSOR_H
#define __E6502_PROCESSOR_PROCESSOR_H

#include <e6502/Core/Defines.h>
#include <e6502/Processor/ProcessorStatus.h>
#include <e6502/Processor/OpCodes.h>
#include <e6502/Memory/Memory.h>
#include <e6502/Instructions/Instruction.h>
#include <unordered_map>

namespace E6502
{
class Processor
{
public:
    Processor(Memory& memory);

    ~Processor();

    /**
     *  @brief Resets the processor to the initial state.
     */
    void reset();

    /**
     *  @brief Starts exectuting the processor starting at the program counter until BRK is encountered.
     */
    void start();

    /**
     *  @brief Print the current processor status
     */
    void printProcessorStatus();
    // private:
    Word PC;                          /**< Program Counter */
    Byte SP;                          /**< Stack Pointer */
    Byte A;                           /**< Accumulator */
    Byte X;                           /**< Index Register X */
    Byte Y;                           /**< Index Register Y */
    ProcessorStatus processor_status; /**< The processor status */
    Memory memory;                    /**< The memory the processor is working with */

    Instruction* instructions[PAGE_SIZE] = {
        nullptr,
    }; /**< Array of alle instructions */

    uint32_t current_id = 0;
    std::unordered_map<OpCodesAdressed, uint32_t> ids;
};
}    // namespace E6502

#endif