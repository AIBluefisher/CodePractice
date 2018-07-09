// ID: 383

// Description:
// Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

// Each letter in the magazine string can only be used once in your ransom note.

// Note:
// You may assume that both strings contain only lowercase letters.

// canConstruct("a", "b") -> false
// canConstruct("aa", "ab") -> false
// canConstruct("aa", "aab") -> true

// Solution:
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<bool> visited(magazine.size(), false);
        for(auto c : ransomNote) {
            bool is_find = false;
            for(int i = 0; i < magazine.size(); i++) {
                if(!visited[i] && magazine[i] == c) {
                    is_find = true;
                    visited[i] = true;
                    break;
                }
            }
            if(is_find) continue;
            else return false;
        }
        return true;
    }
};