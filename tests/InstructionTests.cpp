#include <gtest/gtest.h>

#include <e6502/Processor/Processor.h>

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

TEST(ldaImmediate, ldaImmediate)
{
    Memory memory;
    memory[STACK_START + 1] = LDA_I;
    memory[STACK_START + 2] = 0xC1;
    Processor processor(memory);
    processor.start();

    EXPECT_EQ(processor.A, 0xC1);
}

TEST(ldaZeroPage, ldaZeroPage)
{
    Memory memory;
    memory[0x3F]            = 0x42;
    memory[STACK_START + 1] = LDA_Z;
    memory[STACK_START + 2] = 0x3F;
    Processor processor(memory);
    processor.start();

    EXPECT_EQ(processor.A, 0x42);
}

TEST(ldaZeroX, ldaZeroX)
{
    Memory memory;
    memory[STACK_START + 1] = LDA_ZX;
    memory[STACK_START + 2] = 0xC0;
    memory[0xC5]            = 0x52;
    Processor processor(memory);
    processor.X = 0x05;

    processor.start();

    EXPECT_EQ(processor.A, 0x52);
}

TEST(ldaZeroXWrap, ldaZeroXWrap)
{
    Memory memory;
    memory[STACK_START + 1] = LDA_ZX;
    memory[STACK_START + 2] = 0xC0;
    memory[0x20]            = 0x52;
    Processor processor(memory);
    processor.X = 0x60;

    processor.start();

    EXPECT_EQ(processor.A, 0x52);
}

TEST(ldaAbsolute, ldaAbsolute)
{
    Memory memory;
    memory[STACK_START + 1] = LDA_A;
    memory[STACK_START + 2] = 0x31;
    memory[STACK_START + 3] = 0xAC;
    memory[0xAC31]          = 0x7F;
    Processor processor(memory);

    processor.start();

    EXPECT_EQ(processor.A, 0x7F);
}

TEST(ldaAbsoluteX, ldaAbsoluteX)
{
    Memory memory;
    memory[STACK_START + 1] = LDA_AX;
    memory[STACK_START + 2] = 0x30;
    memory[STACK_START + 3] = 0xAC;
    memory[0xAC39]          = 0x7F;
    Processor processor(memory);
    processor.X = 0x09;

    processor.start();

    EXPECT_EQ(processor.A, 0x7F);
}

TEST(ldaAbsoluteY, ldaAbsoluteY)
{
    Memory memory;
    memory[STACK_START + 1] = LDA_AY;
    memory[STACK_START + 2] = 0x30;
    memory[STACK_START + 3] = 0xAC;
    memory[0xAC39]          = 0x7F;
    Processor processor(memory);
    processor.Y = 0x09;

    processor.start();

    EXPECT_EQ(processor.A, 0x7F);
}

TEST(ldaIndirectX, ldaIndirectX)
{
    Memory memory;
    memory[STACK_START + 1] = LDA_IX;
    memory[STACK_START + 2] = 0x20;
    memory[0x24]            = 0x74;
    memory[0x25]            = 0x20;
    memory[0x2074]          = 0x11;
    Processor processor(memory);
    processor.X = 0x04;

    processor.start();

    EXPECT_EQ(processor.A, 0x11);
}

TEST(ldaIndirectXWrap, ldaIndirectXWrap)
{
    Memory memory;
    memory[STACK_START + 1] = LDA_IX;
    memory[STACK_START + 2] = 0x20;
    memory[0x01]            = 0x74;
    memory[0x02]            = 0x20;
    memory[0x2074]          = 0x11;
    Processor processor(memory);
    processor.X = 0xE1;

    processor.start();

    EXPECT_EQ(processor.A, 0x11);
}

