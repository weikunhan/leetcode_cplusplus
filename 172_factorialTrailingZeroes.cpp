//==============================================================================
// 172. Factorial Trailing Zeroes
// C++
// Tag: Math
//==============================================================================
// Summary:
// https://leetcode.com/problems/factorial-trailing-zeroes/description/

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        int tmp = n;
        
        while (tmp > 0) {
            res += tmp / 5;
            tmp /= 5;
        }
        
        return res;
    }
};
