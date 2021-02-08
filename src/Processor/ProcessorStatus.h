#ifndef __E6502_PROCESSOR_PROCESSORSTATUS_H
#define __E6502_PROCESSOR_PROCESSORSTATUS_H

#include <Core/Defines.h>

namespace E6502
{
    struct ProcessorStatus
    {
        Byte C : 1;     /**< Carry bit */
        Byte Z : 1;     /**< Zero bit */
        Byte I : 1;     /**< Interrupt Disable */
        Byte D : 1;     /**< Decimal */
        Byte B : 1;     /**< Break */
        Byte Z_ :1;     /**< Unused */
        Byte V : 1;     /**< Overflow */
        Byte N : 1;     /**< Negative */
    };
}

#endif