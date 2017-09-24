//==============================================================================
// 280. Wiggle Sort
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/wiggle-sort/description/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (((i & 1) && nums[i] < nums[i - 1]) || (!(i & 1) && nums[i] > nums[i - 1])) {
                swap(nums[i], nums[i - 1]);
            }
        }
    }
};
