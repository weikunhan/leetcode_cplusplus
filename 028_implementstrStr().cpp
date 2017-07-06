//==============================================================================
// 28. Implement strStr()
// C++
// Tag: String
//==============================================================================
// Summary:
// https://leetcode.com/problems/implement-strstr/#/description

class Solution {
public: 
    int strStr(string haystack, string needle) {
        int res = -1;
        
        if (needle.length() == 0) {
            return res = 0;
        }
        
        for (int i = 0; i < haystack.length(); i++) {
            int left = 0;
            while (left < needle.length()) {
                if (i + left  == haystack.length()) {
                    return res = -1;
                }
                if (needle[left] != haystack[i + left]) {
                    break;
                }
                left++;
            }
            if (left == needle.length()) {
                return res = i;
            }
        }

        return res;
    }
};
