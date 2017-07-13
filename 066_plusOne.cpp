//==============================================================================
// 66. Plus One
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/plus-one/#/description

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      	vector<int> res;
        
	for (int i = digits.size() - 1; i >= 0; --i) {
	    if (digits[i] == 9) {
		digits[i] = 0;
	    } else {
	        ++digits[i];
		return res = digits;
	    }
	}
		    
        digits[0] = 1;
	digits.push_back(0); 
        
        return res = digits;
    }
};
