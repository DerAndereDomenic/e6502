#include <gtest/gtest.h>

#include <Processor/Processor.h>

using namespace E6502;

TEST(tax, tax)
{
    Memory memory;
    memory[STACK_START + 1] = TAX;
    Processor processor(memory);
    processor.A = 0x3F;

    processor.start();

    EXPECT_EQ(processor.X, 0x3F);
}

TEST(taxNegative, taxNegative)
{
    Memory memory;
    memory[STACK_START + 1] = TAX;
    Processor processor(memory);
    processor.A = 0xF1;

    processor.start();

    EXPECT_EQ(processor.X, 0xF1);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(taxZero, taxZero)
{
    Memory memory;
    memory[STACK_START + 1] = TAX;
    Processor processor(memory);
    processor.A = 0x00;

    processor.start();

    EXPECT_EQ(processor.X, 0x00);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(tay, tay)
{
    Memory memory;
    memory[STACK_START + 1] = TAY;
    Processor processor(memory);
    processor.A = 0x3F;

    processor.start();

    EXPECT_EQ(processor.Y, 0x3F);
}

TEST(tayNegative, tayNegative)
{
    Memory memory;
    memory[STACK_START + 1] = TAY;
    Processor processor(memory);
    processor.A = 0xF1;

    processor.start();

    EXPECT_EQ(processor.Y, 0xF1);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(tayZero, tayZero)
{
    Memory memory;
    memory[STACK_START + 1] = TAY;
    Processor processor(memory);
    processor.A = 0x00;

    processor.start();

    EXPECT_EQ(processor.Y, 0x00);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(txa, txa)
{
    Memory memory;
    memory[STACK_START + 1] = TXA;
    Processor processor(memory);
    processor.X = 0x3F;

    processor.start();

    EXPECT_EQ(processor.A, 0x3F);
}

TEST(txaNegative, txaNegative)
{
    Memory memory;
    memory[STACK_START + 1] = TXA;
    Processor processor(memory);
    processor.X = 0xF1;

    processor.start();

    EXPECT_EQ(processor.A, 0xF1);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(txaZero, txaZero)
{
    Memory memory;
    memory[STACK_START + 1] = TXA;
    Processor processor(memory);
    processor.X = 0x00;

    processor.start();

    EXPECT_EQ(processor.A, 0x00);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(tya, tya)
{
    Memory memory;
    memory[STACK_START + 1] = TYA;
    Processor processor(memory);
    processor.Y = 0x3F;

    processor.start();

    EXPECT_EQ(processor.A, 0x3F);
}

TEST(tyaNegative, tyaNegative)
{
    Memory memory;
    memory[STACK_START + 1] = TYA;
    Processor processor(memory);
    processor.Y = 0xF1;

    processor.start();

    EXPECT_EQ(processor.A, 0xF1);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(tyaZero, tyaZero)
{
    Memory memory;
    memory[STACK_START + 1] = TYA;
    Processor processor(memory);
    processor.Y = 0x00;

    processor.start();

    EXPECT_EQ(processor.A, 0x00);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(inx, inx)
{
    Memory memory;
    memory[STACK_START + 1] = INX;
    Processor processor(memory);
    processor.X = 0x4B;

    processor.start();

    EXPECT_EQ(processor.X, 0x4C);
}

TEST(inxNegative, inxNegative)
{
    Memory memory;
    memory[STACK_START + 1] = INX;
    Processor processor(memory);
    processor.X = 0xF1;

    processor.start();

    EXPECT_EQ(processor.X, 0xF2);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(inxZero, inxZero)
{
    Memory memory;
    memory[STACK_START + 1] = INX;
    Processor processor(memory);
    processor.X = 0xFF;

    processor.start();

    EXPECT_EQ(processor.X, 0x00);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(iny, iny)
{
    Memory memory;
    memory[STACK_START + 1] = INY;
    Processor processor(memory);
    processor.Y = 0x4B;

    processor.start();

    EXPECT_EQ(processor.Y, 0x4C);
}

TEST(inyNegative, inyNegative)
{
    Memory memory;
    memory[STACK_START + 1] = INY;
    Processor processor(memory);
    processor.Y = 0xF1;

    processor.start();

    EXPECT_EQ(processor.Y, 0xF2);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(inyZero, inyZero)
{
    Memory memory;
    memory[STACK_START + 1] = INY;
    Processor processor(memory);
    processor.Y = 0xFF;

    processor.start();

    EXPECT_EQ(processor.Y, 0x00);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(dex, dex)
{
    Memory memory;
    memory[STACK_START + 1] = DEX;
    Processor processor(memory);
    processor.X = 0x4B;

    processor.start();

    EXPECT_EQ(processor.X, 0x4A);
}

TEST(dexNegative, dexNegative)
{
    Memory memory;
    memory[STACK_START + 1] = DEX;
    Processor processor(memory);
    processor.X = 0xF1;

    processor.start();

    EXPECT_EQ(processor.X, 0xF0);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(dexZero, dexZero)
{
    Memory memory;
    memory[STACK_START + 1] = DEX;
    Processor processor(memory);
    processor.X = 0x01;

    processor.start();

    EXPECT_EQ(processor.X, 0x00);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(dey, dey)
{
    Memory memory;
    memory[STACK_START + 1] = DEY;
    Processor processor(memory);
    processor.Y = 0x4B;

    processor.start();

    EXPECT_EQ(processor.Y, 0x4A);
}

TEST(deyNegative, deyNegative)
{
    Memory memory;
    memory[STACK_START + 1] = DEY;
    Processor processor(memory);
    processor.Y = 0xF1;

    processor.start();

    EXPECT_EQ(processor.Y, 0xF0);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(deyZero, deyZero)
{
    Memory memory;
    memory[STACK_START + 1] = DEY;
    Processor processor(memory);
    processor.Y = 0x01;

    processor.start();

    EXPECT_EQ(processor.Y, 0x00);
    EXPECT_EQ(processor.processor_status.Z, 1);
}