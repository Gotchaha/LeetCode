#include <iostream>
using namespace std;



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
    static ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr or head->next == nullptr) return head;
        ListNode* it1 = head->next;
        ListNode* it2 = head;

        while (it1 != nullptr)
        {
            if (it1->val == it2->val)
            {
                it2->next = it1->next;
                it1 = it1->next;   
            }
            else
            {
                it2 = it1;
                it1 = it1->next;
            }
        }
        return head;
    }

};

int main()
{
    ListNode* x2 = new ListNode(2, nullptr);
    ListNode* x1 = new ListNode(2, x2);
    ListNode* head = new ListNode(2, x1);

    ListNode* ans = Solution::deleteDuplicates(head);
    cout << '[';
    ListNode* it = ans;
    while (it != nullptr)
    {
        cout << it->val << ',';
        it = it->next;
    }
    cout << ']';
    
    return 0;
}
