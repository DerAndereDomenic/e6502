#include <gtest/gtest.h>
#include <Processor/ProcessorStatus.h>

using namespace E6502;

TEST(zeroFlagZero, zeroFlagZero)
{
    ProcessorStatus status;
    Byte byte = 0;
    status.checkZero(byte);

    EXPECT_EQ(status.Z, 1);
}

TEST(zeroFlagPositive, zeroFlagPositive)
{
    ProcessorStatus status;
    Byte byte = 10;
    status.checkZero(byte);

    EXPECT_EQ(status.Z, 0);
}

TEST(zeroFlagNegative, zeroFlagNegative)
{
    ProcessorStatus status;
    Byte byte = -10;
    status.checkZero(byte);

    EXPECT_EQ(status.Z, 0);
}

TEST(negativeFlagPositive, negativeFlagPositive)
{
    ProcessorStatus status;
    Byte byte = 10;
    status.checkNegative(byte);

    EXPECT_EQ(status.N,0);
}

TEST(negativeFlagNegative, negativeFlagNegative)
{
    ProcessorStatus status;
    Byte byte = -10;
    status.checkNegative(byte);

    EXPECT_EQ(status.N,1);
}

TEST(negativeFlagZero, negativeFlagZero)
{
    ProcessorStatus status;
    Byte byte = 0;
    status.checkNegative(byte);

    EXPECT_EQ(status.N,0);
}

TEST(negativeFlagOverflow, negativeFlagOverflow)
{
    ProcessorStatus status;
    Byte byte = 128;
    status.checkNegative(byte);

    EXPECT_EQ(status.N,1);
}

TEST(negativeFlagUnderflow, negativeFlagUnderflow)
{
    ProcessorStatus status;
    int16_t byte = -129;    //Trick compiler to not display overflow warning
    status.checkNegative(static_cast<uint8_t>(byte));

    EXPECT_EQ(status.N,0);
}

TEST(carryFlag2Postive, carryFalg2Positive)
{
    ProcessorStatus status;
    Byte b1 = 10;
    Byte b2 = 20;

    Word result = static_cast<Word>(b1) + static_cast<Word>(b2);
    status.checkCarry(result);

    EXPECT_EQ(status.C,0);
}

TEST(carryFlag2Negative, carryFalg2Negative)
{
    ProcessorStatus status;
    Byte b1 = -10;
    Byte b2 = -20;

    //First convert to signed byte and then extend to 16 bits
    int16_t result = static_cast<int16_t>(b1) + static_cast<int16_t>(b2);
    status.checkCarry(result);

    EXPECT_EQ(status.C,1);
}

TEST(carryFlagPosNeg, carryFlagPosNeg)
{
    ProcessorStatus status;
    Byte b1 = 10;
    Byte b2 = -20;

    //First convert to signed byte and then extend to 16 bits
    int16_t result = static_cast<int16_t>(b1) + static_cast<int16_t>(b2);
    status.checkCarry(result);

    EXPECT_EQ(status.C,0);
}

TEST(carryFlagNegPos, carryFlagNegPos)
{
    ProcessorStatus status;
    Byte b1 = -10;
    Byte b2 = 20;

    //First convert to signed byte and then extend to 16 bits
    int16_t result = static_cast<int16_t>(b1) + static_cast<int16_t>(b2);
    status.checkCarry(result);

    EXPECT_EQ(status.C,1);
}

TEST(carryFlagOneOne, carryFlagOneOne)
{
    ProcessorStatus status;
    Byte b1 = 1;
    Byte b2 = 1;

    int16_t result = static_cast<int16_t>(b1) + static_cast<int16_t>(b2);
    status.checkCarry(result);
    EXPECT_EQ(status.C, 0);
}

TEST(carryFlagOneNegOne, carryFlagOneNegOne)
{
    ProcessorStatus status;
    Byte b1 = 1;
    Byte b2 = -1;

    int16_t result = static_cast<int16_t>(b1) + static_cast<int16_t>(b2);
    status.checkCarry(result);
    EXPECT_EQ(status.C, 1);
}

TEST(carryFlag127One, carryFlag127One)
{
    ProcessorStatus status;
    Byte b1 = 127;
    Byte b2 = 1;

    int16_t result = static_cast<int16_t>(b1) + static_cast<int16_t>(b2);
    status.checkCarry(result);
    EXPECT_EQ(status.C, 0);
}

TEST(carryFlagNeg127NegOne, carryFlagNeg127NegOne)
{
    ProcessorStatus status;
    Byte b1 = -127;
    Byte b2 = -1;
    int16_t result = static_cast<int16_t>(b1) + static_cast<int16_t>(b2);
    status.checkCarry(result);
    EXPECT_EQ(status.C, 1);
}

TEST(overflowFlagOneOne, overflowFlagOneOne)
{
    ProcessorStatus status;
    Byte b1 = 1;
    Byte b2 = 1;
    status.checkOverflow(b1,b2);
    EXPECT_EQ(status.V, 0);
}

TEST(overflowFlagOneNegOne, overflowFlagOneNegOne)
{
    ProcessorStatus status;
    Byte b1 = 1;
    Byte b2 = -1;
    status.checkOverflow(b1,b2);
    EXPECT_EQ(status.V, 0);
}

TEST(overflowFlag127One, overflowFlag127One)
{
    ProcessorStatus status;
    Byte b1 = 127;
    Byte b2 = 1;
    status.checkOverflow(b1,b2);
    EXPECT_EQ(status.V, 1);
}

TEST(overflowFlagNeg128NegOne, overflowFlagNeg128NegOne)
{
    ProcessorStatus status;
    Byte b1 = -128;
    Byte b2 = -1;
    status.checkOverflow(b1,b2);
    EXPECT_EQ(status.V, 1);
}

TEST(overflowFlagZeroNegOne, overflowFlagZeroNegOne)
{
    ProcessorStatus status;
    Byte b1 = 0;
    Byte b2 = -1;
    status.checkOverflow(b1,b2);
    EXPECT_EQ(status.V, 0);
}

TEST(overflowFlag2Postive, overflowFlag2Postive)
{
    ProcessorStatus status;
    Byte b1 = 10;
    Byte b2 = 20;

    status.checkOverflow(b1,b2);

    EXPECT_EQ(status.V,0);
}

TEST(overflowFlag2Negative, overflowFlag2Negative)
{
    ProcessorStatus status;
    Byte b1 = -10;
    Byte b2 = -20;

    status.checkOverflow(b1,b2);

    EXPECT_EQ(status.V,0);
}

TEST(overflowFlagPosNeg, overflowFlagPosNeg)
{
    ProcessorStatus status;
    Byte b1 = 10;
    Byte b2 = -20;
    status.checkOverflow(b1,b2);

    EXPECT_EQ(status.V,0);
}

TEST(overflowFlagNegPos, overflowFlagNegPos)
{
    ProcessorStatus status;
    Byte b1 = -10;
    Byte b2 = 20;

    status.checkOverflow(b1,b2);

    EXPECT_EQ(status.V,0);
}