//==============================================================================
// 459. Repeated Substring Pattern
// C++
// Tag: String
//==============================================================================
// Summary:
// https://leetcode.com/problems/repeated-substring-pattern/description/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        bool res = false;
        int left = 1;
        
        while (left < s.size()) {
            string element = s.substr(0, left);
            string tmp = element;
            while (element.size() < s.size()) {
                element += tmp;
                if (element == s) {
                    return res = true;
                }
            }
            ++left;
        }
        
        return res;
    }
};
