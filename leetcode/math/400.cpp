// ID: 400

// Description:
// Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

// Note:
// n is positive and will fit within the range of a 32-bit signed integer (n < 231).

// Example 1:

// Input:
// 3

// Output:
// 3
// Example 2:

// Input:
// 11

// Output:
// 0

// Explanation:
// The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.

// Solution:
// Reference hints: 
// https://leetcode.com/problems/nth-digit/discuss/88369/0ms-C++-Solution-with-Detail-Explanation
class Solution {
public:
    int findNthDigit(int n) {
        long long int base = 9, digits = 1;
        while(n - base * digits > 0) {
            n -= base * digits;
            base *= 10;
            digits++;
        }
        
        int index = n % digits;
        long long int num = 1;
        for(int i = 1; i < digits; i++) num *= 10;
        
        num += (index == 0) ? n / digits - 1 : n / digits;
        string str = to_string(num);
        return index == 0 ? str[digits - 1] - '0' : str[n % digits - 1] - '0';
    }
};