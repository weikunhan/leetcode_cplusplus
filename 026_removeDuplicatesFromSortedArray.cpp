//==============================================================================
// 26. Remove Duplicates from Sorted Array
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/#/description

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 0;
        int left = 0;
    
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                left++;
            } else {
                nums[i - left] = nums[i];
            }
        }
        
        return res = nums.size() - left;
    }          
};
