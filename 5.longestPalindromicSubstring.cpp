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

    	if (s.length() == 0 || s.length() == 1) {
            return s;
        }
	
	for (int i = 0; i < s.length(); i++) { 
            int count1 = i;
            int count2 = i;
            while(count1 < s.length() - 1 && s[count1] == s[count1 + 1]) {
            	++count1;
            }
	    while(count2 > 0 && count1 < s.length() - 1 && s[count2 - 1] == s[count1 + 1]){
            	++count1;
            	--count2;
            }
            if(count1 - count2 + 1 > maxLength){
		maxLength = count1 - count2 + 1;
            	position = count2; 
            }
            res = s.substr(position, maxLength);
    	}

   	return res;
    }
};
