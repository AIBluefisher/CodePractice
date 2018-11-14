// ID: 22

// Description:
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

// Solution:
class Solution {
    char b[2] = {'(', ')'};
public:
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        string result;
        int l = 0, r = 0;
        backtrack(results, result, l, r, n);
        return results;
    }
    
    void backtrack(vector<string>& results, string result, int& l, int& r, int n) {
        if(l == n && r == n) {
            results.push_back(result);
            return;
        }
        
        if(l == n) {
            result += b[1];
            r++;
            backtrack(results, result, l, r, n);
            r--;
            result.pop_back();
        }
        
        else if(r == l) {
            result += b[0];
            l++;
            backtrack(results, result, l, r, n);
            l--;
            result.pop_back();
        }
        
        else if(l < n && r < l) {
            for(int i = 0; i < 2; i++) {
                result += b[i];
                if(i) r++;
                else l++;
                backtrack(results, result, l, r, n);
                if(i) r--;
                else l--;
                result.pop_back();
            }
        }
    }
};