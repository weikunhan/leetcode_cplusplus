//==============================================================================
// 209. Minimum Size Subarray Sum
// C++
// Tag: Array(2 Pointers, without Binary Search)
//==============================================================================
// Summary:
// https://leetcode.com/problems/minimum-size-subarray-sum/description/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int res = INT_MAX;
        
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i]; 
            while (sum >= s) {
                res = min(res, i - left + 1);
                sum -= nums[left++];
            }
        }
        
        return (res == INT_MAX) ? 0:res;
    }
};
