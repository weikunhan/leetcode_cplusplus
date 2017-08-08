//==============================================================================
// 213. House Robber II
// C++
// Tag: Array(DP)
//==============================================================================
// Summary:
// https://leetcode.com/problems/house-robber-ii/description/

class Solution {
public:
    int rob(vector<int>& nums) {
        int res = 0;
        int max1 = 0;
        int max2 = 0;
        int prevMax1 = 0;
        int prevMax2 = 0;
        
        if (nums.empty()) {
            return res;
        }
        
        if (nums.size() == 1) {
            return res = nums[0];
        }
        
        for (int j = 1; j < nums.size(); ++j) {
            int tmp = max1;
            max1 = nums[j] + prevMax1;
            prevMax1 = max(prevMax1, tmp);
        }
        
        for (int j = 0; j < nums.size() - 1; ++j) {
            int tmp = max2;
            max2 = nums[j] + prevMax2;
            prevMax2 = max(prevMax2, tmp);
        }
        
        max1 = max(max1, prevMax1);
        max2 = max(max2, prevMax2);
        
        return res = max(max1, max2);
    }
};
