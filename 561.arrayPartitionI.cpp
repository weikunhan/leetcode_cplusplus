//==============================================================================
// 561. Array Partition I
// C++
// Tag: Array
//==============================================================================
// Summary:
// In short, the sum of all number is fixed. To maximize the sum of smaller group, 
// you want to minimize the diff of the sum of 2 groups. And the best way to do 
// that is to pair the numbers that are next to each other in sorted order.

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2)
            res += nums[i];
        return res;
    }
};
1
