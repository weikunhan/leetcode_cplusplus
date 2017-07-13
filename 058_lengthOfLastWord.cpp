//==============================================================================
// 58. Length of Last Word
// C++
// Tag: String
//==============================================================================
// Summary:
// https://leetcode.com/problems/length-of-last-word/#/description

class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int i = s.length() - 1;
        
        while (i >= 0 && isspace(s[i])) {
            --i;
        }
        
        while (i >= 0 && !isspace(s[i])) {
            ++res;
            --i;
        }
        
        return res;
    }
};
