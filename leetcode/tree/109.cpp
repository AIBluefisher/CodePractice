// ID: 109

// Description:
// Given a singly linked list where elements are sorted in ascending order, 
// convert it to a height balanced BST.

// For this problem, a height-balanced binary tree is defined as a binary tree in which 
// the depth of the two subtrees of every node never differ by more than 1.

// Example:

// Given the sorted linked list: [-10,-3,0,5,9],

// One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

//       0
//      / \
//    -3   9
//    /   /
//  -10  5

// Solution:

// 1.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums = listToArray(head);
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
    
    vector<int> listToArray(ListNode* head) {
        vector<int> array;
        ListNode* p = head;
        while (p) {
            array.push_back(p->val);
            p = p->next;
        }
        return array;
    }
    
    TreeNode* sortedArrayToBST(const vector<int>& array, int i, int j) {
        if (i > j) return nullptr;
        int mid = (i + j) / 2;
        TreeNode* root = new TreeNode(array[mid]);
        root->left = sortedArrayToBST(array, i, mid - 1);
        root->right = sortedArrayToBST(array, mid + 1, j);
        return root;
    }
};

// 2.
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* p = head;
        int len = 0;
        while (p) {
            len++;
            p = p->next;
        }
        return sortedListToBST(head, 0, len - 1);
    }
    
    TreeNode* sortedListToBST(ListNode*& list, int i, int j) {
        if (i > j) return nullptr;
        
        int mid = (i + j) / 2;
        TreeNode* left = sortedListToBST(list, i, mid - 1);
        TreeNode* root = new TreeNode(list->val);
        root->left = left;
        list = list->next;
        root->right = sortedListToBST(list, mid + 1, j);
        return root;
    }
};