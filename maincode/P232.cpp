#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> s;
    stack<int> aux;

    void transferInOrder(stack<int>& a, stack<int>& b) {
        /*transfer all elements in a to b, in first-pop-then-push order */
        while (!a.empty())
        {
            int temp = a.top();
            b.push(temp);
            a.pop();
        }
        
    }
    
    void push(int x) {
        if (s.empty()) s.push(x);
        else {
            transferInOrder(s, aux);
            s.push(x);
            transferInOrder(aux, s);
        }
    }
    
    int pop() {
        int elem = s.top();
        s.pop();
        return elem;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};

int main() {
/** Your MyQueue object will be instantiated and called as such: **/
    MyQueue* obj = new MyQueue();
    obj->push(1);
    //obj->push(2);
    int param_2 = obj->peek();
    int param_3 = obj->pop();
    bool param_4 = obj->empty();
    
    cout << param_2 << " " << param_3 << " " << param_4 << "\n";

    return 0;
}