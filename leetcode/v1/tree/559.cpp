// ID: 559

// Description:
// Given a n-ary tree, find its maximum depth.

// The maximum depth is the number of nodes along the longest path 
// from the root node down to the farthest leaf node.

// For example, given a 3-ary tree:

 


 
// We should return its max depth, which is 3.

// Note:

// The depth of the tree is at most 1000.
// The total number of nodes is at most 5000.

// 1. DFS
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        int depth = 0;
        for (Node* child : root->children) {
            depth = max(depth, maxDepth(child));
        }
        return depth + 1;
    }
};


// 2.BFS
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        queue<pair<Node*, int>> qu;
        qu.push(make_pair(root, 1));
        
        int depth = 0;
        while(!qu.empty()) {
            auto node = qu.front(); qu.pop();
            depth = node.second;
            for(Node* child : node.first->children) {
                qu.push(make_pair(child, depth + 1));
            }
        }
        return depth;
    }
};