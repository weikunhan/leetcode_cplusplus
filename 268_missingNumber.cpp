//==============================================================================
// 268. Missing Number
// C++
// Tag: Array, Math, Bit Manipulation
//==============================================================================
// Summary:
// https://leetcode.com/problems/missing-number/description/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        int number = 0;
        
        for (int i = 0; i < nums.size(); ++i){
            res ^= nums[i];
            res ^= number;
            ++number;
        }
        
        return res;
    }
};
