// ID: 153

// Description:
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

// Find the minimum element.

// You may assume no duplicate exists in the array.

// Example 1:

// Input: [3,4,5,1,2] 
// Output: 1
// Example 2:

// Input: [4,5,6,7,0,1,2]
// Output: 0

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
