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
    if(word >= 0 && word <= 255)
    {
        C = 0;
    }
    else
    {
        C = 1;
    }
}

void 
ProcessorStatus::checkOverflow(const int16_t& word)
{
    if(word >= -127 && word < 128)
    {
        V = 0;
    }
    else
    {
        V = 1;
    }
}

void 
ProcessorStatus::checkNegative(const Byte& byte)
{
    N = (byte & 0x80) >> 7;
}