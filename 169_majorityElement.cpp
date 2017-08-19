//==============================================================================
// 169. Majority Element
// C++
// Tag: Array. without Bit Manipulation
//==============================================================================
// Summary:
// https://leetcode.com/problems/majority-element/description/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;
        int target = 0;
        int number = 0;
        int total = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (number != 0 && target == nums[i]) {
                ++number;
                continue;
            } 
            if (number == 0) {
                target = nums[i];
                ++number;
                continue;
            }
            --number;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (number > 0) {
                if (nums[i] == target) {
                    ++total;
                }
            }
        }
        
        if (total > nums.size() / 2) {
            res = target;
        }
        
        return res;  
    }
};
