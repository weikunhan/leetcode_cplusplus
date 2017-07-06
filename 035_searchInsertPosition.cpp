//==============================================================================
// 35. Search Insert Position
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/search-insert-position/#/description

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int res = 0;
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > target) {
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                return res = mid;
            }
        }

        return res = low;
    }
};
