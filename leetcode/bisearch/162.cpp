// ID: 162

// Description:


// Solution:

// 1. max_element
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return max_element(nums.begin(), nums.end()) - nums.begin();
    }
};
// 2. binary search
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lb = 0, ub = nums.size() - 1;
        while(lb < ub) {
            int mid = (lb + ub) / 2;
            if(nums[mid] > nums[mid + 1]) ub = mid;
            else lb = mid + 1;
        }
        return lb;
    }
};