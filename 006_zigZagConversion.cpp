//==============================================================================
// 6. ZigZag Conversion
// C++
// Tag: String
//==============================================================================
// Summary:
// https://leetcode.com/problems/zigzag-conversion/#/description

class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        int cycle = 2 * numRows - 2;
        
        if (numRows <= 1) {
            return res = s;
        }

        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < s.length(); j = j + cycle) {
                res += s[j];
                int k = j - i + cycle - i;
                if (i > 0 && i < numRows - 1 && k < s.length()) {
                    res += s[k];
                }
            }
        }
        
        return res;
    }
};
