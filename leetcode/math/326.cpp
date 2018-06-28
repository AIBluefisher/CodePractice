// ID: 326

// Description:
// Given an integer, write a function to determine if it is a power of three.

// Example 1:

// Input: 27
// Output: true
// Example 2:

// Input: 0
// Output: false
// Example 3:

// Input: 9
// Output: true
// Example 4:

// Input: 45
// Output: false
// Follow up:
// Could you do it without using any loop / recursion?

// Solution:

// 1. loop
class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n % 3 == 0 && n > 0) {
            n /= 3;
        }
        return n == 1;
    }
};

// 2. 
// max(3^n) % 3 == 0
// max(3^n) = 3^19  = 1162261467
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && (1162261467 % n == 0);
    }
};