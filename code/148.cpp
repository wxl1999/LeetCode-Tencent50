#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int len = 0;
        ListNode *h = head;
        while (h) {
            ++len;
            h = h->next;
        }
        h = new ListNode(0);
        h->next = head;
        for (int size = 1; size < len; size <<= 1) {
            auto cur = h->next; 
            auto tail = h;

            while (cur) {
                auto left = cur;
                auto right = cut(left, size);
                cur = cut(right, size);

                tail->next = merge(left, right);
                while (tail->next)
                    tail = tail->next;
            }
        }
        return h->next;
    }

    ListNode* cut(ListNode *h, int size) {
        ListNode *p = h;
        while (p && --size) 
            p = p->next;

        if (!p)
            return nullptr;

        auto next = p->next;
        p->next = NULL;
        return next;
    }

    ListNode* merge(ListNode *left, ListNode *right) {
        ListNode *h = new ListNode(0), *p = h;
        while (left && right) {
            if (left->val < right->val) {
                p->next = left;
                left = left->next;
            }
            else
            {
                p->next = right;
                right = right->next;                
            }
            p = p->next;
        }

        p->next = left ? left : right;

        return h->next;
    }
};