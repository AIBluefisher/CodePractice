// ID: 40

// Description:
// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

// Each number in candidates may only be used once in the combination.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]

// Solution:

// 1. backtrack
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> result;
        sort(candidates.begin(), candidates.end());
        backtrack(results, result, candidates, target, 0);
        sort(results.begin(), results.end());
        results.erase(unique(results.begin(), results.end()), results.end());
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
            backtrack(results, result, candidates, target - candidates[i], i + 1);
            result.pop_back();
        }
    }
};