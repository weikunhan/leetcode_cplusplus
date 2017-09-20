//==============================================================================
// 263. Ugly Number
// C++
// Tag: Math
//==============================================================================
// Summary:
// https://leetcode.com/problems/ugly-number/description/

class Solution {
public:
    bool isUgly(int num) {
        bool res = false;
        
        if (num <= 0) {
            return res;
        }
        
        for (int i = 2; i < 6; ++i) {
            while (num % i == 0) {
                num /= i;
            }
        }
        
        return res = num == 1;
    }
};
