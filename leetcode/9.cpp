// ID: 9

// Description:
// Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

// Example 1:

// Input: 121
// Output: true
// Example 2:

// Input: -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:

// Input: 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
// Follow up:

// Coud you solve it without converting the integer to a string?

// Solution:

class Solution {
public:
    bool isPalindrome(int x) {
        if(x == -2147483648) return false;
        vector<char> nums;
        if(x < 0) {
            nums.push_back('-');
            x = -x;
        }
        while(x > 0) {
            nums.push_back(x % 10 + '0');
            x /= 10;
        }
        int i = 0, j = nums.size() - 1;
        while(j - i > 0) {
            if(nums[i++] != nums[j--]) return false;
        }
        return true;
    }
};