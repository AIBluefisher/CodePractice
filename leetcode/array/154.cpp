// ID: 154

// Description:
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

// Find the minimum element.

// The array may contain duplicates.

// Example 1:

// Input: [1,3,5]
// Output: 1
// Example 2:

// Input: [2,2,2,0,1]
// Output: 0
// Note:

// This is a follow up problem to Find Minimum in Rotated Sorted Array.
// Would allow duplicates affect the run-time complexity? How and why?

// Solution:
class Solution {
public:
    int findMin(vector<int>& nums) {
        for(int i = 0; i + 1 < nums.size(); i++) {
            if(nums[i] > nums[i + 1])
                return nums[i + 1];
        }
        return nums[0];
    }
};