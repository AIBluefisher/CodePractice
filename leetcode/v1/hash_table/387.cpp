// ID: 387

// Description:
// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

// Examples:

// s = "leetcode"
// return 0.

// s = "loveleetcode",
// return 2.
// Note: You may assume the string contain only lowercase letters.

// Solution:
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> letter_map;
        for(auto c : s) { letter_map[c]++; }
        for(int i = 0; i < s.size(); i++) {
            if(letter_map[s[i]] == 1) return i; 
        }
        return -1;
    }
};