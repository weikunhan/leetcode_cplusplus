//==============================================================================
// 123. Best Time to Buy and Sell Stock III
// C++
// Tag: Array(DP)
//==============================================================================
// Summary:
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> profit(3, vector<int>(prices.size()));
        int res = 0;
        
        if (prices.size() <= 1) {
            return res;
        }

        for (int i = 1; i <= 2; ++i) {
            int tmpMax = profit[i - 1][0] - prices[0];
            for (int j = 1; j < prices.size(); ++j) {
                profit[i][j] = max(profit[i][j - 1], prices[j] + tmpMax);
                tmpMax = max(tmpMax, profit[i - 1][j] - prices[j]);
                res = max(profit[i][j], res);
            }
        }
        
        return res;
    }
};
