//==============================================================================
// 150. Evaluate Reverse Polish Notation
// C++
// Tag: String(Stack)
//==============================================================================
// Summary:
// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> tables;
        int res = 0;
        
        for (int i = 0; i < tokens.size(); ++i) {
            int number1 = 0;
            int number2 = 0;
	    if (tokens[i] == "+") {
                number1 = tables.top();
                tables.pop();
                number2 = tables.top();
                tables.pop();
                int sum = number2 + number1;
                tables.push(sum);
            } else if (tokens[i] == "-") {
                number1 = tables.top();
                tables.pop();
                number2 = tables.top();
                tables.pop();
                int difference = number2 - number1;
                tables.push(difference);                
            } else if (tokens[i] == "*") {
                number1 = tables.top();
                tables.pop();
                number2 = tables.top();
                tables.pop();
                int product = number2 * number1;
                tables.push(product);                
            } else if (tokens[i] == "/") {
                number1 = tables.top();
                tables.pop();
                number2 = tables.top();
                tables.pop();
                int quotient = number2 / number1;
                tables.push(quotient);                
            } else {
                tables.push(stoi(tokens[i]));
            }
        }
        
        return res = tables.top();
    }
};
