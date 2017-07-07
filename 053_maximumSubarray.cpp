//==============================================================================
// 53. Maximum Subarray
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/maximum-subarray/#/description

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = 0;
        int sum = 0;
        
        if (nums.empty()) {
            return res;
        } else {
            res = nums[0];
        }
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            res = max(sum, res);
            sum = max(sum, 0);
        }
        
        return res;
    }
};
