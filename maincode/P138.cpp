#include <iostream>
#include <unordered_map>
#include <vector>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* it = head;
        if (it == nullptr) return nullptr;

        std::unordered_map<Node*, int> map;
        map[nullptr] = 0;
        int n = 1;
        while (it != nullptr){
            map[it] = n;

            n++;
            it = it->next;
        }

        std::vector<Node*> res(n);
        res[0] = nullptr;
        it = head;
        for (int i=1; i<n; i++){
            res[i] = new Node(it->val);
            it = it->next;
        }

        it = head;
        for (int i=1; i<n; i++){
            if (i == n-1) res[i]->next = nullptr;
            else res[i]->next = res[i+1];

            res[i]->random = res[map[it->random]];
            it = it->next;
        }

        return res[1];

    }
};

void printList(Node* head) {
    std::vector<Node*> nodes;
    std::unordered_map<Node*, std::size_t> indices;

    for (Node* current = head; current != nullptr; current = current->next) {
        indices[current] = nodes.size();
        nodes.push_back(current);
    }

    std::cout << '[';
    for (std::size_t i = 0; i < nodes.size(); ++i) {
        if (i != 0) {
            std::cout << ',';
        }

        std::cout << '[' << nodes[i]->val << ',';
        if (nodes[i]->random == nullptr) {
            std::cout << "null";
        } else {
            std::cout << indices.at(nodes[i]->random);
        }
        std::cout << ']';
    }
    std::cout << "]\n";
}

int main() {
    Node* first = new Node(7);
    Node* second = new Node(13);
    Node* third = new Node(11);
    Node* fourth = new Node(10);
    Node* fifth = new Node(1);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    second->random = first;
    third->random = fifth;
    fourth->random = third;
    fifth->random = first;

    Solution solution;
    Node* copiedHead = solution.copyRandomList(first);
    printList(copiedHead);

    return 0;
}
