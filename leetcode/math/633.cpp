// ID: 633

// Description:
// Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.
//
// Example 1:
// Input: 5
// Output: True
// Explanation: 1 * 1 + 2 * 2 = 5
// Example 2:
// Input: 3
// Output: False

// Solution:
class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long i = 0; i * i <= c; i++) {
            double a = sqrt(c - i * i);
            if(a == (int)a) return true;
        }
        return  false;
    }
};
