//==============================================================================
// 5. Longest Palindromic Substring
// C++
// Tag: String
//==============================================================================
// Summary:
// https://leetcode.com/problems/longest-palindromic-substring/#/description

class Solution {
public:
    string longestPalindrome(string s) {
	string res;
    	int position = 0;
        int maxLength = 0;

    	if (s.length() <= 1) {
            return res = s;
        }
	
	for (int i = 0; i < s.length(); i++) { 
            int j = i;
            int k = i;
            while (j < s.length() - 1 && s[j] == s[j + 1]) {
            	j++;
            }
	    while (k > 0 && j < s.length() - 1 && s[k - 1] == s[j + 1]) {
            	j++;
            	k--;
            }
            if (j - k + 1 > maxLength) {
		maxLength = j - k + 1;
            	position = k; 
            }
    	}

   	return res = = s.substr(position, maxLength);
    }
};
