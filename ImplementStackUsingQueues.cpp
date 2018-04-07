//https://leetcode.com/problems/implement-stack-using-queues/description/
//Implement the following operations of a stack using queues.
//
//push(x) -- Push element x onto stack.
//pop() -- Removes the element on top of the stack.
//top() -- Get the top element.
//empty() -- Return whether the stack is empty.
//Notes:
//You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
//Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
//You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

class MyStack {
    queue<int> mq;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        mq.push(x);
        for(int i=0;i<mq.size()-1;i++)
            mq.push(this->pop());
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = mq.front();
        mq.pop();
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        return mq.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return mq.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
