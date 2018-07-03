// ID: 404

// Description:
// Find the sum of all left leaves in a given binary tree.

// Example:

//     3
//    / \
//   9  20
//     /  \
//    15   7

// There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        leftSum(root, sum);
        return sum;
    }
    
    void leftSum(TreeNode* root, int& sum) {
        if(root == nullptr) return;
        if(root->left != nullptr) {
            if(root->left->left == nullptr && root->left->right == nullptr) {
                sum += root->left->val;
            }
            leftSum(root->left, sum);
        }
        leftSum(root->right, sum);
    }
};