// ID: 66

// Description:
// Given a binary tree, return the preorder traversal of its nodes' values.

// Example
// Given:

//     1
//    / \
//   2   3
//  / \
// 4   5
// return [1,2,4,5,3].

// Challenge
// Can you do it without recursion?


// Solution:

// 1. recursion
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
    vector<int> preorderTraversal(TreeNode * root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }
    
    void preorder(TreeNode* root, vector<int>& result) {
        if(root == nullptr) return;
        result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right, result);
    }
};

// 2. stack
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
    vector<int> preorderTraversal(TreeNode * root) {
        vector<int> result;
        stack<TreeNode*> st;
        if(root != nullptr) st.push(root);
        
        while(!st.empty()) {
            TreeNode * node = st.top(); st.pop();
            result.push_back(node->val);
            if(node->right != nullptr) st.push(node->right);
            if(node->left != nullptr) st.push(node->left);
        }
        return result;
    }
    
};