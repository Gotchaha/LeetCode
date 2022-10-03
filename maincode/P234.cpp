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
    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr)
            return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* rev = nullptr;
        ListNode* tmp = nullptr;

        // locate the mid and reverse the first half
        while (fast && fast->next)
        {
            fast = fast->next->next;
            
            tmp = rev;
            rev = slow;
            slow = slow->next;
            rev->next = tmp;
        }

        tmp = slow;

        // if list length is odd
        if (fast)
            slow = slow->next;

        // compare and restore
        ListNode* res = nullptr;
        bool flag = true;
        while (slow)
        {
            if (rev->val != slow->val)
                flag = false;

            if (res) tmp = res;
            res = rev;
            rev = rev->next;
            res->next = tmp;

            slow = slow->next;
            
        }
        
        return flag;

    }
};