#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> Q;
    queue<int> aux;
    int topIdx, topElem = -1;

    MyStack() {
       topIdx = 0; 
    }
    
    void push(int x) {
        Q.push(x);
        topIdx++;
        topElem = x;
    }

    void reset(queue<int>& a, queue<int>& b) {
        a.swap(b);
        topIdx--;
    }
    
    int pop() {
        for(int i = topIdx ; i != 1; i--) {
            if(i == 2) topElem = Q.front();
            int e = Q.front();
            aux.push(e);
            Q.pop();
        }
        int elem = Q.front();
        Q.pop();
        reset(Q, aux);
        return elem;
    }
    
    int top() {
        return topElem;
    }
    
    bool empty() {
        return topIdx == 0;
    }
};

int main() {
/** Your MyStack object will be instantiated and called as such: **/
    MyStack* obj = new MyStack();
    for (int i = 1; i <= 2; i++)
        obj->push(i);
    int param_2 = obj->pop();
    int param_3 = obj->top();
    int param_3_2 = obj->pop();
    bool param_4 = obj->empty();
    cout << param_2 << " " << param_3 << " " << param_4 << "\n";
    //2 1 1

    return 0;

}