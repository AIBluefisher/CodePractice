// ID: 114

// Description:
// Given a binary tree, flatten it to a linked list in-place.
//
// For example, given the following tree:
//
//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
// The flattened tree should look like:
//
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6

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
    void flatten(TreeNode* root) {
        if(!root || (!root->left && !root->right)) return;
        if(root->left) {
            TreeNode* p = root->left;
            while(p->right) p = p->right;
            TreeNode* q = root->right;
            TreeNode* r = root->left;
            p->right = root->right;
            root->right = root->left;
            root->left = nullptr;
            flatten(r);
            flatten(q);
        }
        else flatten(root->right);
    }
};
