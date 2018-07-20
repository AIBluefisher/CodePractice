// ID: 238

// Description:
// Given an array nums of n integers where n > 1,
// return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

// Example:

// Input:  [1,2,3,4]
// Output: [24,12,8,6]
// Note: Please solve it without division and in O(n).

// Follow up:
// Could you solve it with constant space complexity?
// (The output array does not count as extra space for the purpose of space complexity analysis.)

// Solution:
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int pre = 1, post = 1;
        for(int start = 0, end = nums.size() - 1; start < nums.size(); start++, end--) {
            ans[start] *= pre;
            ans[end] *= post;
            pre *= nums[start];
            post *= nums[end];
        }
        return ans;
    }
};