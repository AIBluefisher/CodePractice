// ID: 190

// Description:
// Reverse bits of a given 32 bits unsigned integer.

// Example:

// Input: 43261596
// Output: 964176192
// Explanation: 43261596 represented in binary as 00000010100101000001111010011100, 
//              return 964176192 represented in binary as 00111001011110000010100101000000.

// Solution:
// we first extract every bit from n, then add them together from the lowest bit.
// To extract every bit from n, we can use (n >> i) & 1.

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> bits;
        for(int i = 0; i < 32; i++) {
            bits.push_back((n >> i) & 1);
        }
        uint32_t ans = 0;
        for(int i = 31; i >= 0; i--) {
            ans += bits[31 - i] * pow(2, i);
        }
        return ans;
    }
};