TEST(ldaIndirectY, ldaIndirectY)
{
    Memory memory;
    memory[STACK_START + 1] = LDA_IY;
    memory[STACK_START + 2] = 0x86;
    memory[0x86]            = 0x28;
    memory[0x87]            = 0x40;
    memory[0x4038]          = 0xF1;
    Processor processor(memory);
    processor.Y = 0x10;

    processor.start();

    EXPECT_EQ(processor.A, 0xF1);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(ldxImmediate, ldxImmediate)
{
    Memory memory;
    memory[STACK_START + 1] = LDX_I;
    memory[STACK_START + 2] = 0xC1;
    Processor processor(memory);
    processor.start();

    EXPECT_EQ(processor.X, 0xC1);
}

TEST(ldxZeroPage, ldxZeroPage)
{
    Memory memory;
    memory[0x3F]            = 0x42;
    memory[STACK_START + 1] = LDX_Z;
    memory[STACK_START + 2] = 0x3F;
    Processor processor(memory);
    processor.start();

    EXPECT_EQ(processor.X, 0x42);
}

TEST(ldxZeroY, ldxZeroY)
{
    Memory memory;
    memory[STACK_START + 1] = LDX_ZY;
    memory[STACK_START + 2] = 0xC0;
    memory[0xC5]            = 0x52;
    Processor processor(memory);
    processor.Y = 0x05;

    processor.start();

    EXPECT_EQ(processor.X, 0x52);
}

TEST(ldxZeroYWrap, ldxZeroYWrap)
{
    Memory memory;
    memory[STACK_START + 1] = LDX_ZY;
    memory[STACK_START + 2] = 0xC0;
    memory[0x20]            = 0x52;
    Processor processor(memory);
    processor.Y = 0x60;

    processor.start();

    EXPECT_EQ(processor.X, 0x52);
}

TEST(ldxAbsolute, ldxAbsolute)
{
    Memory memory;
    memory[STACK_START + 1] = LDX_A;
    memory[STACK_START + 2] = 0x31;
    memory[STACK_START + 3] = 0xAC;
    memory[0xAC31]          = 0x7F;
    Processor processor(memory);

    processor.start();

    EXPECT_EQ(processor.X, 0x7F);
}

TEST(ldxAbsoluteY, ldxAbsoluteY)
{
    Memory memory;
    memory[STACK_START + 1] = LDX_AY;
    memory[STACK_START + 2] = 0x30;
    memory[STACK_START + 3] = 0xAC;
    memory[0xAC39]          = 0x7F;
    Processor processor(memory);
    processor.Y = 0x09;

    processor.start();

    EXPECT_EQ(processor.X, 0x7F);
}

TEST(ldyImmediate, ldyImmediate)
{
    Memory memory;
    memory[STACK_START + 1] = LDY_I;
    memory[STACK_START + 2] = 0xC1;
    Processor processor(memory);
    processor.start();

    EXPECT_EQ(processor.Y, 0xC1);
}

TEST(ldyZeroPage, ldyZeroPage)
{
    Memory memory;
    memory[0x3F]            = 0x42;
    memory[STACK_START + 1] = LDY_Z;
    memory[STACK_START + 2] = 0x3F;
    Processor processor(memory);
    processor.start();

    EXPECT_EQ(processor.Y, 0x42);
}

TEST(ldyZeroY, ldyZeroY)
{
    Memory memory;
    memory[STACK_START + 1] = LDY_ZX;
    memory[STACK_START + 2] = 0xC0;
    memory[0xC5]            = 0x52;
    Processor processor(memory);
    processor.X = 0x05;

    processor.start();

    EXPECT_EQ(processor.Y, 0x52);
}

TEST(ldyZeroYWrap, ldyZeroYWrap)
{
    Memory memory;
    memory[STACK_START + 1] = LDY_ZX;
    memory[STACK_START + 2] = 0xC0;
    memory[0x20]            = 0x52;
    Processor processor(memory);
    processor.X = 0x60;

    processor.start();

    EXPECT_EQ(processor.Y, 0x52);
}

TEST(ldyAbsolute, ldyAbsolute)
{
    Memory memory;
    memory[STACK_START + 1] = LDY_A;
    memory[STACK_START + 2] = 0x31;
    memory[STACK_START + 3] = 0xAC;
    memory[0xAC31]          = 0x7F;
    Processor processor(memory);

    processor.start();

    EXPECT_EQ(processor.Y, 0x7F);
}

TEST(ldyAbsoluteY, ldyAbsoluteY)
{
    Memory memory;
    memory[STACK_START + 1] = LDY_AX;
    memory[STACK_START + 2] = 0x30;
    memory[STACK_START + 3] = 0xAC;
    memory[0xAC39]          = 0x7F;
    Processor processor(memory);
    processor.X = 0x09;

    processor.start();

    EXPECT_EQ(processor.Y, 0x7F);
}

TEST(adcImmediate, adcImmediate)
{
    Memory memory;
    memory[STACK_START + 1] = ADC_I;
    memory[STACK_START + 2] = 20;
    Processor processor(memory);
    processor.A = 42;

    processor.start();

    EXPECT_EQ(processor.A, 62);
}

TEST(adcImmediateZero, adcImmediateZero)
{
    Memory memory;
    memory[STACK_START + 1] = ADC_I;
    memory[STACK_START + 2] = 20;
    Processor processor(memory);
    processor.A = -20;

    processor.start();

    EXPECT_EQ(processor.A, 0);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(adcImmediateNegative, adcImmediateNegative)
{
    Memory memory;
    memory[STACK_START + 1] = ADC_I;
    memory[STACK_START + 2] = 20;
    Processor processor(memory);
    processor.A = -21;

    processor.start();

    EXPECT_EQ(processor.A, 0xFF);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(adcZeroPage, adcZeroPage)
{
    Memory memory;
    memory[0x3F]            = 20;
    memory[STACK_START + 1] = ADC_Z;
    memory[STACK_START + 2] = 0x3F;
    Processor processor(memory);
    processor.A = 42;

    processor.start();

    EXPECT_EQ(processor.A, 62);
}

TEST(adcZeroPageZero, adcZeroPageZero)
{
    Memory memory;
    memory[0x3F]            = 20;
    memory[STACK_START + 1] = ADC_Z;
    memory[STACK_START + 2] = 0x3F;
    Processor processor(memory);
    processor.A = -20;

    processor.start();

    EXPECT_EQ(processor.A, 0);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(adcZeroPageNegative, adcZeroPageNegative)
{
    Memory memory;
    memory[0x3F]            = 20;
    memory[STACK_START + 1] = ADC_Z;
    memory[STACK_START + 2] = 0x3F;
    Processor processor(memory);
    processor.A = -21;

    processor.start();

    EXPECT_EQ(processor.A, 0xFF);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(adcZeroPageX, adcZeroPageX)
{
    Memory memory;
    memory[0x3F]            = 20;
    memory[STACK_START + 1] = ADC_ZX;
    memory[STACK_START + 2] = 0x30;
    Processor processor(memory);
    processor.A = 42;
    processor.X = 0x0F;

    processor.start();

    EXPECT_EQ(processor.A, 62);
}

TEST(adcZeroPageZeroX, adcZeroPageZeroX)
{
    Memory memory;
    memory[0x3F]            = 20;
    memory[STACK_START + 1] = ADC_ZX;
    memory[STACK_START + 2] = 0x30;
    Processor processor(memory);
    processor.A = -20;
    processor.X = 0x0F;

    processor.start();

    EXPECT_EQ(processor.A, 0);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(adcZeroPageNegativeX, adcZeroPageNegativeX)
{
    Memory memory;
    memory[0x3F]            = 20;
    memory[STACK_START + 1] = ADC_ZX;
    memory[STACK_START + 2] = 0x30;
    Processor processor(memory);
    processor.A = -21;
    processor.X = 0x0F;

    processor.start();

    EXPECT_EQ(processor.A, 0xFF);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(adcAbsolute, adcAbsolute)
{
    Memory memory;
    memory[0x3330]          = 20;
    memory[STACK_START + 1] = ADC_A;
    memory[STACK_START + 2] = 0x30;
    memory[STACK_START + 3] = 0x33;
    Processor processor(memory);
    processor.A = 42;

    processor.start();

    EXPECT_EQ(processor.A, 62);
}

TEST(adcAbsoluteZero, adcAbsoluteZero)
{
    Memory memory;
    memory[0x3330]          = 20;
    memory[STACK_START + 1] = ADC_A;
    memory[STACK_START + 2] = 0x30;
    memory[STACK_START + 3] = 0x33;
    Processor processor(memory);
    processor.A = -20;

    processor.start();

    EXPECT_EQ(processor.A, 0);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(adcAbsoluteNegative, adcAbsoluteNegative)
{
    Memory memory;
    memory[0x3330]          = 20;
    memory[STACK_START + 1] = ADC_A;
    memory[STACK_START + 2] = 0x30;
    memory[STACK_START + 3] = 0x33;
    Processor processor(memory);
    processor.A = -21;

    processor.start();

    EXPECT_EQ(processor.A, 0xFF);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(adcAbsoluteX, adcAbsoluteX)
{
    Memory memory;
    memory[0x3334]          = 20;
    memory[STACK_START + 1] = ADC_AX;
    memory[STACK_START + 2] = 0x30;
    memory[STACK_START + 3] = 0x33;
    Processor processor(memory);
    processor.A = 42;
    processor.X = 0x04;

    processor.start();

    EXPECT_EQ(processor.A, 62);
}

TEST(adcAbsoluteXZero, adcAbsoluteXZero)
{
    Memory memory;
    memory[0x3334]          = 20;
    memory[STACK_START + 1] = ADC_AX;
    memory[STACK_START + 2] = 0x30;
    memory[STACK_START + 3] = 0x33;
    Processor processor(memory);
    processor.A = -20;
    processor.X = 0x04;

    processor.start();

    EXPECT_EQ(processor.A, 0);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(adcAbsoluteXNegative, adcAbsoluteXNegative)
{
    Memory memory;
    memory[0x3334]          = 20;
    memory[STACK_START + 1] = ADC_AX;
    memory[STACK_START + 2] = 0x30;
    memory[STACK_START + 3] = 0x33;
    Processor processor(memory);
    processor.A = -21;
    processor.X = 0x04;

    processor.start();

    EXPECT_EQ(processor.A, 0xFF);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(adcAbsoluteY, adcAbsoluteY)
{
    Memory memory;
    memory[0x3334]          = 20;
    memory[STACK_START + 1] = ADC_AY;
    memory[STACK_START + 2] = 0x30;
    memory[STACK_START + 3] = 0x33;
    Processor processor(memory);
    processor.A = 42;
    processor.Y = 0x04;

    processor.start();

    EXPECT_EQ(processor.A, 62);
}

TEST(adcAbsoluteYZero, adcAbsoluteYZero)
{
    Memory memory;
    memory[0x3334]          = 20;
    memory[STACK_START + 1] = ADC_AY;
    memory[STACK_START + 2] = 0x30;
    memory[STACK_START + 3] = 0x33;
    Processor processor(memory);
    processor.A = -20;
    processor.Y = 0x04;

    processor.start();

    EXPECT_EQ(processor.A, 0);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(adcAbsoluteYNegative, adcAbsoluteYNegative)
{
    Memory memory;
    memory[0x3334]          = 20;
    memory[STACK_START + 1] = ADC_AY;
    memory[STACK_START + 2] = 0x30;
    memory[STACK_START + 3] = 0x33;
    Processor processor(memory);
    processor.A = -21;
    processor.Y = 0x04;

    processor.start();

    EXPECT_EQ(processor.A, 0xFF);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(adcIndirectX, adcIndirectX)
{
    Memory memory;
    memory[STACK_START + 1] = ADC_IX;
    memory[STACK_START + 2] = 0x20;
    memory[0x24]            = 0x74;
    memory[0x25]            = 0x20;
    memory[0x2074]          = 20;
    Processor processor(memory);
    processor.A = 42;
    processor.X = 0x04;

    processor.start();

    EXPECT_EQ(processor.A, 62);
}

TEST(adcIndirectXWrap, adcIndirectXWrap)
{
    Memory memory;
    memory[STACK_START + 1] = ADC_IX;
    memory[STACK_START + 2] = 0x20;
    memory[0x01]            = 0x74;
    memory[0x02]            = 0x20;
    memory[0x2074]          = 20;
    Processor processor(memory);
    processor.A = 42;
    processor.X = 0xE1;

    processor.start();

    EXPECT_EQ(processor.A, 62);
}

TEST(adcIndirectXZero, adcIndirectXZero)
{
    Memory memory;
    memory[STACK_START + 1] = ADC_IX;
    memory[STACK_START + 2] = 0x20;
    memory[0x24]            = 0x74;
    memory[0x25]            = 0x20;
    memory[0x2074]          = 20;
    Processor processor(memory);
    processor.A = -20;
    processor.X = 0x04;

    processor.start();

    EXPECT_EQ(processor.A, 0);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(adcIndirectXNegative, adcIndirectXNegative)
{
    Memory memory;
    memory[STACK_START + 1] = ADC_IX;
    memory[STACK_START + 2] = 0x20;
    memory[0x24]            = 0x74;
    memory[0x25]            = 0x20;
    memory[0x2074]          = 20;
    Processor processor(memory);
    processor.A = -21;
    processor.X = 0x04;

    processor.start();

    EXPECT_EQ(processor.A, 0xFF);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(adcIndirectY, adcIndirectY)
{
    Memory memory;
    memory[STACK_START + 1] = ADC_IY;
    memory[STACK_START + 2] = 0x86;
    memory[0x86]            = 0x28;
    memory[0x87]            = 0x40;
    memory[0x4038]          = 20;
    Processor processor(memory);
    processor.A = 42;
    processor.Y = 0x10;

    processor.start();

    EXPECT_EQ(processor.A, 62);
}

TEST(adcIndirectYZero, adcIndirectYZero)
{
    Memory memory;
    memory[STACK_START + 1] = ADC_IY;
    memory[STACK_START + 2] = 0x86;
    memory[0x86]            = 0x28;
    memory[0x87]            = 0x40;
    memory[0x4038]          = 20;
    Processor processor(memory);
    processor.A = -20;
    processor.Y = 0x10;

    processor.start();

    EXPECT_EQ(processor.A, 0);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(adcIndirectYNegative, adcIndirectYNegative)
{
    Memory memory;
    memory[STACK_START + 1] = ADC_IY;
    memory[STACK_START + 2] = 0x86;
    memory[0x86]            = 0x28;
    memory[0x87]            = 0x40;
    memory[0x4038]          = 20;
    Processor processor(memory);
    processor.A = -21;
    processor.Y = 0x10;

    processor.start();

    EXPECT_EQ(processor.A, 0xFF);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(andImmediate, andImmediate)
{
    Memory memory;
    memory[STACK_START + 1] = AND_I;
    memory[STACK_START + 2] = 0x0F;
    Processor processor(memory);
    processor.A = 0xF0;
    processor.start();
    EXPECT_EQ(processor.A, 0x00);
}

TEST(andZeroPage, andZeroPage)
{
    Memory memory;
    memory[STACK_START + 1] = AND_Z;
    memory[STACK_START + 2] = 0x40;
    memory[0x40]            = 0x0F;
    Processor processor(memory);
    processor.A = 0xF0;
    processor.start();
    EXPECT_EQ(processor.A, 0x00);
}

TEST(andZeroX, andZeroX)
{
    Memory memory;
    memory[STACK_START + 1] = AND_ZX;
    memory[STACK_START + 2] = 0x40;
    memory[0x42]            = 0x0F;
    Processor processor(memory);
    processor.A = 0xF0;
    processor.X = 0x02;
    processor.start();
    EXPECT_EQ(processor.A, 0x00);
}

TEST(andAbsolute, andAbsolute)
{
    Memory memory;
    memory[STACK_START + 1] = AND_A;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    memory[0x2040]          = 0x0F;
    Processor processor(memory);
    processor.A = 0xF0;
    processor.start();
    EXPECT_EQ(processor.A, 0x00);
}

TEST(andAbsoluteX, andAbsoluteX)
{
    Memory memory;
    memory[STACK_START + 1] = AND_AX;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    memory[0x2042]          = 0x0F;
    Processor processor(memory);
    processor.A = 0xF0;
    processor.X = 0x02;
    processor.start();
    EXPECT_EQ(processor.A, 0x00);
}

TEST(andAbsoluteY, andAbsoluteY)
{
    Memory memory;
    memory[STACK_START + 1] = AND_AY;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    memory[0x2042]          = 0x0F;
    Processor processor(memory);
    processor.A = 0xF0;
    processor.Y = 0x02;
    processor.start();
    EXPECT_EQ(processor.A, 0x00);
}

TEST(andIndirectX, andIndirectX)
{
    Memory memory;
    memory[STACK_START + 1] = AND_IX;
    memory[STACK_START + 2] = 0x40;
    memory[0x42]            = 0x40;
    memory[0x43]            = 0x20;
    memory[0x2040]          = 0x0F;
    Processor processor(memory);
    processor.A = 0xF0;
    processor.X = 0x02;
    processor.start();
    EXPECT_EQ(processor.A, 0x00);
}

TEST(andIndirectY, andIndirectY)
{
    Memory memory;
    memory[STACK_START + 1] = AND_IY;
    memory[STACK_START + 2] = 0x40;
    memory[0x40]            = 0x40;
    memory[0x41]            = 0x20;
    memory[0x2042]          = 0x0F;
    Processor processor(memory);
    processor.A = 0xF0;
    processor.Y = 0x02;
    processor.start();
    EXPECT_EQ(processor.A, 0x00);
}

TEST(andNegative, andNegative)
{
    Memory memory;
    memory[STACK_START + 1] = AND_I;
    memory[STACK_START + 2] = 0x80;
    Processor processor(memory);
    processor.A = 0xFF;
    processor.start();
    EXPECT_EQ(processor.A, 0x80);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(andZero, andZero)
{
    Memory memory;
    memory[STACK_START + 1] = AND_I;
    memory[STACK_START + 2] = 0x00;
    Processor processor(memory);
    processor.A = 0xFF;
    processor.start();
    EXPECT_EQ(processor.A, 0x00);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(eorImmediate, eorImmediate)
{
    Memory memory;
    memory[STACK_START + 1] = EOR_I;
    memory[STACK_START + 2] = 0x0F;
    Processor processor(memory);
    processor.A = 0xF0;
    processor.start();
    EXPECT_EQ(processor.A, 0xFF);
}

TEST(eorZeroPage, eorZeroPage)
{
    Memory memory;
    memory[STACK_START + 1] = EOR_Z;
    memory[STACK_START + 2] = 0x40;
    memory[0x40]            = 0x0F;
    Processor processor(memory);
    processor.A = 0xF0;
    processor.start();
    EXPECT_EQ(processor.A, 0xFF);
}

TEST(eorZeroX, eorZeroX)
{
    Memory memory;
    memory[STACK_START + 1] = EOR_ZX;
    memory[STACK_START + 2] = 0x40;
    memory[0x42]            = 0x0F;
    Processor processor(memory);
    processor.A = 0xF0;
    processor.X = 0x02;
    processor.start();
    EXPECT_EQ(processor.A, 0xFF);
}

TEST(eorAbsolute, eorAbsolute)
{
    Memory memory;
    memory[STACK_START + 1] = EOR_A;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    memory[0x2040]          = 0x0F;
    Processor processor(memory);
    processor.A = 0xF0;
    processor.start();
    EXPECT_EQ(processor.A, 0xFF);
}

TEST(eorAbsoluteX, eorAbsoluteX)
{
    Memory memory;
    memory[STACK_START + 1] = EOR_AX;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    memory[0x2042]          = 0x0F;
    Processor processor(memory);
    processor.A = 0xF0;
    processor.X = 0x02;
    processor.start();
    EXPECT_EQ(processor.A, 0xFF);
}

TEST(eorAbsoluteY, eorAbsoluteY)
{
    Memory memory;
    memory[STACK_START + 1] = EOR_AY;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    memory[0x2042]          = 0x0F;
    Processor processor(memory);
    processor.A = 0xF0;
    processor.Y = 0x02;
    processor.start();
    EXPECT_EQ(processor.A, 0xFF);
}

TEST(eorIndirectX, eorIndirectX)
{
    Memory memory;
    memory[STACK_START + 1] = EOR_IX;
    memory[STACK_START + 2] = 0x40;
    memory[0x42]            = 0x40;
    memory[0x43]            = 0x20;
    memory[0x2040]          = 0x0F;
    Processor processor(memory);
    processor.A = 0xF0;
    processor.X = 0x02;
    processor.start();
    EXPECT_EQ(processor.A, 0xFF);
}

TEST(eorIndirectY, eorIndirectY)
{
    Memory memory;
    memory[STACK_START + 1] = EOR_IY;
    memory[STACK_START + 2] = 0x40;
    memory[0x40]            = 0x40;
    memory[0x41]            = 0x20;
    memory[0x2042]          = 0x0F;
    Processor processor(memory);
    processor.A = 0xF0;
    processor.Y = 0x02;
    processor.start();
    EXPECT_EQ(processor.A, 0xFF);
}

TEST(eorZero, eorZero)
{
    Memory memory;
    memory[STACK_START + 1] = EOR_I;
    memory[STACK_START + 2] = 0xFF;
    Processor processor(memory);
    processor.A = 0xFF;
    processor.start();
    EXPECT_EQ(processor.A, 0x00);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(oraImmediate, oraImmediate)
{
    Memory memory;
    memory[STACK_START + 1] = ORA_I;
    memory[STACK_START + 2] = 0x0F;
    Processor processor(memory);
    processor.A = 0xF0;
    processor.start();
    EXPECT_EQ(processor.A, 0xFF);
}

TEST(oraZeroPage, oraZeroPage)
{
    Memory memory;
    memory[STACK_START + 1] = ORA_Z;
    memory[STACK_START + 2] = 0x40;
    memory[0x40]            = 0x0F;
    Processor processor(memory);
    processor.A = 0xF0;
    processor.start();
    EXPECT_EQ(processor.A, 0xFF);
}

TEST(oraZeroX, oraZeroX)
{
    Memory memory;
    memory[STACK_START + 1] = ORA_ZX;
    memory[STACK_START + 2] = 0x40;
    memory[0x42]            = 0x0F;
    Processor processor(memory);
    processor.A = 0xF0;
    processor.X = 0x02;
    processor.start();
    EXPECT_EQ(processor.A, 0xFF);
}

TEST(oraAbsolute, oraAbsolute)
{
    Memory memory;
    memory[STACK_START + 1] = ORA_A;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    memory[0x2040]          = 0x0F;
    Processor processor(memory);
    processor.A = 0xF0;
    processor.start();
    EXPECT_EQ(processor.A, 0xFF);
}

TEST(oraAbsoluteX, oraAbsoluteX)
{
    Memory memory;
    memory[STACK_START + 1] = ORA_AX;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    memory[0x2042]          = 0x0F;
    Processor processor(memory);
    processor.A = 0xF0;
    processor.X = 0x02;
    processor.start();
    EXPECT_EQ(processor.A, 0xFF);
}

TEST(oraAbsoluteY, oraAbsoluteY)
{
    Memory memory;
    memory[STACK_START + 1] = ORA_AY;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    memory[0x2042]          = 0x0F;
    Processor processor(memory);
    processor.A = 0xF0;
    processor.Y = 0x02;
    processor.start();
    EXPECT_EQ(processor.A, 0xFF);
}

TEST(oraIndirectX, oraIndirectX)
{
    Memory memory;
    memory[STACK_START + 1] = ORA_IX;
    memory[STACK_START + 2] = 0x40;
    memory[0x42]            = 0x40;
    memory[0x43]            = 0x20;
    memory[0x2040]          = 0x0F;
    Processor processor(memory);
    processor.A = 0xF0;
    processor.X = 0x02;
    processor.start();
    EXPECT_EQ(processor.A, 0xFF);
}

TEST(oraIndirectY, oraIndirectY)
{
    Memory memory;
    memory[STACK_START + 1] = ORA_IY;
    memory[STACK_START + 2] = 0x40;
    memory[0x40]            = 0x40;
    memory[0x41]            = 0x20;
    memory[0x2042]          = 0x0F;
    Processor processor(memory);
    processor.A = 0xF0;
    processor.Y = 0x02;
    processor.start();
    EXPECT_EQ(processor.A, 0xFF);
}

TEST(oraNegative, oraNegative)
{
    Memory memory;
    memory[STACK_START + 1] = ORA_I;
    memory[STACK_START + 2] = 0x80;
    Processor processor(memory);
    processor.A = 0x00;
    processor.start();
    EXPECT_EQ(processor.A, 0x80);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(staZeroPage, staZeroPage)
{
    Memory memory;
    memory[STACK_START + 1] = STA_Z;
    memory[STACK_START + 2] = 0x40;
    Processor processor(memory);
    processor.A = 0xA5;
    processor.start();
    EXPECT_EQ(processor.memory[0x40], 0xA5);
}

TEST(staZeroX, staZeroX)
{
    Memory memory;
    memory[STACK_START + 1] = STA_ZX;
    memory[STACK_START + 2] = 0x40;
    Processor processor(memory);
    processor.A = 0xA5;
    processor.X = 0x02;
    processor.start();
    EXPECT_EQ(processor.memory[0x42], 0xA5);
}

TEST(staAbsolute, staAbsolute)
{
    Memory memory;
    memory[STACK_START + 1] = STA_A;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    Processor processor(memory);
    processor.A = 0xA5;
    processor.start();
    EXPECT_EQ(processor.memory[0x2040], 0xA5);
}

TEST(staAbsoluteX, staAbsoluteX)
{
    Memory memory;
    memory[STACK_START + 1] = STA_AX;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    Processor processor(memory);
    processor.A = 0xA5;
    processor.X = 0x02;
    processor.start();
    EXPECT_EQ(processor.memory[0x2042], 0xA5);
}

TEST(staAbsoluteY, staAbsoluteY)
{
    Memory memory;
    memory[STACK_START + 1] = STA_AY;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    Processor processor(memory);
    processor.A = 0xA5;
    processor.Y = 0x02;
    processor.start();
    EXPECT_EQ(processor.memory[0x2042], 0xA5);
}

TEST(staIndirectX, staIndirectX)
{
    Memory memory;
    memory[STACK_START + 1] = STA_IX;
    memory[STACK_START + 2] = 0x40;
    memory[0x42]            = 0x40;
    memory[0x43]            = 0x20;
    Processor processor(memory);
    processor.A = 0xA5;
    processor.X = 0x02;
    processor.start();
    EXPECT_EQ(processor.memory[0x2040], 0xA5);
}

TEST(staIndirectY, staIndirectY)
{
    Memory memory;
    memory[STACK_START + 1] = STA_IY;
    memory[STACK_START + 2] = 0x40;
    memory[0x40]            = 0x40;
    memory[0x41]            = 0x20;
    Processor processor(memory);
    processor.A = 0xA5;
    processor.Y = 0x02;
    processor.start();
    EXPECT_EQ(processor.memory[0x2042], 0xA5);
}

TEST(stxZeroPage, stxZeroPage)
{
    Memory memory;
    memory[STACK_START + 1] = STX_Z;
    memory[STACK_START + 2] = 0x40;
    Processor processor(memory);
    processor.X = 0xA5;
    processor.start();
    EXPECT_EQ(processor.memory[0x40], 0xA5);
}

TEST(stxZeroY, stxZeroY)
{
    Memory memory;
    memory[STACK_START + 1] = STX_ZY;
    memory[STACK_START + 2] = 0x40;
    Processor processor(memory);
    processor.X = 0xA5;
    processor.Y = 0x02;
    processor.start();
    EXPECT_EQ(processor.memory[0x42], 0xA5);
}

TEST(stxAbsolute, stxAbsolute)
{
    Memory memory;
    memory[STACK_START + 1] = STX_A;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    Processor processor(memory);
    processor.X = 0xA5;
    processor.start();
    EXPECT_EQ(processor.memory[0x2040], 0xA5);
}

TEST(styZeroPage, styZeroPage)
{
    Memory memory;
    memory[STACK_START + 1] = STY_Z;
    memory[STACK_START + 2] = 0x40;
    Processor processor(memory);
    processor.Y = 0xA5;
    processor.start();
    EXPECT_EQ(processor.memory[0x40], 0xA5);
}

TEST(styZeroX, styZeroX)
{
    Memory memory;
    memory[STACK_START + 1] = STY_ZX;
    memory[STACK_START + 2] = 0x40;
    Processor processor(memory);
    processor.X = 0x02;
    processor.Y = 0xA5;
    processor.start();
    EXPECT_EQ(processor.memory[0x42], 0xA5);
}

TEST(styAbsolute, styAbsolute)
{
    Memory memory;
    memory[STACK_START + 1] = STY_A;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    Processor processor(memory);
    processor.Y = 0xA5;
    processor.start();
    EXPECT_EQ(processor.memory[0x2040], 0xA5);
}

TEST(decZeroPage, decZeroPage)
{
    Memory memory;
    memory[STACK_START + 1] = DEC_Z;
    memory[STACK_START + 2] = 0x40;
    memory[0x40]            = 0x01;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.memory[0x40], 0x00);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(decZeroX, decZeroX)
{
    Memory memory;
    memory[STACK_START + 1] = DEC_ZX;
    memory[STACK_START + 2] = 0x40;
    Processor processor(memory);
    processor.X            = 0x02;
    processor.memory[0x42] = 0x00;
    processor.start();
    EXPECT_EQ(processor.memory[0x42], 0xFF);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(decAbsolute, decAbsolute)
{
    Memory memory;
    memory[STACK_START + 1] = DEC_A;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    memory[0x2040]          = 0x10;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.memory[0x2040], 0x0F);
}

TEST(decAbsoluteX, decAbsoluteX)
{
    Memory memory;
    memory[STACK_START + 1] = DEC_AX;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    Processor processor(memory);
    processor.X              = 0x02;
    processor.memory[0x2042] = 0x10;
    processor.start();
    EXPECT_EQ(processor.memory[0x2042], 0x0F);
}

TEST(incZeroPage, incZeroPage)
{
    Memory memory;
    memory[STACK_START + 1] = INC_Z;
    memory[STACK_START + 2] = 0x40;
    memory[0x40]            = 0xFF;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.memory[0x40], 0x00);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(incZeroX, incZeroX)
{
    Memory memory;
    memory[STACK_START + 1] = INC_ZX;
    memory[STACK_START + 2] = 0x40;
    Processor processor(memory);
    processor.X            = 0x02;
    processor.memory[0x42] = 0x7F;
    processor.start();
    EXPECT_EQ(processor.memory[0x42], 0x80);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(incAbsolute, incAbsolute)
{
    Memory memory;
    memory[STACK_START + 1] = INC_A;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    memory[0x2040]          = 0x10;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.memory[0x2040], 0x11);
}

TEST(incAbsoluteX, incAbsoluteX)
{
    Memory memory;
    memory[STACK_START + 1] = INC_AX;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    Processor processor(memory);
    processor.X              = 0x02;
    processor.memory[0x2042] = 0x10;
    processor.start();
    EXPECT_EQ(processor.memory[0x2042], 0x11);
}

TEST(aslAccumulator, aslAccumulator)
{
    Memory memory;
    memory[STACK_START + 1] = ASL_AC;
    Processor processor(memory);
    processor.A = 0x81;
    processor.start();
    EXPECT_EQ(processor.A, 0x02);
    EXPECT_EQ(processor.processor_status.C, 1);
}

TEST(aslZeroPage, aslZeroPage)
{
    Memory memory;
    memory[STACK_START + 1] = ASL_Z;
    memory[STACK_START + 2] = 0x40;
    memory[0x40]            = 0x40;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.memory[0x40], 0x80);
}

TEST(aslZeroX, aslZeroX)
{
    Memory memory;
    memory[STACK_START + 1] = ASL_ZX;
    memory[STACK_START + 2] = 0x40;
    Processor processor(memory);
    processor.X            = 0x02;
    processor.memory[0x42] = 0x01;
    processor.start();
    EXPECT_EQ(processor.memory[0x42], 0x02);
}

TEST(aslAbsolute, aslAbsolute)
{
    Memory memory;
    memory[STACK_START + 1] = ASL_A;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    memory[0x2040]          = 0x7F;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.memory[0x2040], 0xFE);
}

TEST(aslAbsoluteX, aslAbsoluteX)
{
    Memory memory;
    memory[STACK_START + 1] = ASL_AX;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    Processor processor(memory);
    processor.X              = 0x02;
    processor.memory[0x2042] = 0x00;
    processor.start();
    EXPECT_EQ(processor.memory[0x2042], 0x00);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(lsrAccumulator, lsrAccumulator)
{
    Memory memory;
    memory[STACK_START + 1] = LSR_AC;
    Processor processor(memory);
    processor.A = 0x03;
    processor.start();
    EXPECT_EQ(processor.A, 0x01);
    EXPECT_EQ(processor.processor_status.C, 1);
}

TEST(lsrZeroPage, lsrZeroPage)
{
    Memory memory;
    memory[STACK_START + 1] = LSR_Z;
    memory[STACK_START + 2] = 0x40;
    memory[0x40]            = 0x80;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.memory[0x40], 0x40);
}

TEST(lsrZeroX, lsrZeroX)
{
    Memory memory;
    memory[STACK_START + 1] = LSR_ZX;
    memory[STACK_START + 2] = 0x40;
    Processor processor(memory);
    processor.X            = 0x02;
    processor.memory[0x42] = 0x02;
    processor.start();
    EXPECT_EQ(processor.memory[0x42], 0x01);
}

TEST(lsrAbsolute, lsrAbsolute)
{
    Memory memory;
    memory[STACK_START + 1] = LSR_A;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    memory[0x2040]          = 0x01;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.memory[0x2040], 0x00);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(lsrAbsoluteX, lsrAbsoluteX)
{
    Memory memory;
    memory[STACK_START + 1] = LSR_AX;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    Processor processor(memory);
    processor.X              = 0x02;
    processor.memory[0x2042] = 0xFF;
    processor.start();
    EXPECT_EQ(processor.memory[0x2042], 0x7F);
}

TEST(rolAccumulator, rolAccumulator)
{
    Memory memory;
    memory[STACK_START + 1] = ROL_AC;
    Processor processor(memory);
    processor.A = 0x80;
    processor.start();
    EXPECT_EQ(processor.A, 0x00);
    EXPECT_EQ(processor.processor_status.C, 1);
}

TEST(rolZeroPage, rolZeroPage)
{
    Memory memory;
    memory[STACK_START + 1] = ROL_Z;
    memory[STACK_START + 2] = 0x40;
    memory[0x40]            = 0x01;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.memory[0x40], 0x02);
}

TEST(rolZeroX, rolZeroX)
{
    Memory memory;
    memory[STACK_START + 1] = ROL_ZX;
    memory[STACK_START + 2] = 0x40;
    Processor processor(memory);
    processor.X            = 0x02;
    processor.memory[0x42] = 0x80;
    processor.start();
    EXPECT_EQ(processor.memory[0x42], 0x00);
}

TEST(rolAbsolute, rolAbsolute)
{
    Memory memory;
    memory[STACK_START + 1] = ROL_A;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    memory[0x2040]          = 0x00;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.memory[0x2040], 0x00);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(rolAbsoluteX, rolAbsoluteX)
{
    Memory memory;
    memory[STACK_START + 1] = ROL_AX;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    Processor processor(memory);
    processor.X              = 0x02;
    processor.memory[0x2042] = 0x7F;
    processor.start();
    EXPECT_EQ(processor.memory[0x2042], 0xFE);
}

TEST(rorAccumulator, rorAccumulator)
{
    Memory memory;
    memory[STACK_START + 1] = ROR_AC;
    Processor processor(memory);
    processor.A = 0x01;
    processor.start();
    EXPECT_EQ(processor.A, 0x00);
    EXPECT_EQ(processor.processor_status.C, 1);
}

TEST(rorZeroPage, rorZeroPage)
{
    Memory memory;
    memory[STACK_START + 1] = ROR_Z;
    memory[STACK_START + 2] = 0x40;
    memory[0x40]            = 0x80;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.memory[0x40], 0x40);
}

TEST(rorZeroX, rorZeroX)
{
    Memory memory;
    memory[STACK_START + 1] = ROR_ZX;
    memory[STACK_START + 2] = 0x40;
    Processor processor(memory);
    processor.X            = 0x02;
    processor.memory[0x42] = 0x00;
    processor.start();
    EXPECT_EQ(processor.memory[0x42], 0x00);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(rorAbsolute, rorAbsolute)
{
    Memory memory;
    memory[STACK_START + 1] = ROR_A;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    memory[0x2040]          = 0x03;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.memory[0x2040], 0x01);
}

TEST(rorAbsoluteX, rorAbsoluteX)
{
    Memory memory;
    memory[STACK_START + 1] = ROR_AX;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    Processor processor(memory);
    processor.X              = 0x02;
    processor.memory[0x2042] = 0x02;
    processor.start();
    EXPECT_EQ(processor.memory[0x2042], 0x01);
}

TEST(sbcImmediate, sbcImmediate)
{
    Memory memory;
    memory[STACK_START + 1] = SBC_I;
    memory[STACK_START + 2] = 0x14;
    Processor processor(memory);
    processor.A                  = 0x2A;
    processor.processor_status.C = 1;
    processor.start();
    EXPECT_EQ(processor.A, 0x16);
}

TEST(sbcZeroPage, sbcZeroPage)
{
    Memory memory;
    memory[STACK_START + 1] = SBC_Z;
    memory[STACK_START + 2] = 0x40;
    memory[0x40]            = 0x14;
    Processor processor(memory);
    processor.A                  = 0x2A;
    processor.processor_status.C = 1;
    processor.start();
    EXPECT_EQ(processor.A, 0x16);
}

TEST(sbcZeroX, sbcZeroX)
{
    Memory memory;
    memory[STACK_START + 1] = SBC_ZX;
    memory[STACK_START + 2] = 0x40;
    Processor processor(memory);
    processor.X                  = 0x02;
    processor.A                  = 0x2A;
    processor.processor_status.C = 1;
    processor.memory[0x42]       = 0x14;
    processor.start();
    EXPECT_EQ(processor.A, 0x16);
}

TEST(sbcAbsolute, sbcAbsolute)
{
    Memory memory;
    memory[STACK_START + 1] = SBC_A;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    memory[0x2040]          = 0x14;
    Processor processor(memory);
    processor.A                  = 0x2A;
    processor.processor_status.C = 1;
    processor.start();
    EXPECT_EQ(processor.A, 0x16);
}

TEST(sbcAbsoluteX, sbcAbsoluteX)
{
    Memory memory;
    memory[STACK_START + 1] = SBC_AX;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    Processor processor(memory);
    processor.X                  = 0x02;
    processor.A                  = 0x2A;
    processor.processor_status.C = 1;
    processor.memory[0x2042]     = 0x14;
    processor.start();
    EXPECT_EQ(processor.A, 0x16);
}

TEST(sbcAbsoluteY, sbcAbsoluteY)
{
    Memory memory;
    memory[STACK_START + 1] = SBC_AY;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    Processor processor(memory);
    processor.Y                  = 0x02;
    processor.A                  = 0x2A;
    processor.processor_status.C = 1;
    processor.memory[0x2042]     = 0x14;
    processor.start();
    EXPECT_EQ(processor.A, 0x16);
}

TEST(sbcIndirectX, sbcIndirectX)
{
    Memory memory;
    memory[STACK_START + 1] = SBC_IX;
    memory[STACK_START + 2] = 0x40;
    memory[0x42]            = 0x40;
    memory[0x43]            = 0x20;
    memory[0x2040]          = 0x14;
    Processor processor(memory);
    processor.X                  = 0x02;
    processor.A                  = 0x2A;
    processor.processor_status.C = 1;
    processor.start();
    EXPECT_EQ(processor.A, 0x16);
}

TEST(sbcIndirectY, sbcIndirectY)
{
    Memory memory;
    memory[STACK_START + 1] = SBC_IY;
    memory[STACK_START + 2] = 0x40;
    memory[0x40]            = 0x40;
    memory[0x41]            = 0x20;
    memory[0x2042]          = 0x14;
    Processor processor(memory);
    processor.Y                  = 0x02;
    processor.A                  = 0x2A;
    processor.processor_status.C = 1;
    processor.start();
    EXPECT_EQ(processor.A, 0x16);
}

TEST(sbcNegative, sbcNegative)
{
    Memory memory;
    memory[STACK_START + 1] = SBC_I;
    memory[STACK_START + 2] = 0x01;
    Processor processor(memory);
    processor.A = 0x00;
    processor.start();
    EXPECT_EQ(processor.A, 0xFE);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(cmpImmediate, cmpImmediate)
{
    Memory memory;
    memory[STACK_START + 1] = CMP_I;
    memory[STACK_START + 2] = 0x14;
    Processor processor(memory);
    processor.A = 0x20;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 1);
    EXPECT_EQ(processor.processor_status.Z, 0);
}

TEST(cmpZeroPage, cmpZeroPage)
{
    Memory memory;
    memory[STACK_START + 1] = CMP_Z;
    memory[STACK_START + 2] = 0x40;
    memory[0x40]            = 0x14;
    Processor processor(memory);
    processor.A = 0x20;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 1);
}

TEST(cmpZeroX, cmpZeroX)
{
    Memory memory;
    memory[STACK_START + 1] = CMP_ZX;
    memory[STACK_START + 2] = 0x40;
    Processor processor(memory);
    processor.X            = 0x02;
    processor.A            = 0x10;
    processor.memory[0x42] = 0x20;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 0);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(cmpAbsolute, cmpAbsolute)
{
    Memory memory;
    memory[STACK_START + 1] = CMP_A;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    memory[0x2040]          = 0x14;
    Processor processor(memory);
    processor.A = 0x20;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 1);
}

TEST(cmpAbsoluteX, cmpAbsoluteX)
{
    Memory memory;
    memory[STACK_START + 1] = CMP_AX;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    Processor processor(memory);
    processor.X              = 0x02;
    processor.A              = 0x20;
    processor.memory[0x2042] = 0x14;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 1);
}

TEST(cmpAbsoluteY, cmpAbsoluteY)
{
    Memory memory;
    memory[STACK_START + 1] = CMP_AY;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    Processor processor(memory);
    processor.Y              = 0x02;
    processor.A              = 0x20;
    processor.memory[0x2042] = 0x14;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 1);
}

TEST(cmpIndirectX, cmpIndirectX)
{
    Memory memory;
    memory[STACK_START + 1] = CMP_IX;
    memory[STACK_START + 2] = 0x40;
    memory[0x42]            = 0x40;
    memory[0x43]            = 0x20;
    memory[0x2040]          = 0x14;
    Processor processor(memory);
    processor.X = 0x02;
    processor.A = 0x20;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 1);
}

TEST(cmpIndirectY, cmpIndirectY)
{
    Memory memory;
    memory[STACK_START + 1] = CMP_IY;
    memory[STACK_START + 2] = 0x40;
    memory[0x40]            = 0x40;
    memory[0x41]            = 0x20;
    memory[0x2042]          = 0x14;
    Processor processor(memory);
    processor.Y = 0x02;
    processor.A = 0x20;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 1);
}

TEST(cpxImmediate, cpxImmediate)
{
    Memory memory;
    memory[STACK_START + 1] = CPX_I;
    memory[STACK_START + 2] = 0x10;
    Processor processor(memory);
    processor.X = 0x10;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 1);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(cpxZeroPage, cpxZeroPage)
{
    Memory memory;
    memory[STACK_START + 1] = CPX_Z;
    memory[STACK_START + 2] = 0x40;
    memory[0x40]            = 0x10;
    Processor processor(memory);
    processor.X = 0x0F;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 0);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(cpxAbsolute, cpxAbsolute)
{
    Memory memory;
    memory[STACK_START + 1] = CPX_A;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    memory[0x2040]          = 0x10;
    Processor processor(memory);
    processor.X = 0x20;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 1);
}

TEST(cpyImmediate, cpyImmediate)
{
    Memory memory;
    memory[STACK_START + 1] = CPY_I;
    memory[STACK_START + 2] = 0x10;
    Processor processor(memory);
    processor.Y = 0x10;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 1);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(cpyZeroPage, cpyZeroPage)
{
    Memory memory;
    memory[STACK_START + 1] = CPY_Z;
    memory[STACK_START + 2] = 0x40;
    memory[0x40]            = 0x10;
    Processor processor(memory);
    processor.Y = 0x0F;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 0);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(cpyAbsolute, cpyAbsolute)
{
    Memory memory;
    memory[STACK_START + 1] = CPY_A;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    memory[0x2040]          = 0x10;
    Processor processor(memory);
    processor.Y = 0x20;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 1);
}

TEST(bitZeroPage, bitZeroPage)
{
    Memory memory;
    memory[STACK_START + 1] = BIT_Z;
    memory[STACK_START + 2] = 0x40;
    memory[0x40]            = 0xC0;
    Processor processor(memory);
    processor.A = 0x0F;
    processor.start();
    EXPECT_EQ(processor.processor_status.Z, 1);
    EXPECT_EQ(processor.processor_status.V, 1);
    EXPECT_EQ(processor.processor_status.N, 0);
}

TEST(bitAbsolute, bitAbsolute)
{
    Memory memory;
    memory[STACK_START + 1] = BIT_A;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    memory[0x2040]          = 0x40;
    Processor processor(memory);
    processor.A = 0xFF;
    processor.start();
    EXPECT_EQ(processor.processor_status.Z, 0);
    EXPECT_EQ(processor.processor_status.V, 1);
    EXPECT_EQ(processor.processor_status.N, 0);
}

TEST(tsx, tsx)
{
    Memory memory;
    memory[STACK_START + 1] = TSX;
    Processor processor(memory);
    processor.SP = 0x80;
    processor.start();
    EXPECT_EQ(processor.X, 0x80);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(tsxZero, tsxZero)
{
    Memory memory;
    memory[STACK_START + 1] = TSX;
    Processor processor(memory);
    processor.SP = 0x00;
    processor.start();
    EXPECT_EQ(processor.X, 0x00);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(txs, txs)
{
    Memory memory;
    memory[STACK_START + 1] = TXS;
    Processor processor(memory);
    processor.X = 0x42;
    processor.start();
    EXPECT_EQ(processor.SP, 0x42);
}

TEST(clc, clc)
{
    Memory memory;
    memory[STACK_START + 1] = CLC;
    Processor processor(memory);
    processor.processor_status.C = 1;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 0);
}

TEST(sec, sec)
{
    Memory memory;
    memory[STACK_START + 1] = SEC;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 1);
}

TEST(cli, cli)
{
    Memory memory;
    memory[STACK_START + 1] = CLI;
    Processor processor(memory);
    processor.processor_status.I = 1;
    processor.start();
    EXPECT_EQ(processor.processor_status.I, 0);
}

TEST(sei, sei)
{
    Memory memory;
    memory[STACK_START + 1] = SEI;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.processor_status.I, 1);
}

TEST(clv, clv)
{
    Memory memory;
    memory[STACK_START + 1] = CLV;
    Processor processor(memory);
    processor.processor_status.V = 1;
    processor.start();
    EXPECT_EQ(processor.processor_status.V, 0);
}

TEST(cld, cld)
{
    Memory memory;
    memory[STACK_START + 1] = CLD;
    Processor processor(memory);
    processor.processor_status.D = 1;
    processor.start();
    EXPECT_EQ(processor.processor_status.D, 0);
}

TEST(sed, sed)
{
    Memory memory;
    memory[STACK_START + 1] = SED;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.processor_status.D, 1);
}

TEST(pha, pha)
{
    Memory memory;
    memory[STACK_START + 1] = PHA;
    Processor processor(memory);
    processor.A = 0xA5;
    processor.start();
    EXPECT_EQ(processor.memory[0x01FF], 0xA5);
    EXPECT_EQ(processor.SP, 0xFE);
}

TEST(pla, pla)
{
    Memory memory;
    memory[STACK_START + 1] = PLA;
    Processor processor(memory);
    processor.SP             = 0xFE;
    processor.memory[0x01FF] = 0x80;
    processor.start();
    EXPECT_EQ(processor.A, 0x80);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(plaZero, plaZero)
{
    Memory memory;
    memory[STACK_START + 1] = PLA;
    Processor processor(memory);
    processor.SP             = 0xFE;
    processor.memory[0x01FF] = 0x00;
    processor.start();
    EXPECT_EQ(processor.A, 0x00);
    EXPECT_EQ(processor.processor_status.N, 0);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(php, php)
{
    Memory memory;
    memory[STACK_START + 1] = PHP;
    Processor processor(memory);
    processor.processor_status.C = 1;
    processor.start();
    EXPECT_EQ(processor.memory[0x01FF] & 0x31, 0x31);
    EXPECT_EQ(processor.SP, 0xFE);
}

TEST(plp, plp)
{
    Memory memory;
    memory[STACK_START + 1] = PLP;
    Processor processor(memory);
    processor.SP             = 0xFE;
    processor.memory[0x01FF] = 0xC5;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 1);
    EXPECT_EQ(processor.processor_status.Z, 0);
    EXPECT_EQ(processor.processor_status.I, 1);
    EXPECT_EQ(processor.processor_status.D, 0);
    EXPECT_EQ(processor.processor_status.V, 1);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(bcc, bcc)
{
    Memory memory;
    memory[STACK_START + 1] = BCC;
    memory[STACK_START + 2] = 0x02;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.PC, STACK_START + 5);
}

TEST(bccNotTaken, bccNotTaken)
{
    Memory memory;
    memory[STACK_START + 1] = BCC;
    memory[STACK_START + 2] = 0x02;
    Processor processor(memory);
    processor.processor_status.C = 1;
    processor.start();
    EXPECT_EQ(processor.PC, STACK_START + 3);
}

TEST(bcs, bcs)
{
    Memory memory;
    memory[STACK_START + 1] = BCS;
    memory[STACK_START + 2] = 0x02;
    Processor processor(memory);
    processor.processor_status.C = 1;
    processor.start();
    EXPECT_EQ(processor.PC, STACK_START + 5);
}

TEST(bcsNotTaken, bcsNotTaken)
{
    Memory memory;
    memory[STACK_START + 1] = BCS;
    memory[STACK_START + 2] = 0x02;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.PC, STACK_START + 3);
}

TEST(beq, beq)
{
    Memory memory;
    memory[STACK_START + 1] = BEQ;
    memory[STACK_START + 2] = 0x02;
    Processor processor(memory);
    processor.processor_status.Z = 1;
    processor.start();
    EXPECT_EQ(processor.PC, STACK_START + 5);
}

TEST(beqNotTaken, beqNotTaken)
{
    Memory memory;
    memory[STACK_START + 1] = BEQ;
    memory[STACK_START + 2] = 0x02;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.PC, STACK_START + 3);
}

TEST(bmi, bmi)
{
    Memory memory;
    memory[STACK_START + 1] = BMI;
    memory[STACK_START + 2] = 0x02;
    Processor processor(memory);
    processor.processor_status.N = 1;
    processor.start();
    EXPECT_EQ(processor.PC, STACK_START + 5);
}

TEST(bmiNotTaken, bmiNotTaken)
{
    Memory memory;
    memory[STACK_START + 1] = BMI;
    memory[STACK_START + 2] = 0x02;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.PC, STACK_START + 3);
}

TEST(bne, bne)
{
    Memory memory;
    memory[STACK_START + 1] = BNE;
    memory[STACK_START + 2] = 0x02;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.PC, STACK_START + 5);
}

TEST(bneNotTaken, bneNotTaken)
{
    Memory memory;
    memory[STACK_START + 1] = BNE;
    memory[STACK_START + 2] = 0x02;
    Processor processor(memory);
    processor.processor_status.Z = 1;
    processor.start();
    EXPECT_EQ(processor.PC, STACK_START + 3);
}

TEST(bpl, bpl)
{
    Memory memory;
    memory[STACK_START + 1] = BPL;
    memory[STACK_START + 2] = 0x02;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.PC, STACK_START + 5);
}

TEST(bplNotTaken, bplNotTaken)
{
    Memory memory;
    memory[STACK_START + 1] = BPL;
    memory[STACK_START + 2] = 0x02;
    Processor processor(memory);
    processor.processor_status.N = 1;
    processor.start();
    EXPECT_EQ(processor.PC, STACK_START + 3);
}

TEST(bvc, bvc)
{
    Memory memory;
    memory[STACK_START + 1] = BVC;
    memory[STACK_START + 2] = 0x02;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.PC, STACK_START + 5);
}

TEST(bvcNotTaken, bvcNotTaken)
{
    Memory memory;
    memory[STACK_START + 1] = BVC;
    memory[STACK_START + 2] = 0x02;
    Processor processor(memory);
    processor.processor_status.V = 1;
    processor.start();
    EXPECT_EQ(processor.PC, STACK_START + 3);
}

TEST(bvs, bvs)
{
    Memory memory;
    memory[STACK_START + 1] = BVS;
    memory[STACK_START + 2] = 0x02;
    Processor processor(memory);
    processor.processor_status.V = 1;
    processor.start();
    EXPECT_EQ(processor.PC, STACK_START + 5);
}

TEST(bvsNotTaken, bvsNotTaken)
{
    Memory memory;
    memory[STACK_START + 1] = BVS;
    memory[STACK_START + 2] = 0x02;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.PC, STACK_START + 3);
}

TEST(branchNegativeOffset, branchNegativeOffset)
{
    Memory memory;
    memory[STACK_START + 1] = BNE;
    memory[STACK_START + 2] = 0xFD;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.PC, STACK_START);
}

