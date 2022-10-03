#include <iostream>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* it1 = list1;
        ListNode* it2 = list2;
        ListNode* x = new ListNode();
        ListNode* head = x; // x as a temporary dummy node
        while (it1 != nullptr || it2 != nullptr)
        {
            if (it2 == nullptr)
            {
                x->next = it1;
                break;
            }
            if (it1 == nullptr)
            {
                x->next = it2;
                break;
            }

            if (it1->val <= it2->val)
            {
                x->next = it1;
                x = x->next;
                it1 = it1->next;
            }
            else
            {
                x->next = it2;
                x = x->next;
                it2 = it2->next;
            }
        }
        head = head->next;
        return head;
    }
};