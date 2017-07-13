//==============================================================================
// 50. Pow(x, n)
// C++
// Tag: Math(Binary Search)
//==============================================================================
// Summary:
// https://leetcode.com/problems/powx-n/#/description

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1; 
        unsigned int high = (n >= 0) ? n:-n;
        int mid = 0;
        
        if (high == 0) {
            return res;
	}

	while (true) {
            if (high & 1) {
		res *= x;
	    }
            high >>= 1;
            x *= x;
	    if (high == mid) {
	        return res = (n < 0) ? 1 / res:res;
            }
        }
    }  
};