TEST(jmpAbsolute, jmpAbsolute)
{
    Memory memory;
    memory[STACK_START + 1] = JMP_A;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.PC, 0x2040);
}

TEST(jmpIndirect, jmpIndirect)
{
    Memory memory;
    memory[STACK_START + 1] = JMP_I;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    memory[0x2040]          = 0x80;
    memory[0x2041]          = 0x30;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.PC, 0x3080);
}

TEST(jsr, jsr)
{
    Memory memory;
    memory[STACK_START + 1] = JSR_A;
    memory[STACK_START + 2] = 0x40;
    memory[STACK_START + 3] = 0x20;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.PC, 0x2040);
    EXPECT_EQ(processor.SP, 0xFD);
    EXPECT_EQ(processor.memory[0x01FF], 0x02);
    EXPECT_EQ(processor.memory[0x01FE], 0x02);
}

TEST(rts, rts)
{
    Memory memory;
    memory[STACK_START + 1] = RTS;
    Processor processor(memory);
    processor.SP             = 0xFD;
    processor.memory[0x01FE] = 0x02;
    processor.memory[0x01FF] = 0x02;
    processor.start();
    EXPECT_EQ(processor.PC, STACK_START + 4);
    EXPECT_EQ(processor.SP, 0xFF);
}

TEST(nop, nop)
{
    Memory memory;
    memory[STACK_START + 1] = NOP;
    Processor processor(memory);
    processor.A = 0x12;
    processor.X = 0x34;
    processor.Y = 0x56;
    processor.start();
    EXPECT_EQ(processor.A, 0x12);
    EXPECT_EQ(processor.X, 0x34);
    EXPECT_EQ(processor.Y, 0x56);
}

