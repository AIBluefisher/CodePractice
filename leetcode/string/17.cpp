// ID: 17

// Description:
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


// Example:

// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note:

// Although the above answer is in lexicographical order, your answer could be in any order you want

// Solution:
// dfs with backtrack
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> results;
        if(digits.empty()) return results;
        vector<string> ismap = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        string result;
        dfs(digits, 0, ismap, results, result);
        return results;
    }
    
    void dfs(string digits, int index, vector<string> ismap, vector<string>& results, string result) {
        if(result.size() == digits.size()) {
            results.push_back(result);
            return;
        }
        int digit = digits[index] - '0';
        for(int i = 0; i < ismap[digit - 2].size(); i++) {
            result.push_back(ismap[digit - 2][i]);
            dfs(digits, index + 1, ismap, results, result);
            result.pop_back();
        }
    }
};
