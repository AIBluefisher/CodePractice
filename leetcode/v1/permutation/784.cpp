// ID: 784

// Description:
// Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

// Examples:
// Input: S = "a1b2"
// Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

// Input: S = "3z4"
// Output: ["3z4", "3Z4"]

// Input: S = "12345"
// Output: ["12345"]
// Note:

// S will be a string with length at most 12.
// S will consist only of letters or digits.

// Solution:
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        dfs(S, result, 0);
        return result;
    }
    
    void dfs(string S, vector<string>& result, int index) {
        if(index == S.size()) {
            result.push_back(S);
            return;
        }
        dfs(S, result, index + 1);
        string sc = S;
        if(isalpha(S[index])) {
            if('a' <= S[index] && S[index] <= 'z') {
                sc[index] = S[index] - 32;
            }
            if('A' <= S[index] && S[index] <= 'Z') {
                sc[index] = S[index] + 32;
            }
            dfs(sc, result, index + 1);
        }
    }
};