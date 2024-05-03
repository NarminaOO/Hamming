#include "gtest/gtest.h"
#include "DecodeH.cpp" 

TEST(HammingDecodingTest, Test1) 
{
    short packet = 0b0001010111000111; 
    testing::internal::CaptureStdout();
    decodeHamming(packet);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Packet accepted.\nPacket accepted.\nDecoded integer value: 9\n");
}


TEST(HammingDecodingTest, Test2) {
    short packet = 0b0001010111011111; 
    testing::internal::CaptureStdout();
    decodeHamming(packet);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Packet accepted.\nUnknown error condition.\n");
}



int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
