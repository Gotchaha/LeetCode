//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr or head->next == nullptr)
            return head;

        ListNode* anchor = new ListNode(0, head);
        ListNode* former = nullptr;
        ListNode* latter = nullptr;

        while (anchor->next != nullptr && anchor->next->next != nullptr)
        {
            former = anchor->next;
            latter = former->next;

            anchor->next = latter;
            former->next = latter->next;
            latter->next = former;
            if (former == head) head = latter;

            anchor = former;
        }
        
        return head;
        
    }
};