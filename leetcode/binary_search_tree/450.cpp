// ID: 450

// Description:
// Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
//
// Basically, the deletion can be divided into two stages:
//
// Search for a node to remove.
// If the node is found, delete the node.
// Note: Time complexity should be O(height of tree).
//
// Example:
//
// root = [5,3,6,2,4,null,7]
// key = 3
//
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
//
// Given key to delete is 3. So we find the node with value 3 and delete it.
//
// One valid answer is [5,4,6,2,null,null,7], shown in the following BST.
//
//     5
//    / \
//   4   6
//  /     \
// 2       7
//
// Another valid answer is [5,2,6,null,4,null,7].
//
//     5
//    / \
//   2   6
//    \   \
//     4   7

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        else if (key < root->val) root->left = deleteNode(root->left, key);
        else if (key > root->val) root->right = deleteNode(root->right, key);
        else if (!root->left) {
            TreeNode* q = root->right;
            delete root;
            return q;
        }
        else if (!root->left->right) {
            TreeNode* q = root->left;
            q->right = root->right;
            delete root;
            return q;
        }
        else {
            TreeNode* q = root->left;
            while(q->right->right) q = q->right;
            TreeNode* r = q->right;
            q->right = r->left;
            r->left = root->left;
            r->right = root->right;
            delete root;
            return r;
        }
        return root;
    }
};
