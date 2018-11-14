// ID: 136
// Description:
// Given a non-empty array of integers, every element appears twice except for one. Find that single one.

// Note:

// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

// Example 1:

// Input: [2,2,1]
// Output: 1
// Example 2:

// Input: [4,1,2,1,2]
// Output: 4

// Solution:

// 1. bit manipulation
// a ^ b ^ a = a ^ a ^ b = 0 ^ b = b
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto num : nums) {
            ans ^= num;
        }
        return ans;
    }
};

// 2. common aproach
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> norepeat;
        for(auto num : nums) {
            if(norepeat.find(num) == norepeat.end()) norepeat.insert(num);
            else norepeat.erase(num);
        }
        return *(norepeat.begin());
    }
};