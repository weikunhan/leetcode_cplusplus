//==============================================================================
// 279. Perfect Squares
// C++
// Tag: Math(DP, without BFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/perfect-squares/description/

class Solution {
public:
    int numSquares(int n) {
        vector<int> res;
        
        if (n <= 0) {
            return res[0];
        } else {
            res =  vector<int> (n + 1, INT_MAX);
        }
        
        res[0] = 0;
            
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                res[i] = min(res[i], res[i - j * j] + 1);
            }
        }
        
        return res[n];
    }
};
