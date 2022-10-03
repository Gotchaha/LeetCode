#include <vector>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr)
            return nullptr;
        
        vector<ListNode*> v;
        ListNode* it = head;
        int index = 1;
        while (it != nullptr)
        {
            v.push_back(it);
            it = it->next;   
        }

        if (n == v.size())
            head = head->next;
        else
        {
            it = v[v.size()-n-1];
            it->next = it->next->next;
        }    
        

        return head;
        
    }
};