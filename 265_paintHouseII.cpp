//==============================================================================
// 265. Paint House II
// C++
// Tag: Array(DP)
//==============================================================================
// Summary:
// https://leetcode.com/problems/paint-house-ii/description/

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int res = 0; 
        int n = costs.size();
        int m = 0;
        int minColor1 = -1;
        int minColor2 = -1;
        
        if (n == 0) {
            return res;
        } else {
            m = costs[0].size();
        }
    
        for (int i = 0; i < n; ++i) {
            int lastMinColor1 = minColor1;
            int lastMinColor2 = minColor2;
            minColor1 = -1;
            minColor2 = -1;
            for (int j = 0; j < m; ++j) {
                if (j != lastMinColor1) {
                    costs[i][j] += (lastMinColor1 < 0) ? 0:costs[i - 1][lastMinColor1];
                } else {
                    costs[i][j] += (lastMinColor2 < 0) ? 0:costs[i - 1][lastMinColor2];
                }
                if (minColor1 < 0 || costs[i][j] < costs[i][minColor1]) {
                    minColor2 = minColor1;
                    minColor1 = j;
                } else if (minColor2 < 0 || costs[i][j] < costs[i][minColor2]) {
                    minColor2 = j;
                }
            }
        }
    
        return res = costs[n - 1][minColor1];
    }
};
