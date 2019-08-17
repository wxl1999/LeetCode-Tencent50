#include <iostream>
#include <vector>
#include <stack>
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
    int kthSmallest(TreeNode* root, int k) {
        int cur = 0;
        int res;
        kthSmallest(root, k, cur, res);
        return res;
    }

    void kthSmallest(TreeNode* root, int k, int &cur, int &res) {
        if (root->left)
            kthSmallest(root->left, k, cur, res);
        ++cur;
        if (k == cur)
            res = root->val;
        else {
            if (root->right)
                kthSmallest(root->right, k, cur, res);
        }
    }
    //非递归
    int kthSmallest(TreeNode* root, int k) {
        int cur = 0;
        stack<TreeNode*> s;
        TreeNode *t = root;
        while (t || !s.empty()) {
            while (t) {
                s.push(t);
                t = t->left;
            }
            if (!s.empty()) {
                t = s.top();
                s.pop();
                ++cur;
                if (cur == k)
                    return t->val;
                t = t->right;
            }
        }
        return 0;
    }
};