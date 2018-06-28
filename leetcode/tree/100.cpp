// ID: 199

// Description:
// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

// Example:

// Input: [1,2,3,null,5,null,4]
// Output: [1, 3, 4]
// Explanation:

//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---

// Solution:

// 1. level order
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<pair<int, TreeNode*>> qu;
        if(root != nullptr) qu.push(make_pair(0, root));
        int pre = 0;  // previous level, current level
        TreeNode* pre_node = root;
        while(!qu.empty()) {
            auto node = qu.front(); qu.pop();
            TreeNode* tn = node.second;
            int level = node.first;
            if(pre != level) result.push_back(pre_node->val);
            if(tn->left != nullptr) qu.push(make_pair(level + 1, tn->left));
            if(tn->right != nullptr) qu.push(make_pair(level + 1, tn->right));
            pre = level;
            pre_node = tn;
        }
        if(pre_node != nullptr) result.push_back(pre_node->val);
        return result;
    }
};