#ifndef __E6502_PROCESSOR_PROCESSORSTATUS_H
#define __E6502_PROCESSOR_PROCESSORSTATUS_H

#include <Core/Defines.h>

namespace E6502
{
    struct ProcessorStatus
    {
        /**
         *  @brief Check if the given byte is zero.
         *  If the byte is zero, the zero bit is set to 1, 0 otherwise
         *  @param byte The byte to check
         */
        void 
        checkZero(const Byte& byte);

        /**
         *  @brief Check if the carry bit is set.
         *  The calculation should be converted to a Word (16 bit).
         *  This way we can check if the input is out of the range [0,255].
         *  Sets the carry bit 1 if words 9th bit is set, 0 otherwise.
         *  @param word The word to check
         */
        void 
        checkCarry(const int16_t& word);

        /**
         *  @brief Check if overflow was encountered for inp1+inp2.
         *  @param inp1 The first input
         *  @param inp2 The second input
         *  @param c The carry
         */
        void 
        checkOverflow(const Byte& inp1, const Byte& inp2, const Byte& c = 0);

        /**
         *  @brief Check if the byte is negative.
         *  The negative bit gets set to the 8th bit.
         *  @param byte The byte to check. 
         */
        void 
        checkNegative(const Byte& byte);

        /**
        *   @brief Get the current processor status as byte
        * 
        *   @return The processor status encoded as byte
        */
        Byte
        asByte();

        /**
        *   @brief Convert a status byte to the bit representation
        * 
        *   @param status The new status
        */
        void
        fromByte(const Byte& status);

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