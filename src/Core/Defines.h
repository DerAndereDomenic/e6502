#ifndef __E6502_CORE_DEFINES_H
#define __E6502_CORE_DEFINES_H

#include <cstdint>

namespace E6502
{
    #define MEMORY_SIZE 0xFFFF
    #define INIT_STACK 0x01FF

    using Byte = int8_t;    //Byte
    using Word = int16_t;   //Word = 2 Bytes
}

#endif