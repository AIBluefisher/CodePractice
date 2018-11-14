// ID: 47

// Description:
// Given a collection of numbers that might contain duplicates, return all possible unique permutations.

// Example:

// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]

// Solution:

// 1. next_permutation
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        do {
            results.push_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));
        return results;
    }
    
};

// 2. dfs
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> result;
        vector<bool> visited(nums.size(), false);
        dfs(results, nums, result, visited, 0);
        sort(results.begin(), results.end());
        results.erase(unique(results.begin(), results.end()), results.end());
        return results;
    }
    
    void dfs(vector<vector<int>>& results, vector<int> nums, vector<int> result, vector<bool>& visited, int depth) {
        if(result.size() == nums.size()) {
            results.push_back(result);
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(!visited[i]) {
                result.push_back(nums[i]);
                visited[i] = true;
                dfs(results, nums, result, visited, i + 1);
                result.pop_back();
                visited[i] = false;
            }
        }
    }
};