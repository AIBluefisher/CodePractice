// ID: 46

// Description:
// Given a collection of distinct integers, return all possible permutations.

// Example:

// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

// Solution:

// 1. dfs with backtrack
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        vector<bool> visited(nums.size(), false);
        vector<int> result;
        dfs(nums, results, result, visited);
        return results;
    }
    
    void dfs(vector<int> nums, vector<vector<int>>& results, vector<int>& result, vector<bool>& visited) {
        if(result.size() == nums.size()) {
            results.push_back(result);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(!visited[i]) {
                visited[i] = true;
                result.push_back(nums[i]);
                dfs(nums, results, result, visited);
                result.pop_back();
                visited[i] = false;
            }
        }
    }
};

//2. next_permutation
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        sort(nums.begin(), nums.end());
        do {
            results.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        return results;
    }
};