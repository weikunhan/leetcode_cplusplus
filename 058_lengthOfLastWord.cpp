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
        int last = s.length() - 1;
        
        while (last >= 0 && s[last] == ' ') {
            last--;
        }
        
        while (last >= 0 && s[last] != ' ') {
            res++;
            last--;
        }
        
        return res;
    }
};
