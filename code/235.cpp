#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //递归
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)  return NULL;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if ((left && right) || ((root->val == p->val || root->val == q->val) && (left || right)))
            return root;
        else if (left)  return left;
        else if (right) return right;
        else if (root->val == p->val || root->val == q->val)    return root;
        else return NULL;
    }
    //非递归
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* t = root;
        while (t) {
            if (p->val > t->val && q->val > t->val) 
                t = t->right;
            else if (p->val < t->val && q->val < t->val)
                t = t->left;
            else
            {
                return t;
            }
            
        }
    }
};