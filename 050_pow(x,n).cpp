//==============================================================================
// 50. Pow(x, n)
// C++
// Tag: Math
//==============================================================================
// Summary:
// https://leetcode.com/problems/powx-n/#/description

class Solution {
public:
    double myPow(double x, int n) {
    	double res = 0;
    	unsigned long long exponent = 0;
        
        if (n == 0) {
            return res = 1;
        } else {
            res = 1;
        }
        
    	if (n < 0) {
    		exponent = -n;
    		x = 1 / x;
    	} else {
    		exponent = n;
    	}
        
		while (exponent > 0) {
			if (exponent & 1) {
				res *= x;
            }
			x *= x;
			exponent >>= 1;
		}
        
		return res;
    }
};
