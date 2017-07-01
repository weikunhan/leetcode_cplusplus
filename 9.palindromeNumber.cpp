//==============================================================================
// 9. Palindrome Number
// C++
// Tag: Math
//==============================================================================
// Summary:
// https://leetcode.com/problems/palindrome-number/#/description

class Solution {
public:
    bool isPalindrome(int x) {
	bool res = false;
	int reverseInteger = 0; 
	int originalInteger = x;
	    
	if (x < 0) {
	    return res = false;
	}
	
	while (originalInteger) {
	    reverseInteger = reverseInteger * 10 + originalInteger % 10;
	    originalInteger /= 10;
	}
	
	return res = reverseInteger == x;
    }
};
