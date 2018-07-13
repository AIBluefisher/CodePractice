// ID: 687

// Description:
// Given a binary tree, find the length of the longest path where each node in the path has the same value. 
// This path may or may not pass through the root.

// Note: The length of path between two nodes is represented by the number of edges between them.

// Example 1:

// Input:

//               5
//              / \
//             4   5
//            / \   \
//           1   1   5
// Output:

// 2
// Example 2:

// Input:

//               1
//              / \
//             4   5
//            / \   \
//           4   4   5
// Output:

// 2
// Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.

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
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    
    int dfs(TreeNode* root, int& ans) {
        if(!root) return 0;
        int left = dfs(root->left, ans), right = dfs(root->right, ans);
        
        int root_l = 0, root_r = 0;
        if(root->left && root->left->val == root->val)
            root_l = left + 1;
        if(root->right && root->right->val == root->val)
            root_r = right + 1;
        ans = max(ans, root_l + root_r);
        return max(root_l, root_r);
    }
};