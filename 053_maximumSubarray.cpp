//==============================================================================
// 53. Maximum Subarray
// C++
// Tag: Array(DP)
//==============================================================================
// Summary:
// https://leetcode.com/problems/maximum-subarray/#/description

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int j = nums.size();
        vector<int> sum(j, nums[0]);
        int res = sum[0];
        
        for (int i = 1; i < j; i++) {
            sum[i] = nums[i] + (sum[i - 1] > 0 ? sum[i - 1]:0);
            res = max(res, sum[i]);
        }
        
        return res;
    }
};
