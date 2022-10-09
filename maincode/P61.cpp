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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;

        int len = 1;
        ListNode* it = head;
        while (it->next != nullptr)
        {
            len++;
            it = it->next;
        }

        if (k%len != 0)
        {
            ListNode* Ntail = head;
            for (int i = 1; i < len-k%len; i++)
                Ntail = Ntail->next;
            
            it->next = head;
            head = Ntail->next;
            Ntail->next = nullptr;
        }

        return head;     
    }
};