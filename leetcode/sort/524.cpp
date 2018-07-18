// ID: 524

// Description:
// Given a string and a string dictionary, find the longest string in the dictionary 
// that can be formed by deleting some characters of the given string. 
// If there are more than one possible results, return the longest word with the smallest lexicographical order. 
// If there is no possible result, return the empty string.

// Example 1:
// Input:
// s = "abpcplea", d = ["ale","apple","monkey","plea"]

// Output: 
// "apple"
// Example 2:
// Input:
// s = "abpcplea", d = ["a","b","c"]

// Output: 
// "a"
// Note:
// All the strings in the input will only contain lower-case letters.
// The size of the dictionary won't exceed 1,000.
// The length of all the strings in the input won't exceed 1,000.

// Solution:
class Solution {
public:
    static bool cmp(const std::string& a, const std::string& b) {
        if(a.size() == b.size()) return a < b;
        return a.size() > b.size();
    }
    
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), cmp);
        for(int i  = 0; i < d.size(); i++) {
            int pos = -1;
            for(int j = 0; j < d[i].size(); j++) {       
                pos = s.find(d[i][j], pos + 1);
                if(pos == std::string::npos) {
                    pos = -1;
                    break;
                }
            }
            if(pos != -1) return d[i];
        }
        return "";
    }
};