TEST(adcCarryIn, adcCarryIn)
{
    Memory memory;
    memory[STACK_START + 1] = ADC_I;
    memory[STACK_START + 2] = 0x01;
    Processor processor(memory);
    processor.A                  = 0x01;
    processor.processor_status.C = 1;
    processor.start();
    EXPECT_EQ(processor.A, 0x03);
    EXPECT_EQ(processor.processor_status.C, 0);
    EXPECT_EQ(processor.processor_status.Z, 0);
    EXPECT_EQ(processor.processor_status.N, 0);
    EXPECT_EQ(processor.processor_status.V, 0);
}

TEST(adcCarryOut, adcCarryOut)
{
    Memory memory;
    memory[STACK_START + 1] = ADC_I;
    memory[STACK_START + 2] = 0x01;
    Processor processor(memory);
    processor.A = 0xFF;
    processor.start();
    EXPECT_EQ(processor.A, 0x00);
    EXPECT_EQ(processor.processor_status.C, 1);
    EXPECT_EQ(processor.processor_status.Z, 1);
    EXPECT_EQ(processor.processor_status.N, 0);
    EXPECT_EQ(processor.processor_status.V, 0);
}

TEST(adcOverflow, adcOverflow)
{
    Memory memory;
    memory[STACK_START + 1] = ADC_I;
    memory[STACK_START + 2] = 0x01;
    Processor processor(memory);
    processor.A = 0x7F;
    processor.start();
    EXPECT_EQ(processor.A, 0x80);
    EXPECT_EQ(processor.processor_status.C, 0);
    EXPECT_EQ(processor.processor_status.Z, 0);
    EXPECT_EQ(processor.processor_status.N, 1);
    EXPECT_EQ(processor.processor_status.V, 1);
}

