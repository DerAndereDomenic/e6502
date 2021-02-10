#include <gtest/gtest.h>
#include <Processor/OpCodes.h>
#include <Core/Defines.h>

using namespace E6502;

TEST(testADC, testADC)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & ADC_I)>>2;
    EXPECT_EQ(IMMEDIATE, adressing);

    adressing = (adressMask & ADC_Z)>>2;
    EXPECT_EQ(ZERO_PAGE, adressing);

    adressing = (adressMask & ADC_ZX)>>2;
    EXPECT_EQ(ZERO_PAGE_X, adressing);

    adressing = (adressMask & ADC_A)>>2;
    EXPECT_EQ(ABSOLUTE, adressing);
    
    adressing = (adressMask & ADC_AX)>>2;
    EXPECT_EQ(ABSOLUTE_X, adressing);
    
    adressing = (adressMask & ADC_AY)>>2;
    EXPECT_EQ(ABSOLUTE_Y, adressing);

    adressing = (adressMask & ADC_IX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_INDIRECT, adressing);

    adressing = (adressMask & ADC_IY)>>2;
    EXPECT_EQ(ZERO_PAGE_Y_INDIRECT, adressing);
}

TEST(testAND, testAND)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & AND_I)>>2;
    EXPECT_EQ(IMMEDIATE, adressing);

    adressing = (adressMask & AND_Z)>>2;
    EXPECT_EQ(ZERO_PAGE, adressing);

    adressing = (adressMask & AND_ZX)>>2;
    EXPECT_EQ(ZERO_PAGE_X, adressing);

    adressing = (adressMask & AND_A)>>2;
    EXPECT_EQ(ABSOLUTE, adressing);
    
    adressing = (adressMask & AND_AX)>>2;
    EXPECT_EQ(ABSOLUTE_X, adressing);
    
    adressing = (adressMask & AND_AY)>>2;
    EXPECT_EQ(ABSOLUTE_Y, adressing);

    adressing = (adressMask & AND_IX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_INDIRECT, adressing);

    adressing = (adressMask & AND_IY)>>2;
    EXPECT_EQ(ZERO_PAGE_Y_INDIRECT, adressing);
}

TEST(testCMP, testCMP)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & CMP_I)>>2;
    EXPECT_EQ(IMMEDIATE, adressing);

    adressing = (adressMask & CMP_Z)>>2;
    EXPECT_EQ(ZERO_PAGE, adressing);

    adressing = (adressMask & CMP_ZX)>>2;
    EXPECT_EQ(ZERO_PAGE_X, adressing);

    adressing = (adressMask & CMP_A)>>2;
    EXPECT_EQ(ABSOLUTE, adressing);
    
    adressing = (adressMask & CMP_AX)>>2;
    EXPECT_EQ(ABSOLUTE_X, adressing);
    
    adressing = (adressMask & CMP_AY)>>2;
    EXPECT_EQ(ABSOLUTE_Y, adressing);

    adressing = (adressMask & CMP_IX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_INDIRECT, adressing);

    adressing = (adressMask & CMP_IY)>>2;
    EXPECT_EQ(ZERO_PAGE_Y_INDIRECT, adressing);
}

TEST(testEOR, testEOR)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & EOR_I)>>2;
    EXPECT_EQ(IMMEDIATE, adressing);

    adressing = (adressMask & EOR_Z)>>2;
    EXPECT_EQ(ZERO_PAGE, adressing);

    adressing = (adressMask & EOR_ZX)>>2;
    EXPECT_EQ(ZERO_PAGE_X, adressing);

    adressing = (adressMask & EOR_A)>>2;
    EXPECT_EQ(ABSOLUTE, adressing);
    
    adressing = (adressMask & EOR_AX)>>2;
    EXPECT_EQ(ABSOLUTE_X, adressing);
    
    adressing = (adressMask & EOR_AY)>>2;
    EXPECT_EQ(ABSOLUTE_Y, adressing);

    adressing = (adressMask & EOR_IX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_INDIRECT, adressing);

    adressing = (adressMask & EOR_IY)>>2;
    EXPECT_EQ(ZERO_PAGE_Y_INDIRECT, adressing);
}

