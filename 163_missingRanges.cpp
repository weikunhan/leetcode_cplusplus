//==============================================================================
// 163. Missing Ranges
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/missing-ranges/description/

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > lower) {
                if (nums[i] - 1 == lower) {
                    res.push_back(to_string(lower));
                } else {
                    res.push_back(to_string(lower) + "->" + to_string(nums[i] - 1));
                }
            }
            if (nums[i] == upper) {
                return res;
            }
            lower = nums[i] + 1;
        }
        
        if (lower <= upper) {
            if (lower == upper) {
                res.push_back(to_string(lower));
            } else {
                res.push_back(to_string(lower) + "->" + to_string(upper));
            }
        }
        
        return res;
    }
};
