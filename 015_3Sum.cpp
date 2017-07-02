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
    
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1; 
            int k = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            while (j < k) {
                int sum = nums[i] + nums [j] + nums[k];
                if (sum > 0) {
                    k--;
                }
                else if (sum < 0) {
                    j++;
                } else {
                    res.push_back(vector<int> {nums[i], nums[j], nums[k]});
                    while (nums[j] == nums[j + 1]) {          
                        j++;
                    }
                    while (nums[k] == nums[k-1]) {
                        k--;
                    }
                    j++; 
                    k--;
                }
            }
        }
        
        return res;
    }
};
