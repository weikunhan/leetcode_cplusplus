//==============================================================================
// 12. Integer to Roman
// C++
// Tag: Math
//==============================================================================
// Summary:
// https://leetcode.com/problems/integer-to-roman/#/description

class Solution {
public:
    string intToRoman(int num) {
        string res;
        vector<string> M = {"", "M", "MM", "MMM"};
        vector<string> C = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> X = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> I = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        
        return res = M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[num % 10];
    }
};
