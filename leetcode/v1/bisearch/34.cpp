// ID: 34

// Description:
// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

// Solution: binary search
// ## 1. inplemented with binary search
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return vector<int>(2, -1);
        int lb = -1, ub = nums.size() - 1;
        while(ub - lb > 1) {
            int mid = (lb + ub) / 2;
            if(nums[mid] >= target) ub = mid;
            else lb = mid;
        }
        if(nums[ub] != target) return vector<int>(2, -1);
        vector<int> results(2, -1);
        for(int i = ub; i < nums.size(); i++) {
            if(nums[i] != target) {
                results[1] = i - 1;
                break;
            }
            else results[1] = i;
        }
        for(int j = ub; j >= 0; j--) {
            if(nums[j] != target) {
                results[0] = j + 1;
                break;
            }
            else results[0] = j;
        }
        return results;
    }
};

// ## 2. implemented with STL's lower_bound & upper_bound
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lower_bound(nums.cbegin(), nums.cend(), target) - nums.begin();
        int ub = upper_bound(nums.cbegin(), nums.cend(), target) - nums.begin();
        if(lb == ub) return {-1, -1};
        else return {lb, ub - 1};
    }
};