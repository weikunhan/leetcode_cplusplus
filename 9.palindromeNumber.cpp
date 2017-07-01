
//==============================================================================
// 9. Palindrome Number
// C++
// Tag: Math
//==============================================================================
// Summary:
// https://leetcode.com/problems/palindrome-number/#/description

class Solution {
public:
    bool isPalindrome(int x) {
        bool res;
        int sum = 0;
        
        if(x < 0 || (x != 0 && x % 10 == 0)) {
            res = false;
            return res;
        }
 
        

        
        while(x> sum) {
            sum = sum * 10 + x % 10;
            x /= 10;
        }

        res = sum == x || x == sum / 10 ? true:false;
        return res;
    }
};
