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
    // DFS
    int maxDepth(TreeNode* root) {
        if (!root)  return 0;
        stack<pair<TreeNode*, int>> s;

        TreeNode *p = root;
        int res = 1;
        int depth = 0;
        while (!s.empty() || p) {
            while (p) {
                depth++;                
                s.push(pair<TreeNode*, int>(p, depth));
                p = p->left;
            }
            p = s.top().first;
            depth = s.top().second;
            res = max(depth, res);
            s.pop();
            p = p->right;
        }
        return res;
    }
    // BFS
    int maxDepth(TreeNode* root) {
        if (!root)  return 0;
        deque<TreeNode*> q;
        TreeNode *t;
        q.push_back(root);
        int depth = 0;
        while (!q.empty()) {
            ++depth;
            int width = q.size();
            while (width) {
                t = q.front();
                q.pop_front();
                if (t->left)
                    q.push_back(t->left);
                if (t->right)
                    q.push_back(t->right);
                --width;
            }
        }
        return depth;
    }
};

