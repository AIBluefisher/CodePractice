// ID: 637

// Description:
// Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
// Example 1:
// Input:
//     3
//    / \
//   9  20
//     /  \
//    15   7
// Output: [3, 14.5, 11]
// Explanation:
// The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
// Note:
// The range of node's value is in the range of 32-bit signed integer.

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<double>> level_nodes;
        queue<pair<int, TreeNode*>> qu;
        if(root) qu.push(make_pair(0, root));
        
        // level-order traverse
        while(!qu.empty()) {
            pair<int, TreeNode*> node = qu.front(); qu.pop();
            int level = node.first;
            TreeNode* tn = node.second;
            if(level_nodes.size() < level + 1) {
                vector<double> nodes;
                nodes.push_back(tn->val);
                level_nodes.push_back(nodes);
            }
            else level_nodes[level].push_back(tn->val);
            
            if(tn->left) qu.push(make_pair(level + 1, tn->left));
            if(tn->right) qu.push(make_pair(level + 1, tn->right));
        }
        
        vector<double> results;
        for(int i = 0; i < level_nodes.size(); i++) {
            double s = 0;
            for(auto node : level_nodes[i]) { s += node; }
            results.push_back(s / level_nodes[i].size());
        }
        return results;
    }
};