TEST(sbcCarrySet, sbcCarrySet)
{
    Memory memory;
    memory[STACK_START + 1] = SBC_I;
    memory[STACK_START + 2] = 0x01;
    Processor processor(memory);
    processor.A                  = 0x02;
    processor.processor_status.C = 1;
    processor.start();
    EXPECT_EQ(processor.A, 0x01);
    EXPECT_EQ(processor.processor_status.C, 1);
    EXPECT_EQ(processor.processor_status.Z, 0);
    EXPECT_EQ(processor.processor_status.N, 0);
    EXPECT_EQ(processor.processor_status.V, 0);
}

TEST(sbcCarryClear, sbcCarryClear)
{
    Memory memory;
    memory[STACK_START + 1] = SBC_I;
    memory[STACK_START + 2] = 0x01;
    Processor processor(memory);
    processor.A                  = 0x02;
    processor.processor_status.C = 0;
    processor.start();
    EXPECT_EQ(processor.A, 0x00);
    EXPECT_EQ(processor.processor_status.C, 1);
    EXPECT_EQ(processor.processor_status.Z, 1);
    EXPECT_EQ(processor.processor_status.N, 0);
    EXPECT_EQ(processor.processor_status.V, 0);
}

TEST(sbcBorrow, sbcBorrow)
{
    Memory memory;
    memory[STACK_START + 1] = SBC_I;
    memory[STACK_START + 2] = 0x01;
    Processor processor(memory);
    processor.A                  = 0x00;
    processor.processor_status.C = 0;
    processor.start();
    EXPECT_EQ(processor.A, 0xFE);
    EXPECT_EQ(processor.processor_status.C, 0);
    EXPECT_EQ(processor.processor_status.Z, 0);
    EXPECT_EQ(processor.processor_status.N, 1);
    EXPECT_EQ(processor.processor_status.V, 0);
}

