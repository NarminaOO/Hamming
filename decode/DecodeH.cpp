
#include <iostream>
#include <bitset>

int processHamming(int data)
{
    std::bitset<8> bits(data);
    bool b1 = bits[0], b2 = bits[1], b3 = bits[2], b4 = bits[3];
    bool b5 = bits[4], b6 = bits[5], b7 = bits[6], b8 = bits[7];

    bool A = (b1 + b2 + b6 + b8) % 2 == 1;
    bool B = (b2 + b3 + b4 + b8) % 2 == 1;
    bool C = (b2 + b4 + b5 + b6) % 2 == 1;
    bool D = (b1 + b2 + b3 + b4 + b5 + b6 + b7 + b8) % 2 == 1;

    if (A && B && C && D) {
        std::cout << "Packet accepted.\n";
    }
    else if (A && B && C && !D) {
        std::cout << "Error in p4, but packet accepted.\n";
    }
    else if ((!A || !B || !C) && !D) {
        std::cout << "Single Error\n";
        if (!A && B && C) bits.flip(0);
        if (!A && !B && !C) bits.flip(1);
        if (A && !B && C) bits.flip(2);
        if (A && !B && !C) bits.flip(3);
        if (A && B && !C) bits.flip(4);
        if (!A && B && !C) bits.flip(5);
        if (!A && !B && !C) bits.flip(6);
        if (!A && !B && C) bits.flip(7);
    }
    else if (!A && !B && !C && D) {
        std::cout << "Double error, rejecting packet.\n";
        return -1;
    }
    else {
        std::cout << "Unknown error condition.\n";
        return -1;
    }

    int correctedData = 0;
    correctedData |= b2;
    correctedData |= b4 << 1;
    correctedData |= b6 << 2;
    correctedData |= b8 << 3;

    return correctedData;
}

void decodeHamming(short packet) {
    int firstPart = packet >> 8;
    int secondPart = packet & 0xFF;

    int decodedFirst = processHamming(firstPart);
    int decodedSecond = processHamming(secondPart);

    if (decodedFirst != -1 && decodedSecond != -1) {
        int result = decodedFirst * 16 + decodedSecond;
        std::cout << "Decoded integer value: " << result << std::endl;
    }
}

//int main()
//{
//    short packet = 0b0001010111000111;
//    decodeHamming(packet);
//}
//
