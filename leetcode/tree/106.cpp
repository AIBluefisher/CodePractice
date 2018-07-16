// ID: 106

// Description:
// Given inorder and postorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//
// For example, given
//
// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
// Return the following binary tree:
//
//     3
//    / \
//   9  20
//     /  \
//    15   7

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty()) return nullptr;
        return buildBT(inorder, postorder, 0, postorder.size(), 0, inorder.size());
    }

    TreeNode* buildBT(vector<int>& inorder, vector<int>& postorder, int post_left, int post_right, int in_left, int in_right) {
        if(post_left >= post_right) return nullptr;
        TreeNode* root = new TreeNode(postorder[post_right - 1]);

        int k = 0;
        for(int i = in_left; i < in_right; i++) {
            if(inorder[i] == postorder[post_right - 1]) break;
            k++;
        }

        root->left = buildBT(inorder, postorder, post_left, post_left + k, in_left, in_left + k);
        root->right = buildBT(inorder, postorder, post_left + k, post_right - 1, in_left + k + 1, in_right);
        return root;
    }
};
