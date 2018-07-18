// ID: 654

// Description:
// Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

// The root is the maximum number in the array.
// The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
// The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
// Construct the maximum tree by the given array and output the root node of this tree.

// Example 1:
// Input: [3,2,1,6,0,5]
// Output: return the tree root node representing the following tree:

//       6
//     /   \
//    3     5
//     \    / 
//      2  0   
//        \
//         1
// Note:
// The size of the given array will be in the range [1,1000].

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        return constructTree(nums, 0, nums.size() - 1);
    }
    
    TreeNode* constructTree(vector<int>& nums, int l, int r) {
        int max_pos = -1, max_ele = INT_MIN;
        for(int i = l; i <= r; i++) {
            if(max_ele < nums[i]) {
                max_ele = nums[i];
                max_pos = i;
            }
        }
        TreeNode* node = new TreeNode(nums[max_pos]);
        if(l < max_pos) node->left = constructTree(nums, l, max_pos - 1);
        if(max_pos < r) node->right = constructTree(nums, max_pos + 1, r);
        return node;
    }
};