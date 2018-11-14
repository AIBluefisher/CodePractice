// ID: 60

// Description:
// The set [1,2,3,...,n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

// Note:

// Given n will be between 1 and 9 inclusive.
// Given k will be between 1 and n! inclusive.
// Example 1:

// Input: n = 3, k = 3
// Output: "213"
// Example 2:

// Input: n = 4, k = 9
// Output: "2314"

// Solution:
class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        vector<bool> visited(n + 1, false);
        string ans = "";
        dfs(n, result, visited, ans, k);
        return ans;
    }
    
    void dfs(int n, string& result, vector<bool>& visited, string& ans, int& k) {
        if(result.size() == n) {
            k--;
            if(!k) ans = result;
            return;
        }
        for(int i = 1; i <= n; i++) {
            if(!visited[i]) {
                visited[i] = true;
                result.push_back(i + '0');
                dfs(n, result, visited, ans, k);
                result.pop_back();
                visited[i] = false;
            }
        }
    }
};