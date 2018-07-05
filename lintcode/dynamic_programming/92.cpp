// ID: 92

// Description:
// Given n items with size Ai, an integer m denotes the size of a backpack. How full you can fill this backpack?

// Example
// If we have 4 items with size [2, 3, 5, 7], the backpack size is 11, we can select [2, 3, 5], so that the max size we can fill this backpack is 10. If the backpack size is 12. we can select [2, 3, 7] so that we can fulfill the backpack.

// You function should return the max size we can fill in the given backpack.

// Challenge
// O(n x m) time and O(m) memory.

// O(n x m) memory is also acceptable if you do not know how to optimize memory.

// Solution:
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        int dp[A.size() + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j <= m; j++) {
                if(j < A[i]) dp[i + 1][j] = dp[i][j];
                else {
                    dp[i + 1][j] = max(dp[i][j], dp[i][j - A[i]] + A[i]);
                }
            }
        }
        return dp[A.size()][m];
    }
};