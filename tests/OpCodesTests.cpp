#include <gtest/gtest.h>
#include <Processor/OpCodes.h>
#include <Core/Defines.h>

using namespace E6502;

TEST(testADC, testADC)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & ADC_I)>>2;
    EXPECT_EQ(IMMEDIATE_01, adressing);

    adressing = (adressMask & ADC_Z)>>2;
    EXPECT_EQ(ZERO_PAGE_01, adressing);

    adressing = (adressMask & ADC_ZX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_01, adressing);

    adressing = (adressMask & ADC_A)>>2;
    EXPECT_EQ(ABSOLUTE_01, adressing);
    
    adressing = (adressMask & ADC_AX)>>2;
    EXPECT_EQ(ABSOLUTE_X_01, adressing);
    
    adressing = (adressMask & ADC_AY)>>2;
    EXPECT_EQ(ABSOLUTE_Y_01, adressing);

    adressing = (adressMask & ADC_IX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_INDIRECT_01, adressing);

    adressing = (adressMask & ADC_IY)>>2;
    EXPECT_EQ(ZERO_PAGE_Y_INDIRECT_01, adressing);
}

TEST(testAND, testAND)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & AND_I)>>2;
    EXPECT_EQ(IMMEDIATE_01, adressing);

    adressing = (adressMask & AND_Z)>>2;
    EXPECT_EQ(ZERO_PAGE_01, adressing);

    adressing = (adressMask & AND_ZX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_01, adressing);

    adressing = (adressMask & AND_A)>>2;
    EXPECT_EQ(ABSOLUTE_01, adressing);
    
    adressing = (adressMask & AND_AX)>>2;
    EXPECT_EQ(ABSOLUTE_X_01, adressing);
    
    adressing = (adressMask & AND_AY)>>2;
    EXPECT_EQ(ABSOLUTE_Y_01, adressing);

    adressing = (adressMask & AND_IX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_INDIRECT_01, adressing);

    adressing = (adressMask & AND_IY)>>2;
    EXPECT_EQ(ZERO_PAGE_Y_INDIRECT_01, adressing);
}

TEST(testCMP, testCMP)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & CMP_I)>>2;
    EXPECT_EQ(IMMEDIATE_01, adressing);

    adressing = (adressMask & CMP_Z)>>2;
    EXPECT_EQ(ZERO_PAGE_01, adressing);

    adressing = (adressMask & CMP_ZX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_01, adressing);

    adressing = (adressMask & CMP_A)>>2;
    EXPECT_EQ(ABSOLUTE_01, adressing);
    
    adressing = (adressMask & CMP_AX)>>2;
    EXPECT_EQ(ABSOLUTE_X_01, adressing);
    
    adressing = (adressMask & CMP_AY)>>2;
    EXPECT_EQ(ABSOLUTE_Y_01, adressing);

    adressing = (adressMask & CMP_IX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_INDIRECT_01, adressing);

    adressing = (adressMask & CMP_IY)>>2;
    EXPECT_EQ(ZERO_PAGE_Y_INDIRECT_01, adressing);
}

TEST(testEOR, testEOR)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & EOR_I)>>2;
    EXPECT_EQ(IMMEDIATE_01, adressing);

    adressing = (adressMask & EOR_Z)>>2;
    EXPECT_EQ(ZERO_PAGE_01, adressing);

    adressing = (adressMask & EOR_ZX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_01, adressing);

    adressing = (adressMask & EOR_A)>>2;
    EXPECT_EQ(ABSOLUTE_01, adressing);
    
    adressing = (adressMask & EOR_AX)>>2;
    EXPECT_EQ(ABSOLUTE_X_01, adressing);
    
    adressing = (adressMask & EOR_AY)>>2;
    EXPECT_EQ(ABSOLUTE_Y_01, adressing);

    adressing = (adressMask & EOR_IX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_INDIRECT_01, adressing);

    adressing = (adressMask & EOR_IY)>>2;
    EXPECT_EQ(ZERO_PAGE_Y_INDIRECT_01, adressing);
}

TEST(testLDA, testLDA)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & LDA_I)>>2;
    EXPECT_EQ(IMMEDIATE_01, adressing);

    adressing = (adressMask & LDA_Z)>>2;
    EXPECT_EQ(ZERO_PAGE_01, adressing);

    adressing = (adressMask & LDA_ZX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_01, adressing);

    adressing = (adressMask & LDA_A)>>2;
    EXPECT_EQ(ABSOLUTE_01, adressing);
    
    adressing = (adressMask & LDA_AX)>>2;
    EXPECT_EQ(ABSOLUTE_X_01, adressing);
    
    adressing = (adressMask & LDA_AY)>>2;
    EXPECT_EQ(ABSOLUTE_Y_01, adressing);

    adressing = (adressMask & LDA_IX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_INDIRECT_01, adressing);

    adressing = (adressMask & LDA_IY)>>2;
    EXPECT_EQ(ZERO_PAGE_Y_INDIRECT_01, adressing);
}

TEST(testORA, testORA)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & ORA_I)>>2;
    EXPECT_EQ(IMMEDIATE_01, adressing);

    adressing = (adressMask & ORA_Z)>>2;
    EXPECT_EQ(ZERO_PAGE_01, adressing);

    adressing = (adressMask & ORA_ZX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_01, adressing);

    adressing = (adressMask & ORA_A)>>2;
    EXPECT_EQ(ABSOLUTE_01, adressing);
    
    adressing = (adressMask & ORA_AX)>>2;
    EXPECT_EQ(ABSOLUTE_X_01, adressing);
    
    adressing = (adressMask & ORA_AY)>>2;
    EXPECT_EQ(ABSOLUTE_Y_01, adressing);

    adressing = (adressMask & ORA_IX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_INDIRECT_01, adressing);

    adressing = (adressMask & ORA_IY)>>2;
    EXPECT_EQ(ZERO_PAGE_Y_INDIRECT_01, adressing);
}

TEST(testSTA, testSTA)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & STA_Z)>>2;
    EXPECT_EQ(ZERO_PAGE_01, adressing);

    adressing = (adressMask & STA_ZX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_01, adressing);

    adressing = (adressMask & STA_A)>>2;
    EXPECT_EQ(ABSOLUTE_01, adressing);
    
    adressing = (adressMask & STA_AX)>>2;
    EXPECT_EQ(ABSOLUTE_X_01, adressing);
    
    adressing = (adressMask & STA_AY)>>2;
    EXPECT_EQ(ABSOLUTE_Y_01, adressing);

    adressing = (adressMask & STA_IX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_INDIRECT_01, adressing);

    adressing = (adressMask & STA_IY)>>2;
    EXPECT_EQ(ZERO_PAGE_Y_INDIRECT_01, adressing);
}

TEST(testSBC, testSBC)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & SBC_Z)>>2;
    EXPECT_EQ(ZERO_PAGE_01, adressing);

    adressing = (adressMask & SBC_ZX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_01, adressing);

    adressing = (adressMask & SBC_A)>>2;
    EXPECT_EQ(ABSOLUTE_01, adressing);
    
    adressing = (adressMask & SBC_AX)>>2;
    EXPECT_EQ(ABSOLUTE_X_01, adressing);
    
    adressing = (adressMask & SBC_AY)>>2;
    EXPECT_EQ(ABSOLUTE_Y_01, adressing);

    adressing = (adressMask & SBC_IX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_INDIRECT_01, adressing);

    adressing = (adressMask & SBC_IY)>>2;
    EXPECT_EQ(ZERO_PAGE_Y_INDIRECT_01, adressing);
}