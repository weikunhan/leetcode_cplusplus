//==============================================================================
// 34. Search for a Range
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/search-for-a-range/#/description

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        
        if (low > high) {
            return res = {-1, -1};
        }
        
        int low = 0;
        int high = nums.size() - 1;
        int left = 0;
        int right = 0;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                left = mid;
                right = mid;
                break;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        while(left > 0  && nums[left-1] == target) {
            left--;
        }
        
        while(right < nums.size() - 2 && nums[right + 1] == target){
            right++;
        }
        
        return res = {left, right};
    }
};
