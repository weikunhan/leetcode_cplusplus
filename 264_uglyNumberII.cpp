//==============================================================================
// 264. Ugly Number II
// C++
// Tag: Math(DP, without Heap)
//==============================================================================
// Summary:
// https://leetcode.com/problems/ugly-number-ii/description/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res;
        int factor2 = 0;
        int factor3 = 0;
        int factor5 = 0;

        if(n <= 0) {
            return 0;
        } else {
             res = vector<int> (n, 0);
        }

        res[0] = 1;
        
        for(int i  = 1; i < n ; ++i) {
            res[i] = min(res[factor2] * 2, min(res[factor3] * 3, res[factor5] * 5));
            if (res[i] == res[factor2] * 2) {
                ++factor2;
            }
            if (res[i] == res[factor3] * 3) {
                ++factor3;
            }
            if (res[i] == res[factor5] * 5) {
                ++factor5;
            }
        }
        
        return res[n-1];
    }
};
