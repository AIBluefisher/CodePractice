// ID: 102
// Description:
// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]

// Solution: 
// Simply using queue, and traverse from root node. 
// To identify which level the node belongs to, 
// we can use a new struct pair<int, TreeNode*>, 
// pair.first is the level id, and pair.second is the corresponding treenode.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<int, TreeNode*>> qu;
        if(root != nullptr) qu.push(make_pair(0, root));
        
        vector<vector<int>> results;
        while(!qu.empty()) {
            auto pnode = qu.front(); qu.pop();  
            if(results.size() < pnode.first + 1) {
                vector<int> result;
                result.push_back(pnode.second->val);
                results.push_back(result);
            }
            else {
                results[pnode.first].push_back(pnode.second->val);
            }
            
            if(pnode.second->left != nullptr) qu.push(make_pair(pnode.first + 1, pnode.second->left));
            if(pnode.second->right != nullptr) qu.push(make_pair(pnode.first + 1, pnode.second->right));
        }
        return results;
    }
};