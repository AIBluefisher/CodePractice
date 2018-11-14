// ID: 513

// Description:
// Given a binary tree, find the leftmost value in the last row of the tree.

// Example 1:
// Input:

//     2
//    / \
//   1   3

// Output:
// 1
// Example 2: 
// Input:

//         1
//        / \
//       2   3
//      /   / \
//     4   5   6
//        /
//       7

// Output:
// 7
// Note: You may assume the tree (i.e., the given root node) is not NULL.

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
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>> level_nodes;
        queue<pair<int, TreeNode*>> qu;
        if(root) qu.push(make_pair(0, root));
        
        while(!qu.empty()) {
            auto level_node = qu.front(); qu.pop();
            int level = level_node.first;
            TreeNode* node = level_node.second;
            if(level_nodes.size() <= level) {
                vector<int> nodes;
                nodes.push_back(node->val);
                level_nodes.push_back(nodes);
            }
            else level_nodes[level].push_back(node->val);
            if(node->left) qu.push(make_pair(level + 1, node->left));
            if(node->right) qu.push(make_pair(level + 1, node->right));
        }
        return level_nodes[level_nodes.size() - 1][0];
    }
};