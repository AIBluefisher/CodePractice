// ID: 409

// Description:
// Given a string which consists of lowercase or uppercase letters, 
// find the length of the longest palindromes that can be built with those letters.

// This is case sensitive, for example "Aa" is not considered a palindrome here.

// Note:
// Assume the length of given string will not exceed 1,010.

// Example:

// Input:
// "abccccdd"

// Output:
// 7

// Explanation:
// One longest palindrome that can be built is "dccaccd", whose length is 7.

// Solution:
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(128, 0);
        for(auto c : s) count[c]++;
        
        int ans = 0;
        for(auto v : count) {
            ans += v / 2 * 2;
            if(ans % 2 == 0 && v % 2 == 1) ans++;
        }
        return ans;
    }
};