//==============================================================================
// 7. Reverse Integer
// C++
// Tag: Math
//==============================================================================
// Summary:
// https://leetcode.com/problems/reverse-integer/#/description

class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        
        return res = res < INT_MIN || res > INT_MAX ? 0:res;;
    }
};
