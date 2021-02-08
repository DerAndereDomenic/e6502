#ifndef __E6502_PROCESSOR_PROCESSOR_H
#define __E6502_PROCESSOR_PROCESSOR_H

#include <Core/Defines.h>

namespace E6502
{
    class Processor
    {
        public:
            Processor() = default;

            ~Processor() = default;
        private:
            Word PC;    /**< Program Counter */
            Byte SP;    /**< Stack Pointer */
            Byte A;     /**< Accumulator */
            Byte X;     /**< Index Register X */
            Byte Y;     /**< Index Register Y */
    };
}

#endif