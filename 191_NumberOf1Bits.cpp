//==============================================================================
// 191. Number of 1 Bits
// C++
// Tag: Bit Manipulation
//==============================================================================
// Summary:
// https://leetcode.com/problems/number-of-1-bits/description/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        
        for (int i = 0; i < 32; ++i) {
            if (n >> i & 1) {
               ++res;
            }
        }
        
    	return res;
    }
};
