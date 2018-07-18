// ID: 3

// Description:
// Given a string, find the length of the longest substring without repeating characters.

// Examples:

// Given "abcabcbb", the answer is "abc", which the length is 3.

// Given "bbbbb", the answer is "b", with the length of 1.

// Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, 
// "pwke" is a subsequence and not a substring.

// Solution:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, start = -1;
        vector<int> dic(256, -1);
        for(int i = 0; i < s.size(); i++) {
            if(dic[s[i]] > start) start = dic[s[i]];
            dic[s[i]] = i;
            ans = max(ans, i - start);
        }     
        return ans;
    }
};