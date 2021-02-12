#include <Memory/Memory.h>

using namespace E6502;

Byte&
Memory::operator[](const Word& pointer)
{
    return RAM[pointer];
}

Word
Memory::operator()(const Word& pointer)
{
    Byte address0 = RAM[pointer];
    Byte address1 = RAM[pointer+1];

    Word address = (address1<<8) + address0;

    return address;
}