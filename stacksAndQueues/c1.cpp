#include <stack>
using namespace std;

class MyQueue {
public:
    MyQueue() {
        stack<int> sort;
        stack<int> queue;
    }
    
    void push(int x) {
        
        while(!queue.empty()){
            sort.push(queue.top());
            queue.pop();
        }

        queue.push(x);

        while(!sort.empty()){
            queue.push(sort.top());
            sort.pop();
        }

    }
    
    int pop() {
        return queue.pop();
    }
    
    int peek() {
        return queue.top();
    }
    
    bool empty() {
        return queue.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */