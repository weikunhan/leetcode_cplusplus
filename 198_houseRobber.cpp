//==============================================================================
// 198. House Robber
// C++
// Tag: Array(DP)
//==============================================================================
// Summary:
// https://leetcode.com/problems/house-robber/description/

class Solution {
public:
    int rob(vector<int>& nums) {
        int res = 0;
        int prevMax = 0;
        
        for (int j = 0; j < nums.size(); ++j) {
            int tmp = res;
            res = nums[j] + prevMax;
            prevMax = max(prevMax, tmp);
        }
        
        return res = max(res, prevMax);
    }
};
