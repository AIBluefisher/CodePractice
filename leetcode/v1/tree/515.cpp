// ID: 515

// Description:
// You need to find the largest value in each row of a binary tree.

// Example:
// Input: 

//           1
//          / \
//         3   2
//        / \   \  
//       5   3   9 

// Output: [1, 3, 9]

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
    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>> values;
        queue<pair<int, TreeNode*>> qu;
        if(root) qu.push(make_pair(0, root));
        
        while(!qu.empty()) {
            auto node = qu.front(); qu.pop();
            int level = node.first;
            TreeNode* tn = node.second;
            if(values.size() <= level) {
                vector<int> value;
                value.push_back(tn->val);
                values.push_back(value);
            }
            else values[level].push_back(tn->val);
            if(tn->left) qu.push(make_pair(level + 1, tn->left));
            if(tn->right) qu.push(make_pair(level + 1, tn->right));
        }
        
        vector<int> ans;
        for(auto value : values) {
            ans.push_back(*(max_element(value.begin(), value.end())));
        }
        return ans;
    }
};