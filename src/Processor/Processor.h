#ifndef __E6502_PROCESSOR_PROCESSOR_H
#define __E6502_PROCESSOR_PROCESSOR_H

#include <Core/Defines.h>
#include <Processor/ProcessorStatus.h>

namespace E6502
{
    class Processor
    {
        public:
            Processor();

            ~Processor() = default;

            /**
             *  @brief Resets the processor to the initial state.
             */
            void
            reset();
        private:
            Word PC;                            /**< Program Counter */
            Byte SP;                            /**< Stack Pointer */
            Byte A;                             /**< Accumulator */
            Byte X;                             /**< Index Register X */
            Byte Y;                             /**< Index Register Y */
            ProcessorStatus processor_status;   /**< The processor status */
    };
}

#endif