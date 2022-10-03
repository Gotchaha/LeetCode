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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return head;
        
        ListNode* start = nullptr;
        head = reverse(head, start);
        head->next = nullptr;
        head = start;

        return head;
    }

    ListNode* reverse(ListNode* last, ListNode* &start) {
        if (last->next == nullptr)
        {
            start = last;
            return start;
        }

        last->next = reverse(last->next, start);  // conquer and get the result back at this level
        last->next->next = last;  // combine(deal at this level)

        return last;
    }
};