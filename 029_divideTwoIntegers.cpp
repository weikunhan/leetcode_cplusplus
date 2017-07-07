//==============================================================================
// 29. Divide Two Integers
// C++
// Tag: Math
//==============================================================================
// Summary:
// https://leetcode.com/problems/divide-two-integers/#/description

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool negative = (dividend < 0) ^ (divisor < 0);
        long long high = abs((long long)dividend);
        long long low = abs((long long)divisor);
        int res = 0; 
        
        while (low <= high) {
            long long i = low;
            long long j = 1;
            while (i < high >> 1) { 
                i <<= 1; 
                j <<= 1; 
            }
            res += j; 
            high -= i;
            if (res == INT_MIN) {
                return res = negative ? INT_MIN:INT_MAX;
            }
        }
        
        return res = negative ? -res:res;
    }
};
