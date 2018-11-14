// ID: 671

// Description:
// Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.

// Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

// If no such second minimum value exists, output -1 instead.

// Example 1:
// Input: 
//     2
//    / \
//   2   5
//      / \
//     5   7

// Output: 5
// Explanation: The smallest value is 2, the second smallest value is 5.
// Example 2:
// Input: 
//     2
//    / \
//   2   2

// Output: -1
// Explanation: The smallest value is 2, but there isn't any second smallest value.

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
    int findSecondMinimumValue(TreeNode* root) {
        map<int, int> tree_ele;
        int index = 0;
        if(root) preorder(root, tree_ele, index);
        for(auto it = tree_ele.begin(); it != tree_ele.end(); it++) {
            if(it->second == 1) return it->first;
        }
        return -1;
    }
    
    void preorder(TreeNode* root, map<int, int>& tree_ele, int index) {
        if(tree_ele.find(root->val) == tree_ele.end()) {
            tree_ele.insert(make_pair(root->val, index));
            index++;
        }
        if(root->left) preorder(root->left, tree_ele, index);
        if(root->right) preorder(root->right, tree_ele, index);
    }
};