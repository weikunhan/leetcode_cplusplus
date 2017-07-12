//==============================================================================
// 65. Valid Number
// C++
// Tag: Math
//==============================================================================
// Summary:
// https://leetcode.com/problems/valid-number/#/description

class Solution {
public:
    bool isNumber(string s) {
        bool res = false;
        bool flag = false;
        int i = 0; 
        int point = 0;
        int digit = 0;
        
        while (i < s.length() && isspace(s[i])) {
            i++;
        }
        
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            i++;
        }
        
        while (i < s.length() && (isdigit(s[i]) || s[i] == '.')) {
            if (isdigit(s[i])) {
                digit++;
            }
            if (s[i] == '.') {
                point++;
            }
            i++;
            flag = true;
        }
        
        if (digit == 0 || point > 1) {
            return res;
        }
        
        if (i < s.length() && s[i] == 'e') {
            i++;
            flag = false;
            if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
                i++;
            }
            while (i < s.length() && isdigit(s[i])) {
                i++;
                flag = true;
            }
        }
        
        while (i < s.length() && isspace(s[i])) {
            i++;
        }
        
        return res = flag && i == s.length();
    }
};
