//==============================================================================
// 20. Valid Parentheses
// C++
// Tag: Stack
//==============================================================================
// Summary:
// https://leetcode.com/problems/valid-parentheses/#/description

class Solution {
public:
    bool isValid(string s) {
        stack<char> characters;
        bool res = false;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '('|| s[i] == '{' || s[i] == '[') {
                characters.push(s[i]);
            } else {
                if(characters.empty()) {
                    return res = false;
                }
                if(s[i] == ')' && characters.top() != '(') {
                    return res = false;
                }
                if(s[i] == '}' && characters.top() != '{') {
                    return res = false;
                }
                if(s[i] == ']' && characters.top() != '[') {
                    return res = false;
                }
                characters.pop();
            }
        }
        
        return res = characters.empty();
    }
};
