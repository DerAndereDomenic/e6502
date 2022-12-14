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
    memory[0x3F] = 0x42;
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
    memory[0xC5] = 0x52;
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
    memory[0x20] = 0x52;
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
    memory[0xAC31] = 0x7F;
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
    memory[0xAC39] = 0x7F;
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
    memory[0xAC39] = 0x7F;
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
    memory[0x24] = 0x74;
    memory[0x25] = 0x20;
    memory[0x2074] = 0x11;
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
    memory[0x01] = 0x74;
    memory[0x02] = 0x20;
    memory[0x2074] = 0x11;
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
    memory[0x86] = 0x28;
    memory[0x87] = 0x40;
    memory[0x4038] = 0xF1;
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
    memory[0x3F] = 0x42;
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
    memory[0xC5] = 0x52;
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
    memory[0x20] = 0x52;
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
    memory[0xAC31] = 0x7F;
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
    memory[0xAC39] = 0x7F;
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
    memory[0x3F] = 0x42;
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
    memory[0xC5] = 0x52;
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
    memory[0x20] = 0x52;
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
    memory[0xAC31] = 0x7F;
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
    memory[0xAC39] = 0x7F;
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
    memory[0x3F] = 20;
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
    memory[0x3F] = 20;
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
    memory[0x3F] = 20;
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
    memory[0x3F] = 20;
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
    memory[0x3F] = 20;
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
    memory[0x3F] = 20;
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
    memory[0x3330] = 20;
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
    memory[0x3330] = 20;
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
    memory[0x3330] = 20;
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
    memory[0x3334] = 20;
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
    memory[0x3334] = 20;
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
    memory[0x3334] = 20;
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
    memory[0x3334] = 20;
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
    memory[0x3334] = 20;
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
    memory[0x3334] = 20;
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
    memory[0x24] = 0x74;
    memory[0x25] = 0x20;
    memory[0x2074] = 20;
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
    memory[0x01] = 0x74;
    memory[0x02] = 0x20;
    memory[0x2074] = 20;
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
    memory[0x24] = 0x74;
    memory[0x25] = 0x20;
    memory[0x2074] = 20;
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
    memory[0x24] = 0x74;
    memory[0x25] = 0x20;
    memory[0x2074] = 20;
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
    memory[0x86] = 0x28;
    memory[0x87] = 0x40;
    memory[0x4038] = 20;
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
    memory[0x86] = 0x28;
    memory[0x87] = 0x40;
    memory[0x4038] = 20;
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
    memory[0x86] = 0x28;
    memory[0x87] = 0x40;
    memory[0x4038] = 20;
    Processor processor(memory);
    processor.A = -21;
    processor.Y = 0x10;

    processor.start();

    EXPECT_EQ(processor.A, 0xFF);
    EXPECT_EQ(processor.processor_status.N, 1);
}