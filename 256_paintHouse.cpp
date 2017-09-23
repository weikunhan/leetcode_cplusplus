//==============================================================================
// 256. Paint House
// C++
// Tag: Array(DP)
//==============================================================================
// Summary:
// https://leetcode.com/problems/paint-house/description/

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int res = 0;
        int n = costs.size();
        
        if (n == 0) {
            return res;
        }
        
        for (int i = 1; i < n; ++i) {
            costs[i][0] += min(costs[i - 1][1], costs[i - 1][2]);
            costs[i][1] += min(costs[i - 1][0], costs[i - 1][2]);
            costs[i][2] += min(costs[i - 1][1], costs[i - 1][0]);
        }
        
        return res = min(min(costs[n - 1][0], costs[n - 1][1]), costs[n - 1][2]);
    }
};
