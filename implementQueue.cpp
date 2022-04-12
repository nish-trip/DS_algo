#include "test.h"

class MyQueue {
public:
    stack<int>enq, deq;
    MyQueue() {}
    
    void push(int x) {
        enq.push(x);
    }
    
    int pop() {
        if(!deq.empty()){
            int ret = deq.top();
            deq.pop();
            return ret;
        }
        while(!enq.empty()){
            deq.push(enq.top());
            enq.pop();
        }
        int ret = deq.top();
        deq.pop();
        return ret;
    }
    
    int peek() {
        if(!deq.empty()){
            return deq.top();
        }
        while(!enq.empty()){
            deq.push(enq.top());
            enq.pop();
        }
        return deq.top();
    }
    
    bool empty() {
        return deq.empty() && enq.empty();
    }
};