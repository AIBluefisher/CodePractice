
## 94. Binary Tree Inorder Traversal

**Difficulty**: Medium

**Description**

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

**分析**

中序遍历二叉树。使用递归的话很容易。若不使用递归，则使用栈：由于每次均最先先输出左孩子节点，然后是根节点，最后输出右孩子节点。而栈的特点是后进先出，所以我们先将所有左孩子节点入栈，当访问当前节点时，当前节点没有左孩子或者左孩子节点均已访问过，然后再处理右孩子节点即可。

**代码**

### 递归版
```C++
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;
        
        recursiveInorder(root, result);
        
        return result;
    }
    
    void recursiveInorder(TreeNode* root, vector<int>& result)
    {
        if(root->left != NULL) recursiveInorder(root->left, result);
        result.push_back(root->val);
        if(root->right != NULL) recursiveInorder(root->right, result);
    }
};
```
### 非递归版

```C++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty())
        {
            TreeNode* top = st.top();
            while(top->left != NULL)
            {
                st.push(top->left);
                top = top->left;
            }
            
            while(!st.empty())
            {
                TreeNode* tmp = st.top();
                st.pop();
                result.push_back(tmp->val);
                if(tmp->right != NULL) 
                {
                    st.push(tmp->right);
                    break;
                }
            }
        }
        
        return result;
    }
};
```

## 144. Binary Tree Preorder Traversal

**Difficulty**: Medium

**Description**

Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

**分析**

二叉树的中序遍历。使用递归非常简单。不使用递归的话也比中序遍历二叉树简单：同样使用栈，由于后入先出，最先访问根节点元素，然后将右孩子入栈，再将左孩子入栈即可。

**代码**

### 递归版
```C++
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;
        
        recursivePreorder(root, result);
        return result;
    }
    
    void recursivePreorder(TreeNode* root, vector<int>& result)
    {
        if(root != NULL) result.push_back(root->val);
        if(root->left != NULL) recursivePreorder(root->left, result);
        if(root->right != NULL) recursivePreorder(root->right, result);
    }jike
};
```
### 非递归版

```C++
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        // if(root == NULL) return result;
        
        stack<TreeNode*> st;
        if(root != NULL) st.push(root);
        
        while(!st.empty())
        {
            TreeNode* top = st.top();
            st.pop();
            result.push_back(top->val);
            if(top->right != NULL) st.push(top->right);
            if(top->left != NULL) st.push(top->left);
        }
        
        return result;
    }
};
```

## 257. Binary Tree Paths

**Difficulty**: easy

**Description**

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]


**分析**

思路很简单，只需要按先序深度优先遍历搜索即可，遍历到叶节点时就将路径保存．

**代码**

### 递归版
```C++
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(root == NULL) return result;
        string path;
        dfs(result, path, root);
        return result;
    }
    
    void dfs(vector<string>& result, string& path, TreeNode* node)
    {
        if(node == NULL) return;
        else 
        {
            path.append(to_string(node->val));
            path.append("->");
        }
        if(node->left == NULL && node->right == NULL)
        {
            result.push_back(path.substr(0, path.length() - 2));
            return;
        }
        else 
        {
            string leftPath, rightPath;
            leftPath.assign(path.begin(), path.end());
            rightPath.assign(path.begin(), path.end());
            dfs(result, leftPath, node->left);
            dfs(result, rightPath, node->right);
        }
    }
};
```