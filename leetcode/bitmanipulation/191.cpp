// ID: 191

// Description:
// Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
// Example 1:

// Input: 11
// Output: 3
// Explanation: Integer 11 has binary representation 00000000000000000000000000001011 
// Example 2:

// Input: 128
// Output: 1
// Explanation: Integer 128 has binary representation 00000000000000000000000010000000

// Solution: 
// Brian Kernighan Approach
// For bit manipulation, every time we minus 1, we eliminate the 1 at the lowest bit.
// Then the elimination times is just the number of 1s.

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};

