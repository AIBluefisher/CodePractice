// ID: 77

// Description:
// Given two strings, find the longest common subsequence (LCS).

// Your code should return the length of LCS.

// Example
// For "ABCD" and "EDCA", the LCS is "A" (or "D", "C"), return 1.

// For "ABCD" and "EACB", the LCS is "AC", return 2.

// Solution:
class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
    int longestCommonSubsequence(string &A, string &B) {
        int dp[A.size() + 1][B.size() + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < B.size(); j++) {
                if(A[i] == B[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
                else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return dp[A.size()][B.size()];
    }
};