TEST(sbcOverflow, sbcOverflow)
{
    Memory memory;
    memory[STACK_START + 1] = SBC_I;
    memory[STACK_START + 2] = 0x01;
    Processor processor(memory);
    processor.A                  = 0x80;
    processor.processor_status.C = 1;
    processor.start();
    EXPECT_EQ(processor.A, 0x7F);
    EXPECT_EQ(processor.processor_status.C, 1);
    EXPECT_EQ(processor.processor_status.Z, 0);
    EXPECT_EQ(processor.processor_status.N, 0);
    EXPECT_EQ(processor.processor_status.V, 1);
}

TEST(ldaNegative, ldaNegative)
{
    Memory memory;
    memory[STACK_START + 1] = LDA_I;
    memory[STACK_START + 2] = 0x80;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.A, 0x80);
    EXPECT_EQ(processor.processor_status.N, 1);
    EXPECT_EQ(processor.processor_status.Z, 0);
}

TEST(ldaZero, ldaZero)
{
    Memory memory;
    memory[STACK_START + 1] = LDA_I;
    memory[STACK_START + 2] = 0x00;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.A, 0x00);
    EXPECT_EQ(processor.processor_status.N, 0);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(ldxNegative, ldxNegative)
{
    Memory memory;
    memory[STACK_START + 1] = LDX_I;
    memory[STACK_START + 2] = 0x80;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.X, 0x80);
    EXPECT_EQ(processor.processor_status.N, 1);
    EXPECT_EQ(processor.processor_status.Z, 0);
}

