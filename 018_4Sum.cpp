//==============================================================================
// 18. 4Sum
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/4sum/#/description

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        
        if (nums.size() < 4)  {
            return res;
        }
        
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size() - 2; j++) {
                int left = j + 1;
                int right = nums.size() - 1;
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                while (left < right) {
                    int sum = nums[left] + nums[right] + nums[i] + nums[j];
                    if (sum > target) {
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        res.push_back(vector<int> {nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) {          
                            left++;
                        }
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        left++; 
                        right--;
                    }
                }
            }
        }
        
        return res;
    }
};
