#include <iostream>
#include <math.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    int sum = 0;
    int weight = 0;
    void convert(ListNode* node) {
        if (node == nullptr)
            return;

        convert(node->next);
        
        if (node->val == 1)
            sum += pow(2, weight);

        weight++;
        return;
    }

public:
    int getDecimalValue(ListNode* head) {
        convert(head);
        return sum;
    }
};