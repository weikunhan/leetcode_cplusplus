//==============================================================================
// 136. Single Number
// C++
// Tag: Bit Manipulation, without Hash Table
//==============================================================================
// Summary:
// https://leetcode.com/problems/single-number/description/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int firstState = 0; 
        
        for (int i = 0; i < nums.size(); ++i) {
	    firstState = firstState ^ nums[i];
        }
       
	return res = firstState;
    }
};
