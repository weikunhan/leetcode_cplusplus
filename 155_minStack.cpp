//==============================================================================
// 155. Min Stack
// C++
// Tag: Design(Stack)
//==============================================================================
// Summary:
// https://leetcode.com/problems/min-stack/description/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        tables1.push(x);
        
        if (tables2.empty() || x <= tables2.top()) {
            tables2.push(x);
        }
    }
    
    void pop() {
        if (tables1.top() == tables2.top()) {
            tables2.pop();
        }
        
        tables1.pop();
    }
    
    int top() {
        return tables1.top();
    }
    
    int getMin() {
        return tables2.top();
    }
    
private:
    stack<int> tables1;
    stack<int> tables2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
