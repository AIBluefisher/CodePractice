// ID: 343

// Description:
// Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

// For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

// Note: You may assume that n is not less than 2 and not larger than 58.

// Solution:
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = dp[2] = 1;
        for(int i = 3; i <= n; i++) {
            for(int k = 1; k <= i / 2; k++) {
                dp[i] = max(dp[i], max(k * (i - k), k * dp[i - k]));
            }
        }
        return dp[n];
    }
};

