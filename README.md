## Hamming 8-4
These two folders (encode, decode) contain codes for encoding and decoding data using the Hamming 8/4 code.
Hamming 8/4 code is a specific type of Hamming code used for error correction in binary data. 

In Hamming 8/4 code, four data bits are encoded into an eight-bit message, which includes four data bits and four parity bits.
Input data is divided into blocks of 4 bits. Four parity bits are added to each block, creating an eight-bit message. The parity bits are calculated in such a way that they represent the parity (evenness) of certain bits in the message. 
The resulting eight-bit message is then transmitted or stored. When receiving the message, the parity bits are checked. If they do not match the data, it indicates an error, and the error can be corrected. 
This code is capable of detecting two errors and correcting one error in each eight-bit word. However, if more than two errors are detected, the code will not be able to correct them.

### 
