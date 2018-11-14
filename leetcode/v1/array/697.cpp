// ID: 697

// Description:
// Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum 
// frequency of any one of its elements.

// Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

// Example 1:
// Input: [1, 2, 2, 3, 1]
// Output: 2
// Explanation: 
// The input array has a degree of 2 because both elements 1 and 2 appear twice.
// Of the subarrays that have the same degree:
// [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
// The shortest length is 2. So return 2.
// Example 2:
// Input: [1,2,2,3,1,4,2]
// Output: 6
// Note:

// nums.length will be between 1 and 50,000.
// nums[i] will be an integer between 0 and 49,999.

// Solution:
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> nums_map;
        for(int i = 0; i < nums.size(); i++) {
            nums_map[nums[i]].push_back(i);
        }
        
        int max_frequency = 0, min_len = INT_MAX;
        for(auto it = nums_map.begin(); it != nums_map.end(); it++) {
            vector<int> vec_index = it->second;
            int frequency = vec_index.size();
            int len = abs(vec_index[frequency - 1] - vec_index[0]) + 1;
            if((max_frequency < frequency) || 
              (max_frequency == frequency && min_len > len)) {
                max_frequency = frequency;
                min_len = len;
            }
        }
        return min_len;
    }
};