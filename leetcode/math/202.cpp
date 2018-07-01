// ID 202.cpp

// Description:
// Write an algorithm to determine if a number is "happy".

// A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

// Example: 

// Input: 19
// Output: true
// Explanation: 
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1

// Solution:
class Solution {
public:
    bool isHappy(int n) {
        int max_iter = 10;
        while(true && max_iter--) {
            string str = to_string(n);
            int sum = 0;
            for(auto s : str) {
                sum += (s - '0') * (s - '0');
            }
            n = sum;
            if(n == 1) return true;
        }
        return false;
    }
};