TEST(ldxZero, ldxZero)
{
    Memory memory;
    memory[STACK_START + 1] = LDX_I;
    memory[STACK_START + 2] = 0x00;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.X, 0x00);
    EXPECT_EQ(processor.processor_status.N, 0);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(ldyNegative, ldyNegative)
{
    Memory memory;
    memory[STACK_START + 1] = LDY_I;
    memory[STACK_START + 2] = 0x80;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.Y, 0x80);
    EXPECT_EQ(processor.processor_status.N, 1);
    EXPECT_EQ(processor.processor_status.Z, 0);
}

TEST(ldyZero, ldyZero)
{
    Memory memory;
    memory[STACK_START + 1] = LDY_I;
    memory[STACK_START + 2] = 0x00;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.Y, 0x00);
    EXPECT_EQ(processor.processor_status.N, 0);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(eorNegative, eorNegative)
{
    Memory memory;
    memory[STACK_START + 1] = EOR_I;
    memory[STACK_START + 2] = 0x80;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.A, 0x80);
    EXPECT_EQ(processor.processor_status.N, 1);
    EXPECT_EQ(processor.processor_status.Z, 0);
}

TEST(oraZero, oraZero)
{
    Memory memory;
    memory[STACK_START + 1] = ORA_I;
    memory[STACK_START + 2] = 0x00;
    Processor processor(memory);
    processor.start();
    EXPECT_EQ(processor.A, 0x00);
    EXPECT_EQ(processor.processor_status.N, 0);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(cmpEqual, cmpEqual)
{
    Memory memory;
    memory[STACK_START + 1] = CMP_I;
    memory[STACK_START + 2] = 0x20;
    Processor processor(memory);
    processor.A = 0x20;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 1);
    EXPECT_EQ(processor.processor_status.Z, 1);
    EXPECT_EQ(processor.processor_status.N, 0);
}

TEST(cpxEqual, cpxEqual)
{
    Memory memory;
    memory[STACK_START + 1] = CPX_I;
    memory[STACK_START + 2] = 0x20;
    Processor processor(memory);
    processor.X = 0x20;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 1);
    EXPECT_EQ(processor.processor_status.Z, 1);
    EXPECT_EQ(processor.processor_status.N, 0);
}

TEST(cpyEqual, cpyEqual)
{
    Memory memory;
    memory[STACK_START + 1] = CPY_I;
    memory[STACK_START + 2] = 0x20;
    Processor processor(memory);
    processor.Y = 0x20;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 1);
    EXPECT_EQ(processor.processor_status.Z, 1);
    EXPECT_EQ(processor.processor_status.N, 0);
}

