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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || right-left == 0) return head;
        ListNode sentinel(0, head);
        ListNode* keep = &sentinel;
        int count = 1;
        while (keep->next != nullptr && count != left)
        {
            keep = keep->next;
            count++;
        }
        if (keep->next == nullptr) return head;
        

        // now keep is pointing to the node before left
        ListNode* p = keep->next;
        ListNode* q = keep->next;
        ListNode* r = keep->next->next;

        while (r != nullptr && count!= right)
        {
            p = q;
            q = r;
            r = r->next;
            q->next = p;
            count++;
        }
        if (r == nullptr) keep->next->next = nullptr;
        else keep->next->next = r;
        if (keep->next == head) head = q;
        else keep->next = q;
 
        return head;
        
    }
};