// ID: 98

// Description:
// Given a binary tree, determine if it is a valid binary search tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
// Example 1:

// Input:
//     2
//    / \
//   1   3
// Output: true
// Example 2:

//     5
//    / \
//   1   4
//      / \
//     3   6
// Output: false
// Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
//              is 5 but its right child's value is 4.

// Solution: traver by in-order, if the traverse list is in iascending order, then it's a valid BST
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 1.
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> list;
        dfs(root, list);
        if(list.size() == 1 || list.size() == 0) return true;
        for(int i = 1; i < list.size(); i++) {
            if(list[i] <= list[i - 1]) return false;
        }
        return true;
    }
    
    void dfs(TreeNode* root, vector<int>& list) {
        if(root == nullptr) return;
        dfs(root->left, list);
        list.push_back(root->val);
        dfs(root->right, list);
    }
};

// 2.
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, -2147483649, 2147483648);
    }
    
    bool isValidBST(TreeNode* root, long long lower, long long upper) {
        if(!root) return true;
        return root->val > lower && root->val < upper &&
               isValidBST(root->left, lower, root->val) &&
               isValidBST(root->right, root->val, upper);
    }

};