//==============================================================================
// 15. 3Sum
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/3sum/#/description

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        if (nums.size() < 3) {
            return res;
        }
    
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            while (left < right) {
                int sum = nums[i] + nums [left] + nums[right];
                if (sum > 0) {
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    res.push_back(vector<int> {nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) {          
                        left++;
                    }
                    while (left > right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++; 
                    right--;
                }
            }
        }
        
        return res;
    }
};
