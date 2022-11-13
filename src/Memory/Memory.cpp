#include <Memory/Memory.h>
#include <iostream>

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

void
Memory::print()
{
    bool printed_zero = false;
    uint32_t num_zeros_rows = 0;
    for (Word addr = 0; addr < MEMORY_SIZE; ++addr)
    {
        Byte content = RAM[addr];

        if (content == 0)
        {
            ++num_zeros_rows;
            if (!printed_zero)
            {
                printf("0x%4.4x: 0x%2.2x\n", addr, content);
                printed_zero = true;
                
            }
            
            if (num_zeros_rows == 3)
            {
                printf("...\n");
            }
        }
        else
        {
            if (num_zeros_rows >= 3)
            {
                printf("0x%4.4x: 0x%2.2x\n", addr - 1, 0x00);
            }
            printf("0x%4.4x: 0x%2.2x\n", addr, content);
            printed_zero = false;
            num_zeros_rows = 0;
        }
    }

    printf("0x%4.4x: 0x%2.2x\n", MEMORY_SIZE, 0x00);
}