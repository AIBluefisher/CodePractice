// ID: 78

// Description:
// Given a set of distinct integers, nums, return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// Example:

// Input: nums = [1,2,3]
// Output:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

// Solution:
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> result;
        dfs(nums, results, result, 0);
        return results;
    }
    
    void dfs(vector<int> nums, vector<vector<int>>& results, vector<int> result, int level) {
        results.push_back(result);
        for(int i = level; i < nums.size(); i++) {
            result.push_back(nums[i]);
            dfs(nums, results, result, i + 1);
            result.pop_back();
        }
    }
};