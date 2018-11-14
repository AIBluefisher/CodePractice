// ID: 29

// Description:
// Given two integers dividend and divisor, divide two integers without using multiplication, 
// division and mod operator.

// Return the quotient after dividing dividend by divisor.

// The integer division should truncate toward zero.

// Example 1:

// Input: dividend = 10, divisor = 3
// Output: 3
// Example 2:

// Input: dividend = 7, divisor = -3
// Output: -2
// Note:

// Both dividend and divisor will be 32-bit signed integers.
// The divisor will never be 0.
// Assume we are dealing with an environment which could only store integers 
// within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, 
// assume that your function returns 231 − 1 when the division result overflows.

// Solution:
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ans = 0;
        long long abs_dividend = fabs(dividend);
        long long abs_divisor = fabs(divisor);
        
        while(abs_dividend >= abs_divisor) {
            long long tmp = abs_divisor, power = 1;
            while(abs_dividend >= (tmp << 1)) {
                tmp <<= 1;
                power <<= 1;
            }
            ans += power;
            abs_dividend -= tmp;
        }
        if((dividend > 0) ^ (divisor > 0)) ans = -ans;
        return (ans < INT_MIN || ans > INT_MAX) ? INT_MAX : ans;
    }
};