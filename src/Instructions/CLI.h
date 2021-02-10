#ifndef __E6502_INSTRUCTIONS_CLI_H
#define __E6502_INSTRUCTIONS_CLI_H

#include <Instructions/Instruction.h>

namespace E6502_Instructions
{
    using namespace E6502;
    /**
     *  @brief Clear Interrupt
     */
    class CLI : public Instruction
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
             */
            void operator()(Word& PC,                            
                            Byte& SP,                         
                            Byte& A,                             
                            Byte& X,                             
                            Byte& Y,                             
                            ProcessorStatus& processor_status,
                            Memory& memory) override;  
    };
}

#endif