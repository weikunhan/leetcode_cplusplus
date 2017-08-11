//==============================================================================
// 225. Implement Stack using Queues
// C++
// Tag: Design(Stack)
//==============================================================================
// Summary:
// https://leetcode.com/problems/implement-stack-using-queues/description/

class MyStack {
public:    
    /** Initialize your data structure here. */
    MyStack() {}
    
    /** Push element x onto stack. */
    void push(int x) {
        tables.push(x);
	    
        for (int i = 0; i < tables.size() - 1; ++i) {
	    tables.push(tables.front());
	    tables.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int tmp = tables.front();
        tables.pop();
        
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        return tables.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return tables.empty();
    }
    
private:
    queue<int> tables;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
