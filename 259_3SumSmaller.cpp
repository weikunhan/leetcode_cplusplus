//==============================================================================
// 259. 3Sum Smaller
// C++
// Tag: Array(2 Pointers)
//==============================================================================
// Summary:
// https://leetcode.com/problems/3sum-smaller/description/

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int res = 0;
        sort(nums.begin(), nums.end());
        
        if (nums.size() < 2) {
            return res;
        }
    
        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] < target) {
                    res += right - left;
                    ++left;
                } else {
                    --right;
                }
            }
        }
        
        return res;
    }
};
