## Hamming 8-4 
These two folders (encode, decode) contain codes for encoding and decoding data using the Hamming 8/4 code.
Hamming 8/4 code is a specific type of Hamming code used for error correction in binary data. 

In Hamming 8/4 code, four data bits are encoded into an eight-bit message, which includes four data bits and four parity bits.
Input data is divided into blocks of 4 bits. Four parity bits are added to each block, creating an eight-bit message. The parity bits are calculated in such a way that they represent the parity (evenness) of certain bits in the message. 
The resulting eight-bit message is then transmitted or stored. When receiving the message, the parity bits are checked. If they do not match the data, it indicates an error, and the error can be corrected. 
This code is capable of detecting two errors and correcting one error in each eight-bit word. However, if more than two errors are detected, the code will not be able to correct them.

### DecodeH.cpp
The `processHamming` function:

1. It takes an integer `data` as input, which represents an eight-bit packet.
2. The eight bits of the packet are extracted and stored in boolean variables b1 through b8.
3. Parity checks are performed on specific combinations of these bits (A, B, C, and D). These checks verify whether certain combinations of bits have even parity (i.e., an even number of set bits).
4. Based on the results of the parity checks, different error conditions are identified:
- If all parity checks pass (A, B, C, and D are all true), the packet is accepted.
- If only the D check fails, indicating an error in the parity bit itself, the packet is still accepted but with a notification of the error.
- If there's a single error (A, B, or C fails, but D is true), the function attempts to correct it by flipping the corresponding bit in the bits bitset.
- If all data bits are incorrect (A, B, C are all false, and D is true), indicating a double error, the packet is rejected.
- If none of the above conditions are met, an unknown error condition is reported.
- If the packet passes all error checks or if a single error is corrected, the corrected data is extracted from the bits bitset and returned as an integer.
  
The `decodeHamming` function:

1. It takes a short integer `packet` as input, representing a 16-bit encoded message consisting of two eight-bit packets.
2. The packet is split into two eight-bit parts (`firstPart` and `secondPart`).
3. Each part is decoded separately using the `processHamming` function.
4. If both parts are successfully decoded (i.e., not equal to -1), the decoded data is combined to reconstruct the original integer value, which is then printed out.

### EncodeH.cpp
`hamming` function:
1. This function takes a 4-bit input (`bits`) represented as a `std::bitset<4>`.
2. It calculates the parity bits (p1, p2, p3, p4) based on the input bits (d1, d2, d3, d4).
3. The parity bits are computed such that each covers a specific combination of data bits and itself.
4. The result is stored in a `std::bitset<8>`, with parity bits positioned at even indices (0, 2, 4, 6) and data bits at odd indices (1, 3, 5, 7).
5. The resulting `bitset` is returned.

`encodehamming` function:
1. This function takes an integer c as input, representing an 8-bit data.
2. The input integer c is converted into a `std::bitset<8>` called `bits`.
3. The input c is split into two parts: `firstpart` and `secondpart`, each containing 4 bits.
4. Each part is passed to the `hamming` function for encoding. The result is converted back to `ulong` and shifted to the appropriate position (<< 8 for the first part and no shift for the second part).
5. The two encoded parts are then combined using bitwise OR (|) to form a 16-bit `bitset`.
6. The resulting `bitset` representing the encoded data is returned.
