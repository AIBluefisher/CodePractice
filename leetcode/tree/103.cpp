// ID: 103

// Description:
// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> results;
        queue<pair<int, TreeNode*>> qu;
        if(root != nullptr) qu.push(make_pair(0, root));
        while(!qu.empty()) {
            pair<int, TreeNode*> node;
            node = qu.front(); qu.pop();
            if(node.second->left != nullptr) qu.push(make_pair(node.first + 1, node.second->left));
            if(node.second->right != nullptr) qu.push(make_pair(node.first + 1, node.second->right));
            if(results.size() <= node.first) {
                vector<int> result;
                result.push_back(node.second->val);
                results.push_back(result);
            }
            else results[node.first].push_back(node.second->val);
        }
        
        // zig zag
        for(int i = 0; i < results.size(); i++) {
            if(i & 1) reverse(results[i].begin(), results[i].end());
        }
        return results;
    }
};
