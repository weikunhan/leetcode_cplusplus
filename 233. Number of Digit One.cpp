//==============================================================================
// 233. Number of Digit One
// C++
// Tag: Math
//==============================================================================
// Summary:
// https://leetcode.com/problems/number-of-digit-one/description/

class Solution {
public:
    int countDigitOne(int n) {
        int res = 0; 
        int factor = 1; 
        int tmp = n;
        
        while (tmp > 0) {
    	    int digit = tmp / 10;
            int indicator = tmp % 10;
            int amount = 0;
    	    if (indicator == 0) {
                amount = 0;
            } else if (indicator > 1) {
                amount = factor;
            } else {
                amount = n % factor + 1;
            }
    	    res += digit * factor + amount;
    	    factor *= 10;
    	    tmp /=10;
        }
        
        return res;
    }
};
