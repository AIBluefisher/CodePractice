// ID: 242

// Description:
// Given two strings s and t , write a function to determine if t is an anagram of s.

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false
// Note:
// You may assume the string contains only lowercase alphabets.

// Follow up:
// What if the inputs contain unicode characters? How would you adapt your solution to such case?

// Solution:
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> anagram(30, 0);
        for(auto ss : s) anagram[ss - 'a']++;
        for(auto ss : t) anagram[ss - 'a']--;
        for(auto a : anagram) {
            if(a != 0) return false;
        }
        return true;
    }
};