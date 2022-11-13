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

TEST(testASL, testASL)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & ASL_Z)>>2;
    EXPECT_EQ(ZERO_PAGE_10, adressing);

    adressing = (adressMask & ASL_AC)>>2;
    EXPECT_EQ(ACCUMULATOR_10, adressing);

    adressing = (adressMask & ASL_A)>>2;
    EXPECT_EQ(ABSOLUTE_10, adressing);

    adressing = (adressMask & ASL_ZX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_10, adressing);

    adressing = (adressMask & ASL_AX)>>2;
    EXPECT_EQ(ABSOLUTE_X_10, adressing);
}

TEST(testROL, testROL)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & ROL_Z)>>2;
    EXPECT_EQ(ZERO_PAGE_10, adressing);

    adressing = (adressMask & ROL_AC)>>2;
    EXPECT_EQ(ACCUMULATOR_10, adressing);

    adressing = (adressMask & ROL_A)>>2;
    EXPECT_EQ(ABSOLUTE_10, adressing);

    adressing = (adressMask & ROL_ZX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_10, adressing);

    adressing = (adressMask & ROL_AX)>>2;
    EXPECT_EQ(ABSOLUTE_X_10, adressing);
}

TEST(testLSR, testLSR)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & LSR_Z)>>2;
    EXPECT_EQ(ZERO_PAGE_10, adressing);

    adressing = (adressMask & LSR_AC)>>2;
    EXPECT_EQ(ACCUMULATOR_10, adressing);

    adressing = (adressMask & LSR_A)>>2;
    EXPECT_EQ(ABSOLUTE_10, adressing);

    adressing = (adressMask & LSR_ZX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_10, adressing);

    adressing = (adressMask & LSR_AX)>>2;
    EXPECT_EQ(ABSOLUTE_X_10, adressing);
}

TEST(testROR, testROR)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & ROR_Z)>>2;
    EXPECT_EQ(ZERO_PAGE_10, adressing);

    adressing = (adressMask & ROR_AC)>>2;
    EXPECT_EQ(ACCUMULATOR_10, adressing);

    adressing = (adressMask & ROR_A)>>2;
    EXPECT_EQ(ABSOLUTE_10, adressing);

    adressing = (adressMask & ROR_ZX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_10, adressing);

    adressing = (adressMask & ROR_AX)>>2;
    EXPECT_EQ(ABSOLUTE_X_10, adressing);
}

TEST(testSTX, testSTX)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & STX_Z)>>2;
    EXPECT_EQ(ZERO_PAGE_10, adressing);

    adressing = (adressMask & STX_A)>>2;
    EXPECT_EQ(ABSOLUTE_10, adressing);

    adressing = (adressMask & STX_ZY)>>2;
    EXPECT_EQ(ZERO_PAGE_X_10, adressing);

}

TEST(testLDX, testLDX)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & LDX_Z)>>2;
    EXPECT_EQ(ZERO_PAGE_10, adressing);

    adressing = (adressMask & LDX_I)>>2;
    EXPECT_EQ(IMMEDIATE_10, adressing);

    adressing = (adressMask & LDX_A)>>2;
    EXPECT_EQ(ABSOLUTE_10, adressing);

    adressing = (adressMask & LDX_ZY)>>2;
    EXPECT_EQ(ZERO_PAGE_X_10, adressing);

    adressing = (adressMask & LDX_AY)>>2;
    EXPECT_EQ(ABSOLUTE_X_10, adressing);
}

TEST(testDEC, testDEC)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & DEC_Z)>>2;
    EXPECT_EQ(ZERO_PAGE_10, adressing);

    adressing = (adressMask & DEC_A)>>2;
    EXPECT_EQ(ABSOLUTE_10, adressing);

    adressing = (adressMask & DEC_ZX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_10, adressing);

    adressing = (adressMask & DEC_AX)>>2;
    EXPECT_EQ(ABSOLUTE_X_10, adressing);
}

TEST(testINC, testINC)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & INC_Z)>>2;
    EXPECT_EQ(ZERO_PAGE_10, adressing);

    adressing = (adressMask & INC_A)>>2;
    EXPECT_EQ(ABSOLUTE_10, adressing);

    adressing = (adressMask & INC_ZX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_10, adressing);

    adressing = (adressMask & INC_AX)>>2;
    EXPECT_EQ(ABSOLUTE_X_10, adressing);
}

