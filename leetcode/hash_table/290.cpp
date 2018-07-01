// ID: 290

// Description:
// Given a pattern and a string str, find if str follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

// Example 1:

// Input: pattern = "abba", str = "dog cat cat dog"
// Output: true
// Example 2:

// Input:pattern = "abba", str = "dog cat cat fish"
// Output: false
// Example 3:

// Input: pattern = "aaaa", str = "dog cat cat dog"
// Output: false
// Example 4:

// Input: pattern = "abba", str = "dog dog dog dog"
// Output: false
// Notes:
// You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

// Solution:
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> pm;
        unordered_map<string, int> sm;
        vector<string> ss = split(str);
        int i = 0, j = 0;
        for(int k = 0; k < pattern.size(); k++) {
            if(pm.find(pattern[k]) == pm.end())
                pm.insert(make_pair(pattern[k], i++));
        }
        for(int k = 0; k < ss.size(); k++) {
            if(sm.find(ss[k]) == sm.end())
                sm.insert(make_pair(ss[k], j++));
        }
        
        string pp, sp;
        for(int k = 0; k < pattern.size(); k++) pp.push_back(pm.find(pattern[k])->second + '0');
        for(auto s : ss) sp.push_back(sm.find(s)->second + '0');
        return pp == sp;
    }
    
    vector<string> split(string str) {
        vector<string> results;
        string r;
        for(int i = 0; i < str.size(); i++) {
            char s = str[i];
            if(s != ' ') r.push_back(s);
            else {
                results.push_back(r);
                r.clear();
            }
        }
        if(!r.empty()) results.push_back(r);
        return results;
    }
};