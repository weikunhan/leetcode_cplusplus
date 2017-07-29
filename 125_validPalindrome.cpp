//==============================================================================
// 125. Valid Palindrome
// C++
// Tag: String(2 Pointers)
//==============================================================================
// Summary:
// https://leetcode.com/problems/valid-palindrome/description/

class Solution {
public:
    bool isPalindrome(string s) {
        bool res = false;
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
		    if (!isalnum(s[left])) {
                ++left;
            } else if (!isalnum(s[right])) {
                --right;
            } else {
			          if (tolower(s[left++]) != tolower(s[right--])) {
                    return res;
                }
		        }
        }
    
        return res = true;
    }
};
