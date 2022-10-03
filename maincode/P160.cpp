// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr && headB == nullptr)
            return nullptr;

        ListNode* it1 = headA;
        ListNode* it2 = headB;

        while (it1 != it2)
        {
            it1 = it1 == nullptr? headB:it1->next;
            it2 = it2 == nullptr? headA:it2->next;
        }
        
        return it1;
    }
};