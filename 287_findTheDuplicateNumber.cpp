//==============================================================================
// 287. Find the Duplicate Number
// C++
// Tag: Array(2 Pointers, Binary Search)
//==============================================================================
// Summary:
// https://leetcode.com/problems/find-the-duplicate-number/description/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = 0;
        int low = 1;
        int high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            int left = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] <= mid) {
                    ++left;
                }
            }
            if (left > mid) {
                high = mid;
            } else {
                low = mid+1;
            }
        }
        
        return res= low;
    }
};