TEST(testBIT, testBIT)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & BIT_Z)>>2;
    EXPECT_EQ(ZERO_PAGE_00, adressing);

    adressing = (adressMask & BIT_A)>>2;
    EXPECT_EQ(ABSOLUTE_00, adressing);
}

TEST(testJMP, testJMP)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & JMP_I)>>2;
    EXPECT_EQ(ABSOLUTE_00, adressing);

    adressing = (adressMask & JMP_A)>>2;
    EXPECT_EQ(ABSOLUTE_00, adressing);
}

TEST(testSTY, testSTY)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & STY_Z)>>2;
    EXPECT_EQ(ZERO_PAGE_00, adressing);

    adressing = (adressMask & STY_A)>>2;
    EXPECT_EQ(ABSOLUTE_00, adressing);

    adressing = (adressMask & STY_ZX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_00, adressing);
}

TEST(testLDY, testLDY)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & LDY_I)>>2;
    EXPECT_EQ(IMMEDIATE_00, adressing);

    adressing = (adressMask & LDY_Z)>>2;
    EXPECT_EQ(ZERO_PAGE_00, adressing);

    adressing = (adressMask & LDY_A)>>2;
    EXPECT_EQ(ABSOLUTE_00, adressing);

    adressing = (adressMask & LDY_ZX)>>2;
    EXPECT_EQ(ZERO_PAGE_X_00, adressing);

    adressing = (adressMask & LDY_AX)>>2;
    EXPECT_EQ(ABSOLUTE_X_00, adressing);
}

TEST(testCPY, testCPY)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & CPY_I)>>2;
    EXPECT_EQ(IMMEDIATE_00, adressing);

    adressing = (adressMask & CPY_Z)>>2;
    EXPECT_EQ(ZERO_PAGE_00, adressing);

    adressing = (adressMask & CPY_A)>>2;
    EXPECT_EQ(ABSOLUTE_00, adressing);
}

TEST(testCPX, testCPX)
{
    Byte adressMask = 0x1C;
    int adressing;

    adressing = (adressMask & CPX_I)>>2;
    EXPECT_EQ(IMMEDIATE_00, adressing);

    adressing = (adressMask & CPX_Z)>>2;
    EXPECT_EQ(ZERO_PAGE_00, adressing);

    adressing = (adressMask & CPX_A)>>2;
    EXPECT_EQ(ABSOLUTE_00, adressing);
}

//--------------------------------------------------------------
//                      SIMPLE OPCODES                          
//--------------------------------------------------------------

