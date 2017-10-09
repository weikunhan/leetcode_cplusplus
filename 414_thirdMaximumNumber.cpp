//==============================================================================
// 414. Third Maximum Number
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/third-maximum-number/description/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;
        int res = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == first || nums[i] == second || nums[i] == third) {
                continue;
            }
            if (first < nums[i]) {
                third = second;
                second = first;
                first = nums[i];
            } else if (second < nums[i]) {
                third = second;
                second = nums[i];
            } else if (third < nums[i]) {
                third = nums[i];    
            }
        }
        
        return res = (third == LLONG_MIN) ? first:third;
    }
};
