#ifndef __E6502_MEMORY_MEMORY_H
#define __E6502_MEMORY_MEMORY_H

#include <Core/Defines.h>

namespace E6502
{
    class Memory
    {
        public:
            Memory() = default;

            ~Memory() = default;

            /**
             *  @brief Get the byte at the specified location
             *  @param pointer The pointer to memory
             *  @return The byte stored at the specified location (reference)
             */
            Byte& operator[](const Word& pointer);
        private:
            Byte RAM[MEMORY_SIZE] = {0,};
    };
}

#endif