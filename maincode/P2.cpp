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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* it1 = l1;
        ListNode* it2 = l2;
        ListNode* L = new ListNode();
        ListNode* itL = L;
        int carry = 0;
        int val = 0;
        int sum = 0;


        while (it1 != nullptr || it2 != nullptr)
        {
            if (it1 == nullptr)
            {
                while (it2 != nullptr)
                {   
                    sum = it2->val + carry;
                    val = sum%10;
                    carry = sum/10;
                    itL->next = new ListNode(val);
                    itL = itL->next;
                    it2 = it2->next;
                }
            }

            if (it2 == nullptr)
            {
                while (it1 != nullptr)
                {
                    sum = it1->val + carry;
                    val = sum%10;
                    carry = sum/10;
                    itL->next = new ListNode(val);
                    itL = itL->next;
                    it1 = it1->next;
                
                }
            }
            
            if (it1 != nullptr && it2 != nullptr)
            {
                sum = it1->val + it2->val + carry;
                val = sum%10;
                carry = sum/10;
                itL->next = new ListNode(val);
                itL = itL->next;
                it1 = it1->next;
                it2 = it2->next;
            }
        }
        if(carry) itL->next = new ListNode(1);

        L = L->next;
        return L;        
    }
};

int main()
{

    return 0;
}