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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        const int SENTINELNUM = -1000;
        ListNode* anchor = new ListNode(SENTINELNUM, head);
        ListNode* former = head;
        ListNode* latter = head->next;

        while (latter != nullptr)
        {
            if (latter->val == former->val)
            {
                while (latter != nullptr && latter->val == former->val)
                    latter = latter->next;

                if (anchor->val == SENTINELNUM)
                    head = latter;
                else anchor->next = latter;

                if (latter == nullptr)
                    break;
                former = latter;
                latter = latter->next;
            }
            else
            {
                anchor = former;
                former = latter;
                latter = latter->next;
            }
            
        }

        return head;
        
    }
};