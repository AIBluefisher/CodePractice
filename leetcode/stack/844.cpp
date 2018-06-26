// ID 844

// Description:
// Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

// Example 1:

// Input: S = "ab#c", T = "ad#c"
// Output: true
// Explanation: Both S and T become "ac".
// Example 2:

// Input: S = "ab##", T = "c#d#"
// Output: true
// Explanation: Both S and T become "".
// Example 3:

// Input: S = "a##c", T = "#a#c"
// Output: true
// Explanation: Both S and T become "c".
// Example 4:

// Input: S = "a#c", T = "b"
// Output: false
// Explanation: S becomes "c" while T becomes "b".
// Note:

// 1 <= S.length <= 200
// 1 <= T.length <= 200
// S and T only contain lowercase letters and '#' characters.
// Follow up:

// Can you solve it in O(N) time and O(1) space?

// Solution:
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> st1, st2;
        for(auto s : S) {
            if(s == '#' && !st1.empty()) st1.pop();
            else if(s != '#') st1.push(s);
        }
        for(auto s : T) {
            if(s == '#' && !st2.empty()) st2.pop();
            else if(s != '#') st2.push(s);
        }
        while(!st1.empty() && !st2.empty()) {
            char c1 = st1.top(); st1.pop();
            char c2 = st2.top(); st2.pop();
            if(c1 != c2) return false;
        }
        if(!(st1.empty() && st2.empty())) return false;
        return true;
    }
};