
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
    ListNode* removeElements(ListNode* head, int val) {
        
        while (head != nullptr && head->val == val)
            head = head->next;

        if (head == nullptr)
            return head;

        ListNode* it1 = head->next;
        ListNode* it2 = head;
        
        while (it1 != nullptr)
        {
            if (it1->val == val)
            {
                it2->next = it1->next;
                it1 = it1->next;
            }
            else
            {
                it1 = it1->next;
                it2 = it2->next;
            }
            
        }
        
        return head;
        
    }
};