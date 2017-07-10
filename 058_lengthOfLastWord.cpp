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
        
        while (i >= 0 && s[last] == ' ') {
            i--;
        }
        
        while (i >= 0 && s[last] != ' ') {
            res++;
            i--;
        }
        
        return res;
    }
};
