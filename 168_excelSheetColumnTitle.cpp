//==============================================================================
// 168. Excel Sheet Column Title
// C++
// Tag: Math
//==============================================================================
// Summary:
// https://leetcode.com/problems/excel-sheet-column-number/description/

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        
        while (n > 0) {
            res = (char)(--n % 26 + 'A') + res;
            n /= 26;
        }
        
        return res;
    }
};