/*TEST(testADCsimple, testADCsimple)
{
    Byte adressMask = ~0x1C;
    
    EXPECT_EQ((adressMask & ADC_I), ADC);
    EXPECT_EQ((adressMask & ADC_Z), ADC);
    EXPECT_EQ((adressMask & ADC_ZX), ADC);
    EXPECT_EQ((adressMask & ADC_A), ADC);
    EXPECT_EQ((adressMask & ADC_AX), ADC);
    EXPECT_EQ((adressMask & ADC_AY), ADC);
    EXPECT_EQ((adressMask & ADC_IX), ADC);
    EXPECT_EQ((adressMask & ADC_IY), ADC);
}

TEST(testANDsimple, testANDsimple)
{
    Byte adressMask = ~0x1C;
    
    EXPECT_EQ((adressMask & AND_I), AND);
    EXPECT_EQ((adressMask & AND_Z), AND);
    EXPECT_EQ((adressMask & AND_ZX), AND);
    EXPECT_EQ((adressMask & AND_A), AND);
    EXPECT_EQ((adressMask & AND_AX), AND);
    EXPECT_EQ((adressMask & AND_AY), AND);
    EXPECT_EQ((adressMask & AND_IX), AND);
    EXPECT_EQ((adressMask & AND_IY), AND);
}

TEST(testASLsimple, testASLsimple)
{
    Byte adressMask = ~0x1C;
    
    EXPECT_EQ((adressMask & ASL_Z), ASL);
    EXPECT_EQ((adressMask & ASL_ZX), ASL);
    EXPECT_EQ((adressMask & ASL_A), ASL);
    EXPECT_EQ((adressMask & ASL_AX), ASL);
    EXPECT_EQ((adressMask & ASL_AC), ASL);
}

TEST(testBITsimple, testBITsimple)
{
    Byte adressMask = ~0x1C;
    
    EXPECT_EQ((adressMask & BIT_Z), BIT);
    EXPECT_EQ((adressMask & BIT_A), BIT);
}

TEST(testCMPsimple, testCMPsimple)
{
    Byte adressMask = ~0x1C;
    
    EXPECT_EQ((adressMask & CMP_I), CMP);
    EXPECT_EQ((adressMask & CMP_Z), CMP);
    EXPECT_EQ((adressMask & CMP_ZX), CMP);
    EXPECT_EQ((adressMask & CMP_A), CMP);
    EXPECT_EQ((adressMask & CMP_AX), CMP);
    EXPECT_EQ((adressMask & CMP_AY), CMP);
    EXPECT_EQ((adressMask & CMP_IX), CMP);
    EXPECT_EQ((adressMask & CMP_IY), CMP);
}

TEST(testCPXsimple, testCPXsimple)
{
    Byte adressMask = ~0x1C;
    
    EXPECT_EQ((adressMask & CPX_I), CPX);
    EXPECT_EQ((adressMask & CPX_Z), CPX);
    EXPECT_EQ((adressMask & CPX_A), CPX);
}

TEST(testCPYsimple, testCPYsimple)
{
    Byte adressMask = ~0x1C;
    
    EXPECT_EQ((adressMask & CPY_I), CPY);
    EXPECT_EQ((adressMask & CPY_Z), CPY);
    EXPECT_EQ((adressMask & CPY_A), CPY);
}

TEST(testDECsimple, testDECsimple)
{
    Byte adressMask = ~0x1C;
    
    EXPECT_EQ((adressMask & DEC_Z), DEC);
    EXPECT_EQ((adressMask & DEC_ZX), DEC);
    EXPECT_EQ((adressMask & DEC_A), DEC);
    EXPECT_EQ((adressMask & DEC_AX), DEC);
}

TEST(testEORsimple, testEORsimple)
{
    Byte adressMask = ~0x1C;
    
    EXPECT_EQ((adressMask & EOR_I), EOR);
    EXPECT_EQ((adressMask & EOR_Z), EOR);
    EXPECT_EQ((adressMask & EOR_ZX), EOR);
    EXPECT_EQ((adressMask & EOR_A), EOR);
    EXPECT_EQ((adressMask & EOR_AX), EOR);
    EXPECT_EQ((adressMask & EOR_AY), EOR);
    EXPECT_EQ((adressMask & EOR_IX), EOR);
    EXPECT_EQ((adressMask & EOR_IY), EOR);
}

TEST(testINCsimple, testINCsimple)
{
    Byte adressMask = ~0x1C;
    
    EXPECT_EQ((adressMask & INC_Z), INC);
    EXPECT_EQ((adressMask & INC_ZX), INC);
    EXPECT_EQ((adressMask & INC_A), INC);
    EXPECT_EQ((adressMask & INC_AX), INC);
}

///
/// JMP is an exception -> two opcodes
///TEST(testJMPsimple, testJMPsimple)
///{
///    Byte adressMask = ~0x1C;
///    
///    EXPECT_EQ((adressMask & JMP_I), JMP);
///    EXPECT_EQ((adressMask & JMP_A), JMP);
///}

TEST(testJSRsimple, testJSRsimple)
{
    Byte adressMask = ~0x1C;
    
    EXPECT_EQ((adressMask & JSR_A), JSR);
}

TEST(testLDAsimple, testLDAsimple)
{
    Byte adressMask = ~0x1C;
    
    EXPECT_EQ((adressMask & LDA_I), LDA);
    EXPECT_EQ((adressMask & LDA_Z), LDA);
    EXPECT_EQ((adressMask & LDA_ZX), LDA);
    EXPECT_EQ((adressMask & LDA_A), LDA);
    EXPECT_EQ((adressMask & LDA_AX), LDA);
    EXPECT_EQ((adressMask & LDA_AY), LDA);
    EXPECT_EQ((adressMask & LDA_IX), LDA);
    EXPECT_EQ((adressMask & LDA_IY), LDA);
}

TEST(testLDXsimple, testLDXsimple)
{
    Byte adressMask = ~0x1C;
    
    EXPECT_EQ((adressMask & LDX_I), LDX);
    EXPECT_EQ((adressMask & LDX_Z), LDX);
    EXPECT_EQ((adressMask & LDX_A), LDX);
    EXPECT_EQ((adressMask & LDX_AY), LDX);
    EXPECT_EQ((adressMask & LDX_ZY), LDX);
}

TEST(testLDYsimple, testLDYsimple)
{
    Byte adressMask = ~0x1C;
    
    EXPECT_EQ((adressMask & LDY_I), LDY);
    EXPECT_EQ((adressMask & LDY_Z), LDY);
    EXPECT_EQ((adressMask & LDY_ZX), LDY);
    EXPECT_EQ((adressMask & LDY_A), LDY);
    EXPECT_EQ((adressMask & LDY_AX), LDY);
}

TEST(testLSRsimple, testLSRsimple)
{
    Byte adressMask = ~0x1C;
    
    EXPECT_EQ((adressMask & LSR_Z), LSR);
    EXPECT_EQ((adressMask & LSR_ZX), LSR);
    EXPECT_EQ((adressMask & LSR_A), LSR);
    EXPECT_EQ((adressMask & LSR_AX), LSR);
    EXPECT_EQ((adressMask & LSR_AC), LSR);
}

TEST(testORAsimple, testORAsimple)
{
    Byte adressMask = ~0x1C;
    
    EXPECT_EQ((adressMask & ORA_I), ORA);
    EXPECT_EQ((adressMask & ORA_Z), ORA);
    EXPECT_EQ((adressMask & ORA_ZX), ORA);
    EXPECT_EQ((adressMask & ORA_A), ORA);
    EXPECT_EQ((adressMask & ORA_AX), ORA);
    EXPECT_EQ((adressMask & ORA_AY), ORA);
    EXPECT_EQ((adressMask & ORA_IX), ORA);
    EXPECT_EQ((adressMask & ORA_IY), ORA);
}

TEST(testROLsimple, testROLsimple)
{
    Byte adressMask = ~0x1C;
    
    EXPECT_EQ((adressMask & ROL_Z), ROL);
    EXPECT_EQ((adressMask & ROL_ZX), ROL);
    EXPECT_EQ((adressMask & ROL_A), ROL);
    EXPECT_EQ((adressMask & ROL_AX), ROL);
    EXPECT_EQ((adressMask & ROL_AC), ROL);
}

TEST(testRORsimple, testRORsimple)
{
    Byte adressMask = ~0x1C;
    
    EXPECT_EQ((adressMask & ROR_Z), ROR);
    EXPECT_EQ((adressMask & ROR_ZX), ROR);
    EXPECT_EQ((adressMask & ROR_A), ROR);
    EXPECT_EQ((adressMask & ROR_AX), ROR);
    EXPECT_EQ((adressMask & ROR_AC), ROR);
}

TEST(testSBCsimple, testSBCsimple)
{
    Byte adressMask = ~0x1C;
    
    EXPECT_EQ((adressMask & SBC_I), SBC);
    EXPECT_EQ((adressMask & SBC_Z), SBC);
    EXPECT_EQ((adressMask & SBC_ZX), SBC);
    EXPECT_EQ((adressMask & SBC_A), SBC);
    EXPECT_EQ((adressMask & SBC_AX), SBC);
    EXPECT_EQ((adressMask & SBC_AY), SBC);
    EXPECT_EQ((adressMask & SBC_IX), SBC);
    EXPECT_EQ((adressMask & SBC_IY), SBC);
}

TEST(testSTAsimple, testSTAsimple)
{
    Byte adressMask = ~0x1C;
    
    EXPECT_EQ((adressMask & STA_Z), STA);
    EXPECT_EQ((adressMask & STA_ZX), STA);
    EXPECT_EQ((adressMask & STA_A), STA);
    EXPECT_EQ((adressMask & STA_AX), STA);
    EXPECT_EQ((adressMask & STA_AY), STA);
    EXPECT_EQ((adressMask & STA_IX), STA);
    EXPECT_EQ((adressMask & STA_IY), STA);
}

TEST(testSTXsimple, testSTXsimple)
{
    Byte adressMask = ~0x1C;
    
    EXPECT_EQ((adressMask & STX_Z), STX);
    EXPECT_EQ((adressMask & STX_A), STX);
    EXPECT_EQ((adressMask & STX_ZY), STX);
}

TEST(testSTYsimple, testSTYsimple)
{
    Byte adressMask = ~0x1C;
    
    EXPECT_EQ((adressMask & STY_Z), STY);
    EXPECT_EQ((adressMask & STY_ZX), STY);
    EXPECT_EQ((adressMask & STY_A), STY);
}*/