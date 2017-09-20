//==============================================================================
// 260. Single Number III
// C++
// Tag: Bit Manipulation
//==============================================================================
// Summary:
// https://leetcode.com/problems/single-number-iii/description/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2, 0);
        int difference = 0;

        for (int i = 0; i < nums.size(); ++i) {
            difference ^= nums[i];
        }
        
        difference &= ~(difference - 1);
       
        for (int i = 0; i < nums.size(); ++i) {
            if ((nums[i] & difference) == 0) {
                res[0] ^= nums[i];
            } else {
                res[1] ^= nums[i];
            }
        }
        
        return res;
    }
};
