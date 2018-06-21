// ID: 371

// Description:
// Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

// Example:
// Given a = 1 and b = 2, return 3.

// Solution:
// For addition of 1 bit, we can follow:
// 0 + 0 = 00
// 0 + 1 = 01
// 1 + 0 = 01
// 1 + 1 = 10
// Set x0 = a ^ b, c0 = (a & b) << 1, then we can find that s0 = x0 + c0.
// We can extend to n bits addition, that is sn = x0 + c0  = x1 + c1 = ... = xn + cn
// Which means, after n + 1 times of addition, cn are composed of all 0s, and xn = sn
// This can be implemented by recurse.
class Solution {
public:
    int getSum(int a, int b) {
        return b == 0 ? a : getSum(a ^ b, (a & b) << 1);
    }
};