// ID: 367
// Description:
// Given a positive integer num, write a function which returns True if num is a perfect square else False.

// Note: Do not use any built-in library function such as sqrt.

// Example 1:

// Input: 16
// Returns: True
// Example 2:

// Input: 14
// Returns: False
// Credits:
// Special thanks to @elmirap for adding this problem and creating all test cases.

// Solution:
// the type of i should be long long int to avoid overflow
class Solution {
public:
    bool isPerfectSquare(int num) {
        for(long long i = 2; i * i <= num; i++) {
            if(i * i == num) return true;
        }
        return (num < 2) ? num : false;
    }
};