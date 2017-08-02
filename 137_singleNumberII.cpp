//==============================================================================
// 137. Single Number II
// C++
// Tag: Bit Manipulation
//==============================================================================
// Summary:
// https://leetcode.com/problems/single-number-ii/description/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int firstState = 0;
        int secondState = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            firstState = (firstState ^ nums[i]) & ~secondState;
            secondState = (secondState ^ nums[i]) & ~firstState;
        }
        
        return res = firstState;
    }
};
