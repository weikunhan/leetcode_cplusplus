//==============================================================================
// 162. Find Peak Element
// C++
// Tag: Array(Binary Search)
//==============================================================================
// Summary:
// https://leetcode.com/problems/find-peak-element/description/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int res = 0;
        
        while (low < high) {
            int mid1 = low + (high - low ) / 2;
            int mid2 = mid1 + 1;
            if (nums[mid1] < nums[mid2]) {
                low = mid2;
            } else {
                high = mid1;
            }
        }
        
        return res = low;
    }
};
