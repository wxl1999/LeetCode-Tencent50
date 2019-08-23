#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
private:
    int BOTH_PENDING = 2;
    int LEFT_DONE = 1;
    int BOTH_DONE = 0;

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, int>> s;
        s.push(pair<TreeNode*, int>(root, BOTH_PENDING));
        bool one_node_found = false;
        TreeNode* LCA = NULL;
        TreeNode* child = NULL;

        while(!s.empty()) {
            pair<TreeNode*, int> top = s.top();
            TreeNode* parent = top.first;
            int parent_state = top.second;

            if (parent_state != BOTH_DONE) {
                if (parent_state == BOTH_PENDING) {
                    if (parent->val == p->val || parent->val == q->val) {
                        if (one_node_found) {
                            return LCA;
                        }
                        else {
                            one_node_found = true;
                            LCA = s.top().first;
                        }
                    }
                    child = parent->left;
                }
                else {
                    child = parent->right;
                }
                s.pop();
                s.push(pair<TreeNode*, int>(parent, parent_state - 1));

                if (child) {
                    s.push(pair<TreeNode*, int>(child, BOTH_PENDING));
                }
            }
            else {
                if (one_node_found && LCA->val == s.top().first->val) {
                    s.pop();
                    LCA = s.top().first;
                }
                else s.pop();
            }
        }
        return NULL;
    }
};