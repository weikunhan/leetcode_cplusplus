//==============================================================================
// 227. Basic Calculator II
// C++
// Tag: String
//==============================================================================
// Summary:
// https://leetcode.com/problems/basic-calculator-ii/description/

class Solution {
public:
    int calculate(string s) {
        stack<int> tables;
        char sign = '+';
        int res = 0;
        int sum = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                sum = 10 * sum + s[i] - '0';
            }
            if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size() - 1) {
                if (sign == '+') {
                    tables.push(sum);
                }
                if (sign == '-') {
                    tables.push(-sum);
                }
                if (sign == '*' ) {
                    int tmp = tables.top() * sum;
                    tables.pop();
                    tables.push(tmp);
                }
                if (sign == '/') {
                    int tmp = tables.top() / sum;
                    tables.pop();
                    tables.push(tmp);
                }
                sign = s[i];
                sum = 0;
            }
        }
        
        while (!tables.empty()) {
            res += tables.top();
            tables.pop();
        }
        
        return res;
    }
};
