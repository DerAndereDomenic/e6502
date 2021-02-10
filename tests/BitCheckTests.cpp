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