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