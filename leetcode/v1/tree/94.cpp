// ID: 96

// Description:
// Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

// Example:

// Input: 3
// Output: 5
// Explanation:
// Given n = 3, there are a total of 5 unique BST's:

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

// Solution:
class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n + 1, 0);
        f[0] = f[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int k = 0; k < i; k++) {
                f[i] += f[k] * f[i - k - 1];
            }
        }
        return f[n];
    }
};
