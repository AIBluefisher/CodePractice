// ID: 530

// Description:
// Given a binary search tree with non-negative values, 
// find the minimum absolute difference between values of any two nodes.

// Example:

// Input:

//    1
//     \
//      3
//     /
//    2

// Output:
// 1

// Explanation:
// The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
// Note: There are at least two nodes in this BST.

// Solution:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int min_diff = INT_MAX;
        vector<int> vals;
        inorder(root, vals);
        for(int i = 1; i < vals.size(); i++) {
            min_diff = min(min_diff, vals[i] - vals[i - 1]);
        }
        return min_diff;
    }
    
    void inorder(TreeNode* root, vector<int>& vals) {
        if(!root) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }
};