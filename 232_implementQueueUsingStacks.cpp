//==============================================================================
// 232. Implement Queue using Stacks
// C++
// Tag: Design(Stack)
//==============================================================================
// Summary:
// https://leetcode.com/problems/implement-queue-using-stacks/description/

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {
        helper(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tmp = tables.top();
        tables.pop();
        
        return tmp;
    }
    
    /** Get the front element. */
    int peek() {
        return tables.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return tables.empty();
    }

private:
    stack<int> tables;
    
    void helper(int numberIn) {
        if (tables.empty()) {
            tables.push(numberIn);
            return;
        }
        
        int tmp = tables.top();
        tables.pop();
        helper(numberIn);
        tables.push(tmp);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
