// ID: 7

// Description:
// Given a 32-bit signed integer, reverse digits of an integer.

// Example 1:

// Input: 123
// Output: 321
// Example 2:

// Input: -123
// Output: -321
// Example 3:

// Input: 120
// Output: 21
// Note:
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. 
// For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

// Solution

// 1.
class Solution {
public:
    int reverse(int x) {
        string str = to_string(x);
        long long int ans = 0;
        int j = 0;
        for(int i = 0; i < str.size(); i++) {
            if(isdigit(str[i])) {
                ans += (str[i] - '0') * pow(10, j++);
                if((x > 0 && ans > 0x7fffffff) || (x < 0 && ans > 0x80000000)) 
                    return 0;
            }
        }
        return ans = (x > 0) ? ans : -ans;
    }
};

// 2. 
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x != 0) {
            int r = x % 10;
            x /= 10;
            if(rev > INT_MAX / 10 || (rev == INT_MAX / 10 && r > 7)) return 0;
            if(rev < INT_MIN / 10 || (rev == INT_MIN / 10 && r < -8)) return 0;
            rev = rev * 10 + r;
        }
        return rev;
    }
};