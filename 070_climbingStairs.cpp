//==============================================================================
// 70. Climbing Stairs
// C++
// Tag: Math(DP)
//==============================================================================
// Summary:
// https://leetcode.com/problems/climbing-stairs/#/description

class Solution {
public:
    int climbStairs(int n) {
        int res = 0;
        int f1 = 1;
        int f2 = 2;
        
        if (n <= 0) {
            return res;
        }
        
        if (n == 1) {
            return res = f1;
        }
        
        if (n == 2) {
            return res = f2;
        }
    
        for (int i = 2; i < n; i++) { 
    	      res = f2 + f1;
    	      f1 = f2;
            f2 = res;
        }
        
        return res;
    }
};
