#include <gtest/gtest.h> 
#include "EncodeH.cpp"
#include <bitset>
TEST(EncodeHammingTest, CorrectEncoding)
{
    // Test values
    int value1 = 9;
    int value2 = 5;
    int value3 = 15;
    std::bitset<16> expected1("0001010111000111");
    std::bitset<16> expected2("0001010101110011");
    std::bitset<16> expected3("0001010111101010");

    
    std::bitset<16> encodedbits1 = encodehamming(value1);
    std::bitset<16> encodedbits2 = encodehamming(value2);
    std::bitset<16> encodedbits3 = encodehamming(value3);

    
    EXPECT_EQ(encodedbits1, expected1);
    EXPECT_EQ(encodedbits2, expected2);
    EXPECT_EQ(encodedbits3, expected3);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
