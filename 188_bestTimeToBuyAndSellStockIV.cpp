//==============================================================================
// 188. Best Time to Buy and Sell Stock IV
// C++
// Tag: Array(DP)
//==============================================================================
// Summary:
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int res = 0;

        if (prices.size() <= 1) {
            return res;
        }
        
        if (k >= prices.size()) {
            for (int i = 1; i < prices.size(); ++i) {
                res += max(prices[i] - prices[i - 1], 0);
            }
        } else {
            vector<vector<int>> profit(k + 1, vector<int>(prices.size()));
            for (int i = 1; i <= k; ++i) {
                int tmpMax = profit[i - 1][0] - prices[0];
                for (int j = 1; j < prices.size(); ++j) {
                    profit[i][j] = max(profit[i][j - 1], prices[j] + tmpMax);
                    tmpMax = max(tmpMax, profit[i - 1][j] - prices[j]);
                    res = max(profit[i][j], res);
                }
            }
        }
        
        return res;
    }
};
