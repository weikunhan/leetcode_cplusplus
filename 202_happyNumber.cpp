//==============================================================================
// 201. Bitwise AND of Numbers Range
// C++
// Tag: Math(Hash Table)
//==============================================================================
// Summary:
// https://leetcode.com/problems/happy-number/description/

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> tables;
        bool res = false;
        ++tables[n];
        
	    while (tables[n] == 1) {
		    int sum = 0;
		    while (n > 0) {
		        int digit = n % 10;
			    sum += digit * digit;
			    n /= 10;
		    }
		    if (sum == 1) {
			    return res = true;
            } else {
			    n = sum;
                ++tables[n];
            }
	    }
        
	    return res;
    }
};
