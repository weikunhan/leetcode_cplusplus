//==============================================================================
// 121. Best Time to Buy and Sell Stock
// C++
// Tag: Array(DP)
//==============================================================================
// Summary:
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/tabs/description

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int currentMax = 0;
        
        for (int i = 1; i < prices.size(); ++i) {
            currentMax += prices[i] - prices[i - 1];
            currentMax = (currentMax < 0) ? 0:currentMax; 
            res = max(currentMax, res);
        }
        
        return res;
    }
};
