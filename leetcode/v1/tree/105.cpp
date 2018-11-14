// ID: 105

// Description:
// Given preorder and inorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//
// For example, given
//
// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return nullptr;
        return buildBT(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }

    TreeNode* buildBT(vector<int>& preorder, vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right) {
        if(pre_left >= pre_right)  { return nullptr; }
        TreeNode* root = new TreeNode(preorder[pre_left]);

        int k = 0;
        for(int i = in_left; i < in_right; i++) {
            if(preorder[pre_left] == inorder[i]) break;
            k++;
        }

        root->left = buildBT(preorder, inorder, pre_left + 1, pre_left + k + 1, in_left, in_left + k);
        root->right = buildBT(preorder, inorder, pre_left + k + 1, pre_right, in_left + k + 1, in_right);

        return root;
    }
};
