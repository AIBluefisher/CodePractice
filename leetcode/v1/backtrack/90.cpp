// ID: 90

// Description:
// Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// Example:

// Input: [1,2,2]
// Output:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

// Solution:
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> result;
        dfs(nums, results, result, 0);
        sort(results.begin(), results.end());
        results.erase(unique(results.begin(), results.end()), results.end());
        return results;
    }
    
    void dfs(vector<int> nums, vector<vector<int>>& results, vector<int> result, int level) {
        sort(result.begin(), result.end());
        results.push_back(result);
        for(int i = level; i < nums.size(); i++) {
            result.push_back(nums[i]);
            dfs(nums, results, result, i + 1);
            result.pop_back();
        }
    }
};