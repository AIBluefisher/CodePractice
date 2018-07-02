// ID: 219

// Description:
// Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

// Example 1:

// Input: nums = [1,2,3,1], k = 3
// Output: true
// Example 2:

// Input: nums = [1,0,1,1], k = 1
// Output: true
// Example 3:

// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false

// Solution:
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> nums_map;
        int min_dist = 0x7fffffff;
        for(int i = 0; i < nums.size(); i++) {
            if(nums_map.find(nums[i]) != nums_map.end())
                min_dist = min(min_dist, i - nums_map[nums[i]]);
            nums_map[nums[i]] = i;
        }
        return min_dist <= k;
    }
};