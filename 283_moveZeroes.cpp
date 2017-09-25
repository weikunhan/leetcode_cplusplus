//==============================================================================
// 283. Move Zeroes
// C++
// Tag: Array(2 Pointers)
//==============================================================================
// Summary:
// https://leetcode.com/problems/move-zeroes/description/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = 0;
    
        while (left < nums.size()) {
            if (nums[left] != 0) {
                swap(nums[left], nums[right]);
                ++right;
            }
            ++left;
        }
    }
};
