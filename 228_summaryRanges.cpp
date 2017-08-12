//==============================================================================
// 228. Summary Ranges
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/summary-ranges/description/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int left = 0;
        int right = 0;
        
        for (int i = 0; i < nums.size(); i = right + 1) {
            left = i;
            right = i;
            while (right + 1 < nums.size() && nums[right + 1] == nums[right] + 1) {
                ++right;
            }
            if (right > left) {
                res.push_back(to_string(nums[left]) + "->" + to_string(nums[right]));
            } else {
                res.push_back(to_string(nums[left]));
            }
        }
        
        return res;
    }
};
