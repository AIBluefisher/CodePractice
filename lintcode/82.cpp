// ID: 82

// Description:
// Given 2*n + 1 numbers, every numbers occurs twice except one, find it.

// Example
// Given [1,2,2,1,3,4,3], return 4

// Challenge
// One-pass, constant extra space.

// Solution:
// a ^ b ^ a = a ^ a ^ b = 0 ^ b = b
class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumber(vector<int> &A) {
        int ans = 0;
        for(auto num : A) ans ^= num;
        return ans;
    }
};