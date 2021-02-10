#include <Processor/ProcessorStatus.h>

using namespace E6502;

void 
ProcessorStatus::checkZero(const Byte& byte)
{
    Z = byte == 0;
}

void 
ProcessorStatus::checkCarry(const int16_t& word)
{
    C = (word & 0x100) >> 8;
}

void 
ProcessorStatus::checkOverflow(const Byte& inp1, const Byte& inp2)
{
    Byte result = inp1+inp2;
    if((inp1 & 0x80) == (inp2 & 0x80))
    {
        if((inp1 & 0x80) == (result & 0x80))
        {
            V = 0;
        }
        else
        {
            V = 1;
        }
    }
    else
    {
        V = 0;
    }
}

void 
ProcessorStatus::checkNegative(const Byte& byte)
{
    N = (byte & 0x80) >> 7;
}