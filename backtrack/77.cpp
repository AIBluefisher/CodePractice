// ID: 77

// Description:
// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// Example:

// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

// Solution:
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> results;
        vector<int> result;
        dfs(results, result, n, k, 0);
        return results;
    }
    
    void dfs(vector<vector<int>>& results, vector<int> result, int n, int k, int d) {
        if(result.size() == k) {
            results.push_back(result);
            return;
        }
        for(int i = d; i < n; i++) {
            result.push_back(i + 1);
            dfs(results, result, n, k, i + 1);
            result.pop_back();
        }
    }
};