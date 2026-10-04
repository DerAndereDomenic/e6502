#include <e6502/Instructions/JSR.h>
#include <iostream>

using namespace E6502_Instructions;

void JSR::apply(Word& PC,
                Byte& SP,
                Byte& A,
                Byte& X,
                Byte& Y,
                ProcessorStatus& processor_status,
                Memory& memory,
                AddressingModes& address_mode)
{
    Word address = memory(PC);

    // When this is called, PC is already advanced by 1 (PC - 1) is the op code of the current instruction. The next
    // instruction is at PC + 2. JSR stores PC - 1 (one address before the _next_ instruction). Therefore, in this
    // implementation, we have to store PC + 1
    Word stored_pc = PC + 1;

    memory[0x0100 + SP] = (Byte)((stored_pc) >> 8);
    --SP;
    memory[0x0100 + SP] = (Byte)((stored_pc) & 0x00FF);
    --SP;

    PC = address;
}