//==============================================================================
// 201. Bitwise AND of Numbers Range
// C++
// Tag: Bit Manipulation
//==============================================================================
// Summary:
// https://leetcode.com/problems/bitwise-and-of-numbers-range/description/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        int moveFactor = 1;
        
        while (m != n) {
            m >>= 1;
            n >>= 1;
            moveFactor <<= 1;
        }
        
        return res = m * moveFactor;
    }
};
