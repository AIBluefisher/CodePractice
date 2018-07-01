// ID: 205

// Description:
// Given two strings s and t, determine if they are isomorphic.

// Two strings are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

// Example 1:

// Input: s = "egg", t = "add"
// Output: true
// Example 2:

// Input: s = "foo", t = "bar"
// Output: false
// Example 3:

// Input: s = "paper", t = "title"
// Output: true
// Note:
// You may assume both s and t have the same length.

// Solution:
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> sm, tm;
        int i = 0, j = 0;
        for(int k = 0; k < s.size(); k++) {
            if(sm.find(s[k]) == sm.end())
                sm.insert(make_pair(s[k], i++));
            if(tm.find(t[k]) == tm.end())
                tm.insert(make_pair(t[k], j++));
        }
        string sp, tp;
        for(int k = 0; k < s.size(); k++) {
            sp.push_back(sm.find(s[k])->second + '0');
            tp.push_back(tm.find(t[k])->second + '0');
        }
        return sp == tp;
    }
};