// ID: 5

// Description:
// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
// Example 1:
//
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:
//
// Input: "cbbd"
// Output: "bb"

// Solution:
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        bool dp[s.size()][s.size()] = { false };

        for(int i = 0; i < s.size(); i++) {
            dp[i][i] = true;
            if(i + 1 < s.size()) { dp[i][i + 1] = (s[i] == s[i + 1]); }
        }
        for(int i = s.size() - 3; i >= 0; i--) {
            for(int j = i + 2; j < s.size(); j++) {
                dp[i][j] = (dp[i + 1][j - 1] && s[i] == s[j]);
            }
        }

        int max_len = INT_MIN;
        string ans = "";
        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) {
                if(dp[i][j] && j - i + 1 > max_len) {
                    max_len = j - i + 1;
                    ans = s.substr(i, j - i + 1);
                }
            }
        }
        return ans;
    }
};
