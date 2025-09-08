struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head->next == nullptr)
            return head;

        ListNode* sl = new ListNode();
        sl->next = head;

        ListNode* p = head->next;
        sl->next->next = nullptr;

        while (p != nullptr)
        {
            int val = p->val;

            ListNode* prev = sl;
            while (prev->next != nullptr && prev->next->val <= val)
                prev = prev->next;

            ListNode* pnext = p->next;
            if (prev->next != nullptr)
            {
                p->next = prev->next;
                prev->next = p;
            }
            else
            {
                prev->next = p;
                p->next = nullptr;
            }
            p = pnext;
        }

        ListNode* temp=sl;
        sl = sl->next;
        delete temp;
        return sl;
    }
};