TEST(testLDA, testLDA)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & LDA_I)>>2;
    EXPECT_EQ(IMMEDIATE, adressing);

    adressing = (adressMask & LDA_Z)>>2;
    EXPECT_EQ(ZERO_PAGE, adressing);

    adressing = (adressMask & LDA_ZX)>>2;
    EXPECT_EQ(ZERO_PAGE_X, adressing);

    adressing = (adressMask & LDA_A)>>2;
    EXPECT_EQ(ABSOLUTE, adressing);
    
    adressing = (adressMask & LDA_AX)>>2;
    EXPECT_EQ(ABSOLUTE_X, adressing);
    
    adressing = (adressMask & LDA_AY)>>2;
    EXPECT_EQ(ABSOLUTE_Y, adressing);

    adressing = (adressMask & LDA_IX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_INDIRECT, adressing);

    adressing = (adressMask & LDA_IY)>>2;
    EXPECT_EQ(ZERO_PAGE_Y_INDIRECT, adressing);
}

TEST(testORA, testORA)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & ORA_I)>>2;
    EXPECT_EQ(IMMEDIATE, adressing);

    adressing = (adressMask & ORA_Z)>>2;
    EXPECT_EQ(ZERO_PAGE, adressing);

    adressing = (adressMask & ORA_ZX)>>2;
    EXPECT_EQ(ZERO_PAGE_X, adressing);

    adressing = (adressMask & ORA_A)>>2;
    EXPECT_EQ(ABSOLUTE, adressing);
    
    adressing = (adressMask & ORA_AX)>>2;
    EXPECT_EQ(ABSOLUTE_X, adressing);
    
    adressing = (adressMask & ORA_AY)>>2;
    EXPECT_EQ(ABSOLUTE_Y, adressing);

    adressing = (adressMask & ORA_IX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_INDIRECT, adressing);

    adressing = (adressMask & ORA_IY)>>2;
    EXPECT_EQ(ZERO_PAGE_Y_INDIRECT, adressing);
}

TEST(testSTA, testSTA)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & STA_Z)>>2;
    EXPECT_EQ(ZERO_PAGE, adressing);

    adressing = (adressMask & STA_ZX)>>2;
    EXPECT_EQ(ZERO_PAGE_X, adressing);

    adressing = (adressMask & STA_A)>>2;
    EXPECT_EQ(ABSOLUTE, adressing);
    
    adressing = (adressMask & STA_AX)>>2;
    EXPECT_EQ(ABSOLUTE_X, adressing);
    
    adressing = (adressMask & STA_AY)>>2;
    EXPECT_EQ(ABSOLUTE_Y, adressing);

    adressing = (adressMask & STA_IX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_INDIRECT, adressing);

    adressing = (adressMask & STA_IY)>>2;
    EXPECT_EQ(ZERO_PAGE_Y_INDIRECT, adressing);
}

TEST(testSBC, testSBC)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & SBC_Z)>>2;
    EXPECT_EQ(ZERO_PAGE, adressing);

    adressing = (adressMask & SBC_ZX)>>2;
    EXPECT_EQ(ZERO_PAGE_X, adressing);

    adressing = (adressMask & SBC_A)>>2;
    EXPECT_EQ(ABSOLUTE, adressing);
    
    adressing = (adressMask & SBC_AX)>>2;
    EXPECT_EQ(ABSOLUTE_X, adressing);
    
    adressing = (adressMask & SBC_AY)>>2;
    EXPECT_EQ(ABSOLUTE_Y, adressing);

    adressing = (adressMask & SBC_IX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_INDIRECT, adressing);

    adressing = (adressMask & SBC_IY)>>2;
    EXPECT_EQ(ZERO_PAGE_Y_INDIRECT, adressing);
}