#include <Memory/Memory.h>

using namespace E6502;

Byte&
Memory::operator[](const Word& pointer)
{
    return RAM[pointer];
}