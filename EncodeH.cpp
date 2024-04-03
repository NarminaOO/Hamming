#include <iostream>
#include <bitset>

std::bitset<8> hamming(std::bitset<4> bits)
{
    bool d1 = bits[0];
    bool d2 = bits[1];
    bool d3 = bits[2];
    bool d4 = bits[3];

    bool p1 = (d1 + d3 + d4 + 1) % 2;
    bool p2 = (d1 + d2 + d4 + 1) % 2;
    bool p3 = (d1 + d2 + d3 + 1) % 2;
    bool p4 = (d1 + d2 + d3 + d4 + p2 + p1 + p3 + 1) % 2;

    std::bitset<8> res;
    res[0] = p1;
    res[1] = d1;
    res[2] = p2;
    res[3] = d2;
    res[4] = p3;
    res[5] = d3;
    res[6] = p4;
    res[7] = d4;

    return res;

}


std::bitset<16> encodehamming(int c)
{

    std::bitset<8> bits(c);


    char firstpart = (c & 0xf0) >> 4;
    char secondpart = c & 0x0f;

    return (hamming(std::bitset<4>(firstpart)).to_ulong() << 8) | hamming(std::bitset<4>(secondpart)).to_ulong();
}



//int main()
//{
//    int value = 15;
//    std::bitset<8> originalbits(value);
//
//    std::bitset<16> encodedbits = encodehamming(value);
//
//
//    std::cout << "original: " << value << " = " << originalbits << std::endl;
//    std::cout << "encoded: " << encodedbits << std::endl;
//
//    return 0;
//}
/////////////////////////////
//
//original: 9 = 00001001
//encoded : 0001010111000111

//5 = 00000101 Encoded: 0001010101110011
//5 = 00000101 Encoded: 01110011
//15 = 00001111 Encoded: 0001010111101010