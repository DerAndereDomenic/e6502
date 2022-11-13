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
ProcessorStatus::checkOverflow(const Byte& inp1, const Byte& inp2, const Byte& c)
{
    Byte result = inp1+inp2+c;
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

Byte
ProcessorStatus::asByte()
{
    Byte result = 0;

    result |= (N << 7);
    result |= (V << 6);
    result |= (Z_ << 5);
    result |= (B << 4);
    result |= (D << 3);
    result |= (I << 2);
    result |= (Z << 1);
    result |= (C << 0);

    result;
}

void
ProcessorStatus::fromByte(const Byte& status)
{
    N = (status >> 7) & 0x01;
    V = (status >> 6) & 0x01;
    Z_ = (status >> 5) & 0x01;
    B = (status >> 4) & 0x01;
    D = (status >> 3) & 0x01;
    I = (status >> 2) & 0x01;
    Z = (status >> 1) & 0x01;
    C = (status >> 0) & 0x01;
}