// ID: 113

//  Description:
// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

// Note: A leaf is a node with no children.

// Example:

// Given the below binary tree and sum = 22,

//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \    / \
// 7    2  5   1
// Return:

// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> results;
        vector<int> result;
        dfs(results, result, root, sum);
        return results;
    }
    
    void dfs(vector<vector<int>>& results, vector<int> result, TreeNode* root, int sum) {
        if(root == nullptr) return;
        if(sum == root->val && root->left == nullptr && root->right == nullptr) {
            result.push_back(root->val);
            results.push_back(result);
            return;
        }
        result.push_back(root->val);
        dfs(results, result, root->left, sum - root->val);
        dfs(results, result, root->right, sum - root->val);
    }
};