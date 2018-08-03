// ID: 116

// Description:
// Given a binary tree

// struct TreeLinkNode {
//   TreeLinkNode *left;
//   TreeLinkNode *right;
//   TreeLinkNode *next;
// }
// Populate each next pointer to point to its next right node. If there is no next right node, 
// the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

// Note:

// You may only use constant extra space.
// Recursive approach is fine, implicit stack space does not count as extra space for this problem.
// You may assume that it is a perfect binary tree (ie, all leaves are at the same level, 
// and every parent has two children).
// Example:

// Given the following perfect binary tree,

//      1
//    /  \
//   2    3
//  / \  / \
// 4  5  6  7
// After calling your function, the tree should look like:

//      1 -> NULL
//    /  \
//   2 -> 3 -> NULL
//  / \  / \
// 4->5->6->7 -> NULL

// Solution:
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

// 1.
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        TreeLinkNode* pre = root, *cur = root;
        while(pre->left) {
            cur = pre;
            while(cur) {
                cur->left->next = cur->right;
                if(cur->next) {
                    cur->right->next = cur->next->left;
                }
                cur = cur->next;
            }
            pre = pre->left;
        }
    }
};

// 2. level order traversal
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        vector<vector<TreeLinkNode*>> nodes_list;
        queue<pair<TreeLinkNode*, int>> qu;
        qu.push(make_pair(root, 0));
        
        while(!qu.empty()) {
            auto node = qu.front(); qu.pop();
            TreeLinkNode* tnode = node.first;
            int level = node.second;
            if(nodes_list.size() <= level) {
                vector<TreeLinkNode*> vec;
                vec.push_back(tnode);
                nodes_list.push_back(vec);
            }
            else nodes_list[level].push_back(tnode);
            if(tnode->left) qu.push(make_pair(tnode->left, level + 1));
            if(tnode->right) qu.push(make_pair(tnode->right, level + 1));
        }
        
        for(auto& nodes : nodes_list) {
            for(int i = 1; i < nodes.size(); i++) {
                nodes[i - 1]->next = nodes[i];
            }
        }
    }
};