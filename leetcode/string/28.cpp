// ID: 28

// Description :
// Implement strStr().

// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Example 1:

// Input: haystack = "hello", needle = "ll"
// Output: 2
// Example 2:

// Input: haystack = "aaaaa", needle = "bba"
// Output: -1
// Clarification:

// What should we return when needle is an empty string? This is a great question to ask during an interview.

// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

// Solution: naive string matching
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        
        int i = 0, j = 0;
        while(i < haystack.size() && j < needle.size()) {
            if(haystack[i] == needle[j]) {
                i++;
                j++;
            }
            else {
                i = i - j + 1;
                j = 0;
            }     
            if(j == needle.size()) return i - needle.length();
        }
        return -1;
    }
};