TEST(aslFlags, aslFlags)
{
    Memory memory;
    memory[STACK_START + 1] = ASL_AC;
    Processor processor(memory);
    processor.A = 0x00;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 0);
    EXPECT_EQ(processor.processor_status.Z, 1);
    EXPECT_EQ(processor.processor_status.N, 0);
}

TEST(lsrFlags, lsrFlags)
{
    Memory memory;
    memory[STACK_START + 1] = LSR_AC;
    Processor processor(memory);
    processor.A = 0x01;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 1);
    EXPECT_EQ(processor.processor_status.Z, 1);
    EXPECT_EQ(processor.processor_status.N, 0);
}

TEST(rolFlags, rolFlags)
{
    Memory memory;
    memory[STACK_START + 1] = ROL_AC;
    Processor processor(memory);
    processor.A = 0x00;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 0);
    EXPECT_EQ(processor.processor_status.Z, 1);
    EXPECT_EQ(processor.processor_status.N, 0);
}

TEST(rorFlags, rorFlags)
{
    Memory memory;
    memory[STACK_START + 1] = ROR_AC;
    Processor processor(memory);
    processor.A = 0x01;
    processor.start();
    EXPECT_EQ(processor.A, 0x00);
    EXPECT_EQ(processor.processor_status.C, 1);
    EXPECT_EQ(processor.processor_status.Z, 1);
    EXPECT_EQ(processor.processor_status.N, 0);
}

TEST(adcSignedNegative, adcSignedNegative)
{
    Memory memory;
    memory[STACK_START + 1] = ADC_I;
    memory[STACK_START + 2] = 0x01;
    Processor processor(memory);
    processor.A = 0xFE;
    processor.start();
    EXPECT_EQ(processor.A, 0xFF);
    EXPECT_EQ(processor.processor_status.C, 0);
    EXPECT_EQ(processor.processor_status.Z, 0);
    EXPECT_EQ(processor.processor_status.N, 1);
    EXPECT_EQ(processor.processor_status.V, 0);
}

TEST(cmpImmediateNegative, cmpImmediateNegative)
{
    Memory memory;
    memory[STACK_START + 1] = CMP_I;
    memory[STACK_START + 2] = 0x01;
    Processor processor(memory);
    processor.A = 0xF1;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 0);
    EXPECT_EQ(processor.processor_status.Z, 0);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(cmpImmediateLess, cmpImmediateLess)
{
    Memory memory;
    memory[STACK_START + 1] = CMP_I;
    memory[STACK_START + 2] = 0xF1;
    Processor processor(memory);
    processor.A = 0x01;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 1);
    EXPECT_EQ(processor.processor_status.Z, 0);
    EXPECT_EQ(processor.processor_status.N, 0);
}

TEST(cpxImmediateNegative, cpxImmediateNegative)
{
    Memory memory;
    memory[STACK_START + 1] = CPX_I;
    memory[STACK_START + 2] = 0x01;
    Processor processor(memory);
    processor.X = 0xF1;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 0);
    EXPECT_EQ(processor.processor_status.Z, 0);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(cpyImmediateNegative, cpyImmediateNegative)
{
    Memory memory;
    memory[STACK_START + 1] = CPY_I;
    memory[STACK_START + 2] = 0x01;
    Processor processor(memory);
    processor.Y = 0xF1;
    processor.start();
    EXPECT_EQ(processor.processor_status.C, 0);
    EXPECT_EQ(processor.processor_status.Z, 0);
    EXPECT_EQ(processor.processor_status.N, 1);
}

TEST(rolCarryIn, rolCarryIn)
{
    Memory memory;
    memory[STACK_START + 1] = ROL_AC;
    Processor processor(memory);
    processor.A                  = 0x00;
    processor.processor_status.C = 1;
    processor.start();
    EXPECT_EQ(processor.A, 0x01);
    EXPECT_EQ(processor.processor_status.C, 0);
}

TEST(rorCarryIn, rorCarryIn)
{
    Memory memory;
    memory[STACK_START + 1] = ROR_AC;
    Processor processor(memory);
    processor.A                  = 0x00;
    processor.processor_status.C = 1;
    processor.start();
    EXPECT_EQ(processor.A, 0x80);
    EXPECT_EQ(processor.processor_status.C, 0);
}

TEST(adcCarryClear, adcCarryClear)
{
    Memory memory;
    memory[STACK_START + 1] = ADC_I;
    memory[STACK_START + 2] = 0x05;
    Processor processor(memory);
    processor.A                  = 0x10;
    processor.processor_status.C = 0;
    processor.start();
    EXPECT_EQ(processor.A, 0x15);
    EXPECT_EQ(processor.processor_status.C, 0);
    EXPECT_EQ(processor.processor_status.V, 0);
    EXPECT_EQ(processor.processor_status.N, 0);
    EXPECT_EQ(processor.processor_status.Z, 0);
}

TEST(adcCarrySetNoOverflow, adcCarrySetNoOverflow)
{
    Memory memory;
    memory[STACK_START + 1] = ADC_I;
    memory[STACK_START + 2] = 0x05;
    Processor processor(memory);
    processor.A                  = 0x10;
    processor.processor_status.C = 1;
    processor.start();
    EXPECT_EQ(processor.A, 0x16);
    EXPECT_EQ(processor.processor_status.C, 0);
    EXPECT_EQ(processor.processor_status.V, 0);
    EXPECT_EQ(processor.processor_status.N, 0);
    EXPECT_EQ(processor.processor_status.Z, 0);
}

TEST(adcCarryOutWithoutOverflow, adcCarryOutWithoutOverflow)
{
    Memory memory;
    memory[STACK_START + 1] = ADC_I;
    memory[STACK_START + 2] = 0x01;
    Processor processor(memory);
    processor.A                  = 0xFF;
    processor.processor_status.C = 0;
    processor.start();
    EXPECT_EQ(processor.A, 0x00);
    EXPECT_EQ(processor.processor_status.C, 1);
    EXPECT_EQ(processor.processor_status.V, 0);
    EXPECT_EQ(processor.processor_status.N, 0);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(adcNegativeOverflow, adcNegativeOverflow)
{
    Memory memory;
    memory[STACK_START + 1] = ADC_I;
    memory[STACK_START + 2] = 0x80;
    Processor processor(memory);
    processor.A                  = 0x80;
    processor.processor_status.C = 0;
    processor.start();
    EXPECT_EQ(processor.A, 0x00);
    EXPECT_EQ(processor.processor_status.C, 1);
    EXPECT_EQ(processor.processor_status.V, 1);
    EXPECT_EQ(processor.processor_status.N, 0);
    EXPECT_EQ(processor.processor_status.Z, 1);
}

TEST(sbcNoBorrow, sbcNoBorrow)
{
    Memory memory;
    memory[STACK_START + 1] = SBC_I;
    memory[STACK_START + 2] = 0x05;
    Processor processor(memory);
    processor.A                  = 0x10;
    processor.processor_status.C = 1;
    processor.start();
    EXPECT_EQ(processor.A, 0x0B);
    EXPECT_EQ(processor.processor_status.C, 1);
    EXPECT_EQ(processor.processor_status.V, 0);
    EXPECT_EQ(processor.processor_status.N, 0);
    EXPECT_EQ(processor.processor_status.Z, 0);
}

TEST(sbcCarryClearWithNoBorrow, sbcCarryClearWithNoBorrow)
{
    Memory memory;
    memory[STACK_START + 1] = SBC_I;
    memory[STACK_START + 2] = 0x05;
    Processor processor(memory);
    processor.A                  = 0x10;
    processor.processor_status.C = 0;
    processor.start();
    EXPECT_EQ(processor.A, 0x0A);
    EXPECT_EQ(processor.processor_status.C, 1);
    EXPECT_EQ(processor.processor_status.V, 0);
    EXPECT_EQ(processor.processor_status.N, 0);
    EXPECT_EQ(processor.processor_status.Z, 0);
}

TEST(sbcBorrowWithCarrySet, sbcBorrowWithCarrySet)
{
    Memory memory;
    memory[STACK_START + 1] = SBC_I;
    memory[STACK_START + 2] = 0x01;
    Processor processor(memory);
    processor.A                  = 0x00;
    processor.processor_status.C = 1;
    processor.start();
    EXPECT_EQ(processor.A, 0xFF);
    EXPECT_EQ(processor.processor_status.C, 0);
    EXPECT_EQ(processor.processor_status.V, 0);
    EXPECT_EQ(processor.processor_status.N, 1);
    EXPECT_EQ(processor.processor_status.Z, 0);
}

TEST(sbcPositiveOverflow, sbcPositiveOverflow)
{
    Memory memory;
    memory[STACK_START + 1] = SBC_I;
    memory[STACK_START + 2] = 0xFF;
    Processor processor(memory);
    processor.A                  = 0x7F;
    processor.processor_status.C = 1;
    processor.start();
    EXPECT_EQ(processor.A, 0x80);
    EXPECT_EQ(processor.processor_status.C, 0);
    EXPECT_EQ(processor.processor_status.V, 1);
    EXPECT_EQ(processor.processor_status.N, 1);
    EXPECT_EQ(processor.processor_status.Z, 0);
}

TEST(sbcNegativeOverflow, sbcNegativeOverflow)
{
    Memory memory;
    memory[STACK_START + 1] = SBC_I;
    memory[STACK_START + 2] = 0x01;
    Processor processor(memory);
    processor.A                  = 0x80;
    processor.processor_status.C = 1;
    processor.start();
    EXPECT_EQ(processor.A, 0x7F);
    EXPECT_EQ(processor.processor_status.C, 1);
    EXPECT_EQ(processor.processor_status.V, 1);
    EXPECT_EQ(processor.processor_status.N, 0);
    EXPECT_EQ(processor.processor_status.Z, 0);
}