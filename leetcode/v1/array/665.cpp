// ID: 665

// Description:
// Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

// We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

// Example 1:
// Input: [4,2,3]
// Output: True
// Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
// Example 2:
// Input: [4,2,1]
// Output: False
// Explanation: You can't get a non-decreasing array by modify at most one element.
// Note: The n belongs to [1, 10,000].

// Solution:
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int decre_num = 0;
        int decre_index = -1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] > nums[i]) {
                decre_index = i - 1;
                decre_num++;
            }
            if(decre_num > 1) return false; 
        }
        if(decre_num == 0) return true;
        
        if(decre_index == 0 || 
           decre_index == nums.size() - 2 ||
           nums[decre_index - 1] <= nums[decre_index + 1] || 
           nums[decre_index] <= nums[decre_index + 2] ) return true;
        return false;
    }
};