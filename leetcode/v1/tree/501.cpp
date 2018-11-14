// ID: 501

// Description:
// Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently 
// occurred element) in the given BST.

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than or equal to the node's key.
// The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
// Both the left and right subtrees must also be binary search trees.
 

// For example:
// Given BST [1,null,2,2],

//    1
//     \
//      2
//     /
//    2
 

// return [2].

// Note: If a tree has more than one mode, you can return them in any order.

// Follow up: Could you do that without using any extra space? (Assume that the implicit stack space 
// incurred due to recursion does not count).

// Solution:

// 1.
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
    int curval = -1;
public:
    vector<int> findMode(TreeNode* root) {
        int max_frequency = 0, cur_frequency = 0;
        vector<int> results;
        inorder(root, results, max_frequency, cur_frequency);
        return results;
    }
    
    void inorder(TreeNode* root, vector<int>& results, int& max_frequency, int& cur_frequency) {
        if(!root) return;
        
        inorder(root->left, results, max_frequency, cur_frequency);
        
        if(curval == root->val) cur_frequency++;
        else {
            curval = root->val;
            cur_frequency = 1;
        }
        
        if(cur_frequency > max_frequency) {
            max_frequency = cur_frequency;
            vector<int>().swap(results);
            results.push_back(curval);
        }
        else if(cur_frequency == max_frequency) results.push_back(curval);
        
        inorder(root->right, results, max_frequency, cur_frequency);
    }
};

// 2. 
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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> nums_map;
        int max_frequency = 0;
        inorder(root, nums_map, max_frequency);
        vector<int> results;
        
        for(auto ite = nums_map.begin(); ite != nums_map.end(); ite++) {
            if (ite->second == max_frequency) results.push_back(ite->first);
        }
        return results;
    }
    
    void inorder(TreeNode* root, unordered_map<int, int>& nums, int& max_frequency) {
        if (!root) return;
        inorder(root->left, nums, max_frequency);
        nums[root->val]++;
        max_frequency = max(++nums[root->val], max_frequency);
        inorder(root->right, nums, max_frequency);
    }
};


