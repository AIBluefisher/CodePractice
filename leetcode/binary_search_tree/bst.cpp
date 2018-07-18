struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 插入数值
TreeNode* insert(TreeNode* p, int x)
{
  if(!p) {
    TreeNode* q = new TreeNode(x);
    return q;
  }

  else {
    if(x < p->val) p->left = insert(p->left, x);
    else p->right = insert(p->right, x);
    return p;
  }
}

// 查找数值
bool find(TreeNode* p, int x)
{
  if(!p) return false;
  else if(p->val == x) return true;
  else if(p->val > x) return find(p->left, x);
  else return find(p->right, x);
}


// 删除数值
TreeNode* remove(TreeNode* p, int x)
{
  if(!p) return nullptr;
  else if(x < p->val) p->left = remove(p->left, x);
  else if(x > p->val) p->right = remove(p->right, x);
  // 没有左孩子
  else if(!p->left) {
    TreeNode* q = p->right;
    delete p;
    return q;
  }
  else if(!p->left->right) {
    TreeNode* q = p->left;
    q->right = p->right;
    delete p;
    return q;
  }
  else {
    TreeNode* q = p->left;
    while(q->right->right) q = q->right;
    TreeNode* r = q->right;
    q->right = r->left;
    r->left = p->left;
    r->right = p->right;
    delete p;
    return r;
  }
  return p;
}
