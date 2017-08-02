//==============================================================================
// 189. Rotate Array
// C++
// Tag: Backtracking
//==============================================================================
// Summary:
// https://leetcode.com/problems/rotate-array/description/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int right = nums.size();
        int left = 0;
        
        while (k %= right) {
            for (int i = 0; i < k ; ++i) { 
                swap(nums[left + i], nums[left + right - k + i]);
            }
            right -= k;
            left += k;
        }
    }
};
