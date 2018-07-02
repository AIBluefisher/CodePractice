// ID: 39

// Description:
// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

// The same repeated number may be chosen from candidates unlimited number of times.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
// Example 2:

// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]


// Solution:

// 1. backtrack
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> result;
        sort(candidates.begin(), candidates.end());
        backtrack(results, result, candidates, target, 0);
        return results;
    }
    
    void backtrack(vector<vector<int>>& results, vector<int> result, vector<int> candidates, int target, int d) {
        if(target == 0) {
            results.push_back(result);
            return;
        }
        if(target < 0) return;
        for(int i = d; i < candidates.size(); i++) {
            result.push_back(candidates[i]);
            backtrack(results, result, candidates, target - candidates[i], i);
            result.pop_back();
        }
    }
};