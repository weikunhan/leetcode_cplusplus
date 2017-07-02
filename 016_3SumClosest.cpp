//==============================================================================
// 16. 3Sum Closest
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/3sum-closest/#/description

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0;
        sort(nums.begin(), nums.end());
        
        if (nums.size() < 3) {
            return res;
        } else {
            res = nums[0] + nums[1] + nums[2];
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return res = target;
                }
                if (abs(sum - target) < abs(res - target)) {
                    res = sum;
                }
                if (sum > target) {
                    k--;
                } else {
                    j++;
                }
            } 
        }
        
        return res;
    }
};
