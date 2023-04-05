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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* left = head;
        ListNode* keep = head;
        ListNode* right = head;

        // the situation head node val is >= x
        if (left->val >= x)
        {
            while (left != nullptr && left->val >= x)
            {
                left = left->next;
                if (keep->next != left)
                    keep = keep->next;
            }

            if (left == nullptr)
                return head;
            
            keep->next = left->next;
            left->next = head;
            head = left;
            right = keep->next;
        }
        else
        {
            while (left->next != nullptr && left->next->val < x)
                left = left->next;
            if (left->next == nullptr) return head;
            keep = left;
            right = left->next;
        }

        while (right != nullptr)
        {
            if (right->val < x)
            {
                keep->next = right->next;
                right->next = left->next;
                left->next = right;

                left = left->next;
                right = keep->next;
            }
            else
            {
                keep = right;
                right = right->next;
            }
        }

        return head;
            
    }
};