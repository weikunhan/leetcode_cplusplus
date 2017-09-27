//==============================================================================
// 300. Longest Increasing Subsequence
// C++
// Tag: Array(DP, without Binary Search)
//==============================================================================
// Summary:
// https://leetcode.com/problems/longest-increasing-subsequence/description/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<int> maxLength(n, 0);
        
        for (int i = 0; i < n; ++i) {
            maxLength[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j] && maxLength[j] + 1 > maxLength[i]) {
                    maxLength[i] = maxLength[j] + 1;
                }
            }
            res = max(res, maxLength[i]);
        }
        
        return res;
    }
};
