//==============================================================================
// 171. Excel Sheet Column Number
// C++
// Tag: Math
//==============================================================================
// Summary:
// https://leetcode.com/problems/excel-sheet-column-number/description/

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        
        for (int i = 0 ; i < s.size(); ++i) {
            res = res * 26 + (s[i] - 'A' + 1);
        }
        
        return res;
    }
};
