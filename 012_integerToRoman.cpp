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
        static const vector<string> M = {"", "M", "MM", "MMM"};
        static const vector<string> C = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        static const vector<string> X = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        static const vector<string> I = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string res;
        
        return res = M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[num % 10];
    }
};
