//==============================================================================
// 224. Basic Calculator
// C++
// Tag: Math(Stack)
//==============================================================================
// Summary:
// https://leetcode.com/problems/basic-calculator/description/

class Solution {
public:
    int calculate(string s) {
        stack<int> tables;
        stack<int> signs;
        int sum = 0;
        int res = 0;
        int sign = 1;
        
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                sum = sum * 10 + s[i] - '0';
            } else {
                res += sign * sum;
                sum = 0;
                if (s[i] == '+') {
                    sign = 1;
                }
                if (s[i] == '-') {
                    sign = -1;
                }
                if (s[i] == '(') {
                    tables.push(res);
                    signs.push(sign);
                    res = 0;
                    sign = 1;
                }
                if (s[i] == ')' && signs.size()) {
                    res = signs.top() * res + tables.top();
                    signs.pop(); 
                    tables.pop();
                }
            }
        }
        
        return res += sign * sum;
    }
};
