//==============================================================================
// 67. Add Binary
// C++
// Tag: Math
//==============================================================================
// Summary:
// https://leetcode.com/problems/add-binary/#/description

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry = 0; 
        int i = a.length() - 1; 
        int j = b.length() - 1;
        
        while (i >= 0 || j >= 0 || carry == 1) {
            carry += i >= 0 ? a[i--] - '0':0;
            carry += j >= 0 ? b[j--] - '0':0;
            res = to_string(carry % 2) + res;
            carry /= 2;
        }
        
        return res;
    }
};
