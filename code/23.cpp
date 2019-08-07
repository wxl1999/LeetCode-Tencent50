#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // int k = lists.size();
        ListNode *h = new ListNode(-1), *p = new ListNode(-1);
        h = p;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] == NULL) {
                lists.erase(lists.begin() + i);
                i--;
            }
        }
        // return lists[2];
        while (lists.size() > 1) {
            int tmp = lists[0]->val;
            int index = 0;
            for (int i = 1; i < lists.size(); i++) {
                if (lists[i]->val < tmp) {
                    tmp = lists[i]->val;
                    index = i;
                }
            }
            p->next = lists[index];
            p = p->next;
            // return p->next;
            lists[index] = lists[index]->next;
            if (lists[index] == NULL)
                lists.erase(lists.begin() + index);
        }
        if (lists.size())
            p->next = lists[0];
        // return p;
        // h = p->next;
        return h->next;
    }
};