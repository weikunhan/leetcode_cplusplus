class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = -1; 
        int low = 0;
        int high = nums.size() - 1;
        
        if (nums.empty()) {
            return res;
        }
        
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return res = mid;
            }
            if (nums[low] <= nums[mid]) {
                if (target < nums[mid] && target >= nums[low]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        
        return res = nums[low] == target ? low:res;
    }
};
