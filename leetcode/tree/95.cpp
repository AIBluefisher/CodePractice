// ID: 95

// Description:
// Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

// Example:

// Input: 3
// Output:
// [
//   [1,null,3,2],
//   [3,2,null,1],
//   [3,1,null,null,2],
//   [2,1,3],
//   [1,null,2,null,3]
// ]
// Explanation:
// The above output corresponds to the 5 unique BST's shown below:

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return generate(1, n);
    }
    
    vector<TreeNode*> generate(int l, int r) {
        vector<TreeNode*> subTree;
        if (l > r) {
            subTree.push_back(nullptr);
            return subTree;
        }
        
        for (int k = l; k <= r; k++) {
            vector<TreeNode*> lTree = generate(l, k - 1);
            vector<TreeNode*> rTree = generate(k + 1, r);
            for (auto lt : lTree) {
                for (auto rt : rTree) {
                    TreeNode* node = new TreeNode(k);
                    node->left = lt;
                    node->right = rt;
                    subTree.push_back(node);
                }
            }
        }
        return subTree;
    }
};