// ID: 107

// Description:
// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]

// Solution:
// level order by queue, then reverse the results

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> results;
        queue<pair<int, TreeNode*>> qu;
        if(root != nullptr) qu.push(make_pair(0, root));
        
        while(!qu.empty()) {
            auto node = qu.front(); qu.pop();
            int level = node.first;
            TreeNode* tn = node.second;
            if(results.size() <= level) {
                vector<int> result;
                result.push_back(tn->val);
                results.push_back(result);
            }
            else results[level].push_back(tn->val);
            if(tn->left != nullptr) qu.push(make_pair(level + 1, tn->left));
            if(tn->right != nullptr) qu.push(make_pair(level + 1, tn->right));
        }
        // reverse results
        vector<vector<int>> rev_results;
        for(int i = results.size() - 1; i >= 0; i--) {
            rev_results.push_back(results[i]);
        }
        return rev_results;
    }
};