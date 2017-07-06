//==============================================================================
// 27. Remove Element
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/remove-element/#/description

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        int left = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                left++;
            } else {
                nums[i - left] = nums[i];
            }
        }
        
        return res = nums.size() - left;
    }
};
